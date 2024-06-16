#ifndef REQUEST_H
#define REQUEST_H

#include <string>

struct Request {
    std::string ipIn;
    std::string ipOut;
    int time;

    Request(const std::string& ipIn, const std::string& ipOut, int time);
};

#endif // REQUEST_H
