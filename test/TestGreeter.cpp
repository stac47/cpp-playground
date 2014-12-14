#include <boost/test/auto_unit_test.hpp>

#include "Greeter.h"

BOOST_AUTO_TEST_SUITE(greeter_test_suite)

BOOST_AUTO_TEST_CASE(constructor) {
    Greeter greeter;
    BOOST_CHECK(greeter.copyConstruct() == 0);
    BOOST_CHECK(greeter.copyOperator() == 0);
    BOOST_CHECK(greeter.sayHello() == "Hello, God !");
}

BOOST_AUTO_TEST_CASE(copy_constructor) {
    Greeter greeter;
    GreeterContainer c(greeter);
    BOOST_CHECK(c.get().copyConstruct() == 1);
    BOOST_CHECK(c.get().copyOperator() == 0);
}

BOOST_AUTO_TEST_CASE(copy_operator) {
    Greeter greeter1;
    Greeter greeter2;
    greeter2 = greeter1;
    BOOST_CHECK(greeter2.copyConstruct() == 0);
    BOOST_CHECK(greeter2.copyOperator() == 1);
}
BOOST_AUTO_TEST_SUITE_END()
