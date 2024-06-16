#include "loadbalancer.h"
#include <iostream>

int main() {
    int numServers;
    int simulationTime;

    std::cout << "Enter number of servers: ";
    std::cin >> numServers;

    std::cout << "Enter simulation time (clock cycles): ";
    std::cin >> simulationTime;

    LoadBalancer loadBalancer(numServers);
    loadBalancer.simulate(simulationTime);

    return 0;
}