///////////////////////////////////////////////////////////////////////////
// Precompilled headers
///////////////////////////////////////////////////////////////////////////
#include <pch.hpp>

///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#include <xrn/Util.hpp>

///////////////////////////////////////////////////////////////////////////
auto main()
    -> int
{
    ::std::cout << ::std::boolalpha;
    // (string) a <- "bonjour"
    // (int)    a <- 1
    int numberInt{ 3 }; // int == integer == nombre
    char numberChar{ '3' }; // char == character == lettre
    ::std::string numberStr{ "3" }; // string == chaine de character
    ::std::cout << numberInt << ::std::endl;
    ::std::cout << numberChar << ::std::endl;
    ::std::cout << numberStr << ::std::endl;
    ::std::cout << int{ '+' } << ::std::endl;

    if (numberInt == 3) {
        ::std::cout << "true" << ::std::endl;
    } else {
        ::std::cout << "false" << ::std::endl;
    }

    for (int i{ 0 }; i < numberInt; ++i) {
        ::std::cout << "hello " << i << ::std::endl;
    }

    int i{ 0 };
    while (i < numberInt) {
        ::std::cout << "hello " << i << ::std::endl;
        ++i;
    }
}
