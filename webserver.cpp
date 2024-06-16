#include "webserver.h"
#include <iostream> // for cout

WebServer::WebServer(int id) : id(id), busyTime(0), wasBusy(false) {
    // Constructor implementation
}

int WebServer::getId() const {
    return id;
}

void WebServer::processRequest(Request request) {
    std::cout << "Server " << id << " is processing request from " << request.ipIn
              << " to " << request.ipOut << " for " << request.time << " seconds" << std::endl;
    busyTime = request.time;
    wasBusy = true;
}

bool WebServer::isBusy() const {
    return busyTime > 0;
}

void WebServer::update() {
    if (busyTime > 0) {
        --busyTime;
        if (busyTime == 0 && wasBusy) {
            std::cout << "Server " << id << " has completed its current request" << std::endl;
            wasBusy = false; // Reset the flag after logging completion
        }
    }

    if (!requestsQueue.empty() && busyTime == 0) {
        Request request = requestsQueue.front();
        requestsQueue.pop();
        processRequest(request);
    }
}

void WebServer::enqueueRequest(const Request& request) {
    requestsQueue.push(request);
}
