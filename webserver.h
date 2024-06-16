#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "request.h"
#include <queue>

class WebServer {
private:
    int id;
    int busyTime; // Time remaining to process the current request
    bool wasBusy; // Flag to check if the server was previously busy
    std::queue<Request> requestsQueue;

public:
    WebServer(int id);
    int getId() const;
    void processRequest(Request request);
    bool isBusy() const;
    void update();
    void enqueueRequest(const Request& request); // Add enqueueRequest method
};

#endif // WEBSERVER_H
