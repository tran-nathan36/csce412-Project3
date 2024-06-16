/**
 * @file request.h
 * @brief Defines the Request struct used to represent a web request in the load balancer simulation.
 */

#ifndef REQUEST_H
#define REQUEST_H

#include <string>

/**
 * @struct Request
 * @brief Represents a request with source and destination IPs and processing time.
 */
struct Request {
    std::string ipIn;   ///< Source IP address of the request.
    std::string ipOut;  ///< Destination IP address of the request.
    int time;           ///< Processing time required for the request.

    /**
     * @brief Constructor for Request struct.
     * @param ipIn Source IP address of the request.
     * @param ipOut Destination IP address of the request.
     * @param time Processing time required for the request.
     */
    Request(const std::string& ipIn, const std::string& ipOut, int time);
};

#endif // REQUEST_H
