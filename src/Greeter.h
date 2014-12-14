#ifndef __GREETER_H__
#define __GREETER_H__ 

#include <string>

class Greeter {
    std::string _name;
    unsigned int _copyConstruct;
    unsigned int _copyOperator;
public:
    Greeter(std::string name="God") :
        _name(name), _copyConstruct(0), _copyOperator(0) {};
    Greeter(const Greeter&);
    Greeter& operator=(const Greeter&);
    ~Greeter();

    std::string sayHello() const;
    inline unsigned int copyConstruct() const {return _copyConstruct;}
    inline unsigned int copyOperator() const {return _copyOperator;}
};

class GreeterContainer {
    Greeter _greeter;
public:
    GreeterContainer(const Greeter& greeter): _greeter(greeter) {};
    inline Greeter const& get() const {return _greeter;}
};

#endif /* __GREETER_H__ */
