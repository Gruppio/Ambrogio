
var https = require('https');
var querystring = require('querystring');
const REMOTE_CLOUD_BASE_PATH = '/v1/devices/1a002b000447343337373737/execute';
const REMOTE_CLOUD_HOSTNAME = 'api.particle.io';
const PARTICLE_ACCESS_TOKEN = process.env.PARTICLE_ACCESS_TOKEN;

// namespaces
const NAMESPACE_CONTROL = "Alexa.ConnectedHome.Control";
const NAMESPACE_DISCOVERY = "Alexa.ConnectedHome.Discovery";

// discovery
const REQUEST_DISCOVER = "DiscoverAppliancesRequest";
const RESPONSE_DISCOVER = "DiscoverAppliancesResponse";

// control
const REQUEST_TURN_ON = "TurnOnRequest";
const RESPONSE_TURN_ON = "TurnOnConfirmation";
const REQUEST_TURN_OFF = "TurnOffRequest";
const RESPONSE_TURN_OFF = "TurnOffConfirmation";

// errors
const ERROR_UNSUPPORTED_OPERATION = "UnsupportedOperationError";
const ERROR_UNEXPECTED_INFO = "UnexpectedInformationReceivedError";

// entry
exports.handler = function (event, context, callback) {

  log("Received Directive", event);

  var requestedNamespace = event.header.namespace;
  var response = null;

  try {
    switch (requestedNamespace) {
      case NAMESPACE_DISCOVERY:
        response = handleDiscovery(event);
        break;

      case NAMESPACE_CONTROL:
        response = handleControl(event);
        break;

      default:
        log("Error", "Unsupported namespace: " + requestedNamespace);
        response = handleUnexpectedInfo(requestedNamespace);
        break;
    }
  } catch (error) {
    log("Error", error);
  }
  callback(null, response);
}


var handleDiscovery = function(event) {
    var appliances = [];

    var ledPanel = {
        applianceId: 'LedPanel',
        manufacturerName: 'Gruppio',
        modelName: 'LedPanel',
        version: '1.0',
        friendlyName: 'Led Panel',
        friendlyDescription: 'The led panel upon the table',
        isReachable: true,
        actions: [
            "turnOn",
            "turnOff"
        ],
        additionalApplianceDetails: {
        }
    };

    var livingRoomLamp = {
        applianceId: 'LivingRoomLamp',
        manufacturerName: 'Gruppio',
        modelName: 'LivingRoomLamp',
        version: '1.0',
        friendlyName: 'Living Room Lamp',
        friendlyDescription: 'The living room lamp',
        isReachable: true,
        actions: [
            "turnOn",
            "turnOff"
        ],
        additionalApplianceDetails: {
        }
    };

    var ledStripLeft = {
        applianceId: 'LedStripLeft',
        manufacturerName: 'Gruppio',
        modelName: 'LedStripLeft',
        version: '1.0',
        friendlyName: 'Led Strip Left',
        friendlyDescription: 'The Left Led Strip in the kitchen',
        isReachable: true,
        actions: [
            "turnOn",
            "turnOff"
        ],
        additionalApplianceDetails: {
        }
    };

    var ledStripRight = {
        applianceId: 'LedStripRight',
        manufacturerName: 'Gruppio',
        modelName: 'LedStripRight',
        version: '1.0',
        friendlyName: 'Led Strip Right',
        friendlyDescription: 'The Right Led Strip in the kitchen',
        isReachable: true,
        actions: [
            "turnOn",
            "turnOff"
        ],
        additionalApplianceDetails: {
        }
    };

    var coffeeMachine = {
        applianceId: 'CoffeeMachine',
        manufacturerName: 'Gruppio',
        modelName: 'CoffeeMachine',
        version: '1.0',
        friendlyName: 'Coffee Machine',
        friendlyDescription: 'The Coffee Machine in the kitchen',
        isReachable: true,
        actions: [
            "turnOn",
            "turnOff"
        ],
        additionalApplianceDetails: {
        }
    };

    var tv = {
        applianceId: 'Tv',
        manufacturerName: 'Gruppio',
        modelName: 'Tv',
        version: '1.0',
        friendlyName: 'Tv',
        friendlyDescription: 'The Tv in the living room',
        isReachable: true,
        actions: [
            "turnOn",
            "turnOff"
        ],
        additionalApplianceDetails: {
        }
    };

    var christmasTree = {
        applianceId: 'ChristmasTree',
        manufacturerName: 'Gruppio',
        modelName: 'ChristmasTree',
        version: '1.0',
        friendlyName: 'Christmas Tree',
        friendlyDescription: 'The Christmas Tree in the living room',
        isReachable: true,
        actions: [
            "turnOn",
            "turnOff"
        ],
        additionalApplianceDetails: {
        }
    };

    appliances.push(ledPanel);
    appliances.push(livingRoomLamp);
    appliances.push(ledStripLeft);
    appliances.push(ledStripRight);
    appliances.push(coffeeMachine);
    appliances.push(tv);
    appliances.push(christmasTree);

  var header = createHeader(NAMESPACE_DISCOVERY, RESPONSE_DISCOVER);
  var payload = {
    "discoveredAppliances": appliances
  };
  return createDirective(header,payload);
}

