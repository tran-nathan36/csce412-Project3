/**
 * @file main.cpp
 * @brief Main function to simulate load balancing with user-defined parameters.
 */

#include "loadbalancer.h"
#include <iostream>

/**
 * @brief Main function to simulate load balancing with user-defined parameters.
 * @return Exit status of the program.
 */
int main() {
    int numServers;
    int simTime;

    // Prompt user to enter number of servers
    std::cout << "Enter number of servers: ";
    std::cin >> numServers;

    // Prompt user to enter simulation time
    std::cout << "Enter simulation time (clock cycles): ";
    std::cin >> simTime;

    // Create a LoadBalancer object with user-defined number of servers
    LoadBalancer loadBalancer(numServers);

    // Simulate load balancing for the specified simulation time
    loadBalancer.simulate(simTime);

    return 0;
}
