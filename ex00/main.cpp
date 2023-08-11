#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;// a = b = cだと、機能しない。理由）右から評価されるので、(b = c)の返り値がvoidになってしまって、a = bでbがvoid型になってしまい、オーバーロードが効かなくなる。ほとんどの演算子のオーバーロードは同じクラスの参照を返す。
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return (0);
}
