//
//  HttpGetCommand.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 24/10/2017.
//  Copyright © 2017 Michele Gruppioni. All rights reserved.
//

#include "HttpGetCommand.h"

HttpGetCommand::HttpGetCommand(const char *hostname, const char *path, const char *description): Command(description) {
    this->hostname = hostname;
    this->path = path;
}

void HttpGetCommand::execute() {
    HttpClient http;
    http_request_t request;
    http_response_t response;
    http_header_t headers[] = {
        //  { "Content-Type", "application/json" },
        //  { "Accept" , "application/json" },
        { "Accept" , "*/*"},
        //{ "User-Agent" , "Particle"},
        { NULL, NULL } // NOTE: Always terminate headers will NULL
    };
    request.hostname = hostname;
    request.port = 80;
    request.path = path;
    http.get(request, response, headers);

    //Particle.publish("command", String::format("%d", response.status) + response.body, PRIVATE);
}
