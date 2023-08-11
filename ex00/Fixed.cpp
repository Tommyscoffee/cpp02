#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	// this->_value = obj.getRawBits();
	*this = obj;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

Fixed&	Fixed::operator=(const Fixed &obj)// 同じインスタンスが代入された場合のエラー処理を追加する。これだと、一回しか代入できない。 a = b = c;右から演算されるから、b = cの返り値がvoidになるから。
{
	std::cout << "Copy assignation operator called" << std::endl;

	this->_value = obj.getRawBits();
	return (*this);
}
