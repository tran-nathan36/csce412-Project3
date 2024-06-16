#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "request.h" // Include the Request class definition
#include <queue>     // For std::queue

/**
 * @class WebServer
 * @brief Represents a web server that processes requests.
 */
class WebServer {
private:
    int id;               ///< Unique identifier of the server.
    int busyTime;         ///< Time remaining to process the current request.
    bool wasBusy;         ///< Flag to check if the server was previously busy.
    std::queue<Request> requestsQueue; ///< Queue of requests waiting to be processed.

public:
    /**
     * @brief Constructor for WebServer class.
     * @param id Unique identifier of the server.
     */
    WebServer(int id);

    /**
     * @brief Retrieves the unique identifier of the server.
     * @return The identifier of the server.
     */
    int getId() const;

    /**
     * @brief Processes a request by setting the busy time and marking server as busy.
     * @param request The request to be processed.
     */
    void processRequest(Request request);

    /**
     * @brief Checks if the server is currently busy processing a request.
     * @return True if the server is busy, otherwise false.
     */
    bool isBusy() const;

    /**
     * @brief Updates the server's status after processing a time unit.
     *        Decreases the busy time if the server is busy.
     */
    void update();

    /**
     * @brief Adds a request to the server's queue.
     * @param request The request to be added to the queue.
     */
    void enqueueRequest(const Request& request);
};

#endif // WEBSERVER_H
