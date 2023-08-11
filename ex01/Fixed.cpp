#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = num << 8;
}

Fixed::Fixed(const float num) 
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = (int)roundf(num *(1 << _fractional_bits));

}

float Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << _fractional_bits));
}

int Fixed::toInt(void) const
{
	// return (this->_value >> _fractional_bits);
	return (this->_value / (1 << _fractional_bits));//マイナスの値を右シフトすると、歩数表
}

//x * -1 = ~x + 1
//  42 = 0 0101010 >> 1 => 21 = 0 0010101 >> 1 = 10 = 0 0001010                                        
// -42 = 1 1010110 >> 1 =>-21 = 1 1101011 >> 1 =-11 = 1 1110101 =-00001011 
//

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
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}


Fixed&	Fixed::operator=(const Fixed &obj)// 同じインスタンスが代入された場合のエラー処理を追加する。これだと、一回しか代入できない。 a = b = c;右から演算されるから、b = cの返り値がvoidになるから。
{
	std::cout << "Copy assignation operator called" << std::endl;

	this->_value = obj.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& stream, const Fixed&obj)
{
	stream << obj.toFloat();
	return stream;
}


void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}