var handleControl = function(event) {
  var response = null;
  var requestedName = event.header.name;

  switch (requestedName) {
    case REQUEST_TURN_ON :
      response = handleControlTurnOn(event);
      break;

    case REQUEST_TURN_OFF :
      response = handleControlTurnOff(event);
      break;

    default:
      log("Error", "Unsupported operation" + requestedName);
      response = handleUnsupportedOperation();
      break;     
  }
  return response;
}


var handleControlTurnOn = function(event) {
  handleControlTurnOnOff(event, 'On');
  var header = createHeader(NAMESPACE_CONTROL,RESPONSE_TURN_ON);
  var payload = {};
  return createDirective(header,payload);
}

var handleControlTurnOff = function(event) {
  handleControlTurnOnOff(event, 'Off');
  var header = createHeader(NAMESPACE_CONTROL,RESPONSE_TURN_OFF);
  var payload = {};
  return createDirective(header,payload);
}

var handleControlTurnOnOff = function(event, controlType) {
  var applianceId = event.payload.appliance.applianceId;
  var accessToken = event.payload.accessToken.trim();
  var command = applianceId + controlType;
  log("Executing", command);
  executeCommand(command, function(response) {
    log("Command Response", response);
  }, function(failure) {
    log("Command Error", failure);
  });
}

 function executeCommand(command, onSuccess, onError) {
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
            onSuccess(str);
        });

        response.on('error', function() {
            onError(e.message);
            log('Error', e.message);
        });
    };

    var req = https.request(options, callback);
    req.write(postData);
    req.end();
}


var handleUnsupportedOperation = function() {
  var header = createHeader(NAMESPACE_CONTROL,ERROR_UNSUPPORTED_OPERATION);
  var payload = {};
  return createDirective(header,payload);
}

var handleUnexpectedInfo = function(fault) {
  var header = createHeader(NAMESPACE_CONTROL,ERROR_UNEXPECTED_INFO);
  var payload = {
    "faultingParameter" : fault
  };
  return createDirective(header,payload);
}

// support functions
var createMessageId = function() {
  var d = new Date().getTime();
  var uuid = 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function(c) {
    var r = (d + Math.random()*16)%16 | 0;
    d = Math.floor(d/16);
    return (c=='x' ? r : (r&0x3|0x8)).toString(16);
  });
  return uuid;
}

var createHeader = function(namespace, name) {
  return {
    "messageId": createMessageId(),
    "namespace": namespace,
    "name": name,
    "payloadVersion": "2"
  };
}

var createDirective = function(header, payload) {
  return {
    "header" : header,
    "payload" : payload
  };
}


var log = function(title, msg) {
  console.log('* ' + title + ': ' + JSON.stringify(msg));
}
