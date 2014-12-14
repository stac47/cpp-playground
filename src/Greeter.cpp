#include <string>

#include "Greeter.h"

using namespace std;

Greeter::Greeter(const Greeter& other): 
    _name(other._name),
    _copyConstruct(other._copyConstruct + 1),
    _copyOperator(other._copyOperator) {}

Greeter& Greeter::operator=(const Greeter& other) {
    if (this == &other) {
        return *this;
    }
    _name = other._name;
    _copyConstruct = other._copyConstruct;
    _copyOperator = other._copyOperator + 1;
    return *this;
}

Greeter::~Greeter() {}

string Greeter::sayHello() const {
    return "Hello, " + _name + " !";
}
