/**
 * @file loadbalancer.h
 * @brief Defines the LoadBalancer class used to simulate load balancing among multiple web servers.
 */

#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "webserver.h" // Include the WebServer class definition
#include <queue>       // For std::queue
#include <vector>      // For std::vector
#include <random>      // For std::random_device and std::mt19937

/**
 * @class LoadBalancer
 * @brief Simulates a load balancer that distributes requests among multiple servers.
 */
class LoadBalancer {
private:
    std::vector<WebServer> servers; ///< Vector of WebServer instances representing servers in the load balancer.
    std::queue<Request> requestQueue; ///< Queue of Request instances representing incoming requests.
    int clock; ///< Simulation clock representing the current time.

public:
    /**
     * @brief Constructor for LoadBalancer class.
     * @param numServers Number of servers to initialize in the load balancer.
     */
    LoadBalancer(int numServers);

    /**
     * @brief Simulates the load balancing process for a specified number of clock cycles.
     * @param maxClock Maximum number of clock cycles to simulate.
     */
    void simulate(int maxClock);

    /**
     * @brief Adds a new request to the request queue.
     * @param request The request to add to the queue.
     */
    void addRequest(const Request& request);

    /**
     * @brief Updates the status of each server and assigns requests if servers are available.
     */
    void updateServers();

    /**
     * @brief Prints the current status of the load balancer simulation.
     */
    void printStatus();
};

#endif // LOADBALANCER_H
