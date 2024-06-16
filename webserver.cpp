#include "webserver.h"
#include <iostream> // For std::cout

/**
 * @brief Constructor for WebServer class.
 * @param id Unique identifier of the server.
 */
WebServer::WebServer(int id) : id(id), busyTime(0), wasBusy(false) {
    // Constructor implementation
}

/**
 * @brief Retrieves the unique identifier of the server.
 * @return The identifier of the server.
 */
int WebServer::getId() const {
    return id;
}

/**
 * @brief Processes a request by setting the busy time and marking server as busy.
 * @param request The request to be processed.
 */
void WebServer::processRequest(Request request) {
    std::cout << "Server " << id << " is processing request from " << request.ipIn
              << " to " << request.ipOut << " for " << request.time << " seconds" << std::endl;
    busyTime = request.time;
    wasBusy = true;
}

/**
 * @brief Checks if the server is currently busy processing a request.
 * @return True if the server is busy, otherwise false.
 */
bool WebServer::isBusy() const {
    return busyTime > 0;
}

/**
 * @brief Updates the server's status after processing a time unit.
 *        Decreases the busy time if the server is busy.
 *        If no request is currently being processed and there are pending requests,
 *        processes the next request from the queue.
 */
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

/**
 * @brief Adds a request to the server's queue.
 * @param request The request to be added to the queue.
 */
void WebServer::enqueueRequest(const Request& request) {
    requestsQueue.push(request);
}
