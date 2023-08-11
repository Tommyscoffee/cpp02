#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
    Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed c( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << "  a = " << a << std::endl;
    std::cout << "++a = " << ++a << std::endl;
    std::cout << "  a = " << a << std::endl;
    std::cout << "a++ = " << a++ << std::endl;
    std::cout << "  a = " << a << std::endl << std::endl;
    std::cout << "  b = " << b << std::endl << std::endl;

    std::cout << b << std::endl << std::endl;

    std::cout << "a < b = " << (a < b) << std::endl;
    std::cout << "a > b = " << (a > b) << std::endl;
    std::cout << "a <= b = " << (a <= b) << std::endl;
    std::cout << "a >= b = " << (a >= b) << std::endl;
    std::cout << "a == b = " << (a == b) << std::endl;
    std::cout << "a != b = " << (a != b) << std::endl << std::endl;

    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "a / b = " << (a / b) << std::endl << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << Fixed::max( a, c ) << std::endl;
    std::cout << Fixed::min( a, b ) << std::endl;
    std::cout << Fixed::min( a, c ) << std::endl;

	return 0;
}