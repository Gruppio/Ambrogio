/**
 * This sample demonstrates a simple driver  built against the Alexa Lighting Api.
 * For additional details, please refer to the Alexa Lighting API developer documentation 
 * https://developer.amazon.com/public/binaries/content/assets/html/alexa-lighting-api.html
 */
 
 
var https = require('https');
var querystring = require('querystring');
var REMOTE_CLOUD_BASE_PATH = '/v1/devices/1a002b000447343337373737/execute';
var REMOTE_CLOUD_HOSTNAME = 'api.particle.io';
var PARTICLE_ACCESS_TOKEN = process.env.PARTICLE_ACCESS_TOKEN;

/**
 * Main entry point.
 * Incoming events from Alexa Lighting APIs are processed via this method.
 */
exports.handler = function(event, context) {

    console.log("Request Received");
    console.log(event.header.namespace + " - " + event.header.name + " - " + event.payload.switchControlAction);

    switch (event.header.namespace) {
        
        /**
         * The namespace of "Discovery" indicates a request is being made to the lambda for
         * discovering all appliances associated with the customer's appliance cloud account.
         * can use the accessToken that is made available as part of the payload to determine
         * the customer.
         */
        case 'Alexa.ConnectedHome.Discovery':
            handleDiscovery(event, context);
            break;

            /**
             * The namespace of "Control" indicates a request is being made to us to turn a
             * given device on, off or brighten. This message comes with the "appliance"
             * parameter which indicates the appliance that needs to be acted on.
             */
        case 'Alexa.ConnectedHome.Control':
            handleControl(event, context);
            break;

            /**
             * We received an unexpected message
             */
        default:
            log('Err', 'No supported namespace: ' + event.header.namespace);
            context.fail('Something went wrong');
            break;
    }
};

/**
 * This method is invoked when we receive a "Discovery" message from Alexa Smart Home Skill.
 * We are expected to respond back with a list of appliances that we have discovered for a given
 * customer. 
 */
function handleDiscovery(accessToken, context) {

    /**
     * Crafting the response header
     */
    var headers = {
        namespace: 'Alexa.ConnectedHome.Discovery',
        name: 'DiscoverAppliancesResponse',
        payloadVersion: '1'
    };

    /**
     * Response body will be an array of discovered devices.
     */
    var appliances = [];

    var applianceDiscovered = {
        applianceId: 'LedPanel',
        manufacturerName: 'Gruppio',
        modelName: 'Pannellone a Leddoni',
        version: '1.0',
        friendlyName: 'Led Panel',
        friendlyDescription: 'The led panel upon the table',
        isReachable: true,
        actions: [
            "turnOn",
            "turnOff"
        ],
        additionalApplianceDetails: {
            /**
             * OPTIONAL:
             * We can use this to persist any appliance specific metadata.
             * This information will be returned back to the driver when user requests
             * action on this appliance.
             */
            //'fullApplianceId': '2cd6b650-c0h0-4062-b31d-7ec2c146c5ea'
        }
    };
    appliances.push(applianceDiscovered);

    var payloads = {
        discoveredAppliances: appliances
    };
    var result = {
        header: headers,
        payload: payloads
    };

    console.log('Discovery Result' + result);

    context.succeed(result);
}

/**
 * Control events are processed here.
 * This is called when Alexa requests an action (IE turn off appliance).
 */
function handleControl(event, context) {

    /**
     * Fail the invocation if the header is unexpected. This example only demonstrates
     * turn on / turn off, hence we are filtering on anything that is not SwitchOnOffRequest.
     */
    if (event.header.namespace != 'Alexa.ConnectedHome.Control') { 
        context.fail(generateControlError('SwitchOnOffRequest', 'UNSUPPORTED_OPERATION', 'Unrecognized operation'));
    }
    
    if (event.header.name != 'TurnOnRequest' && event.header.name != 'TurnOffRequest') {
        context.fail(generateControlError('SwitchOnOffRequest', 'UNSUPPORTED_OPERATION', 'Unrecognized operation'));
    }

    var applianceId = event.payload.appliance.applianceId;
    var accessToken = event.payload.accessToken.trim();
    console.log("applianceId:" + applianceId);

    if (event.header.name == 'TurnOnRequest') {
        executeCommand('LedPanelOn', event, context);
    } else if (event.header.name == 'TurnOffRequest') {
        executeCommand('LedPanelOff', event, context);
    }
}

/**
 * Utility functions.
 */
 function executeCommand(command, event, context) {
    var postData = querystring.stringify({
        arg: command,
        access_token: PARTICLE_ACCESS_TOKEN
    });
             
    var options = {
        host: REMOTE_CLOUD_HOSTNAME,
        port: 443,
        method: 'POST',
        path: REMOTE_CLOUD_BASE_PATH,
        headers: {
            'Content-Type': 'application/x-www-form-urlencoded',
            'Content-Length': postData.length
        }
    };

    var callback = function(response) {
        var str = '';

        response.on('data', function(chunk) {
            str += chunk.toString('utf-8');
        });

        response.on('end', function() {
            var headers = {
                namespace: event.header.namespace,
                name: event.header.name,
                payloadVersion: '1'
            };
            var payloads = {
                success: true
            };
            var result = {
                header: headers,
                payload: payloads
            };
            log('Particle Response:', str);
            context.succeed(result);
        });

        response.on('error', function() {
            log('Error', e.message);
            context.fail(generateControlError(event.header.name, 'DEPENDENT_SERVICE_UNAVAILABLE', 'Unable to connect to server'));
        });
    };


    console.log("Sending the request");
    var req = https.request(options, callback);
    req.write(postData);
    req.end();
}
 
function log(title, msg) {
    console.log(title + ": " + msg);
}

function generateControlError(name, code, description) {
    var headers = {
        namespace: 'Alexa.ConnectedHome.Control',
        name: name,
        payloadVersion: '1'
    };

    var payload = {
        exception: {
            code: code,
            description: description
        }
    };

    var result = {
        header: headers,
        payload: payload
    };

    return result;
}