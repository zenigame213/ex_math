#ifndef INEURAL_NETWORK_HPP
#define INEURAL_NETWORK_HPP

#include <string>
#include <vector>

class INN_Framework
{
public:
    virtual ~INN_Framework() = default;
    virtual bool initNNFramework(const std::string &config) = 0;
    virtual bool detect(const std::vector<float> &features) = 0;
};

#endif
