#include <string>
#include <iostream>

using namespace std;

class URL
{
public:
    explicit URL(std::string protocol_, std::string resource_) : m_protocol(protocol_), m_resource(resource_) {}

    void Display()
    {
        std::cout << m_protocol << "://" << m_resource << std::endl;
    }

private:
    std::string m_protocol;
    std::string m_resource;
};