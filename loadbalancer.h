#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "webserver.h"
#include <queue>
#include <vector>
#include <random>

class LoadBalancer {
private:
    std::vector<WebServer> servers;
    std::queue<Request> requestQueue;
    int clock;

public:
    LoadBalancer(int numServers);
    void simulate(int maxClock);
    void addRequest(const Request& request);
    void updateServers();
    void printStatus();
};

#endif // LOADBALANCER_H
