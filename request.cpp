#include "request.h"

/**
 * @brief Constructor for Request struct.
 * @param ipIn Source IP address of the request.
 * @param ipOut Destination IP address of the request.
 * @param time Processing time required for the request.
 */
Request::Request(const std::string& ipIn, const std::string& ipOut, int time)
    : ipIn(ipIn), ipOut(ipOut), time(time) {
    // Constructor implementation
}
