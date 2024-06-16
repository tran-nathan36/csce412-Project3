#include "loadbalancer.h"
#include <iostream> // for cout
#include <cstdlib>  // for rand()

LoadBalancer::LoadBalancer(int numServers) : servers(numServers, WebServer(0)), clock(0) {
    for (int i = 0; i < numServers; ++i) {
        servers[i] = WebServer(i + 1);
    }
}

void LoadBalancer::simulate(int maxClock) {
    // Print initial size of the request queue
    std::cout << "Initial size of the request queue: " << requestQueue.size() << std::endl;

    while (clock < maxClock) {
        // Generate random requests (simulation)
        std::string ipIn = "192.168.1." + std::to_string(rand() % 256);
        std::string ipOut = "10.0.0." + std::to_string(rand() % 256);
        int time = rand() % 10 + 1; // Random processing time

        Request newRequest(ipIn, ipOut, time);
        std::cout << "Request from " << ipIn << " to " << ipOut << " generated at simulation time " << clock 
                  << " with processing time " << time << std::endl;
        addRequest(newRequest);

        updateServers();

        // Increment clock
        ++clock;
    }
    printStatus();
}

void LoadBalancer::addRequest(const Request& request) {
    std::cout << "Adding request from " << request.ipIn << " to server queue" << std::endl;
    requestQueue.push(request);
}

void LoadBalancer::updateServers() {
    for (auto& server : servers) {
        if (!requestQueue.empty() && !server.isBusy()) {
            Request request = requestQueue.front();
            requestQueue.pop();
            std::cout << "Assigning request from " << request.ipIn << " to " << request.ipOut
                      << " to Server " << server.getId() << std::endl;
            server.processRequest(request);
        }
        server.update();
    }
}

void LoadBalancer::printStatus() {
    std::cout << "Load Balancer Simulation Results:" << std::endl;
    std::cout << "Simulation Clock: " << clock << std::endl;

    // Print status of each server
    for (const auto& server : servers) {
        std::cout << "Server " << server.getId() << ": ";
        if (server.isBusy()) {
            std::cout << "Busy" << std::endl;
        } else {
            std::cout << "Idle" << std::endl;
        }
    }

    // Print requests in queue
    std::cout << "Requests in Queue: " << requestQueue.size() << std::endl;

    std::cout << std::endl; // Optional: Add an empty line for better readability
}
