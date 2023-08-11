#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	this->_value = num << this->_fractional_bits;
}

Fixed::Fixed(const float num) 
{
	this->_value = roundf(num * (1 << this->_fractional_bits));
	// std::cout << "float value = " << this->_value << std::endl;
}

float Fixed::toFloat(void) const
{
	return (float)this->_value / (1 << _fractional_bits);
}

int Fixed::toInt(void) const
{
	return (this->_value >> this->_fractional_bits);
}

Fixed::Fixed(const Fixed &obj)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->_value = obj.getRawBits();
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

std::ostream& operator<<(std::ostream& stream, const Fixed&obj)
{
	stream << obj.toFloat();
	return stream;
}

const Fixed& Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
	if (obj1.getRawBits() > obj2.getRawBits())
		return obj2;
	return obj1;
}

Fixed& Fixed::min(Fixed &obj1, Fixed &obj2)
{
	if (obj1.getRawBits() > obj2.getRawBits())
		return obj2;
	return obj1;
}

const Fixed& Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
	if (obj1.getRawBits() < obj2.getRawBits())
		return obj2;
	return obj1;
}

Fixed& Fixed::max(Fixed &obj1, Fixed &obj2)
{
	if (obj1.getRawBits() < obj2.getRawBits())
		return obj2;
	return obj1;
}

Fixed&	Fixed::operator=(const Fixed &obj)// 同じインスタンスが代入された場合のエラー処理を追加する。これだと、一回しか代入できない。 a = b = c;右から演算されるから、b = cの返り値がvoidになるから。
{
	std::cout << "Assignation operator called" << std::endl;
	this->_value = obj.getRawBits();
	return (*this);
}

bool Fixed::operator > (const Fixed &obj)
{
	return (this->_value > obj.getRawBits());
}

bool Fixed::operator < (const Fixed &obj)
{
	return (this->_value < obj.getRawBits());
}
bool Fixed::operator >= (const Fixed &obj)
{
	return (this->_value >= obj.getRawBits());
}
bool Fixed::operator <= (const Fixed &obj)
{
	return (this->_value <= obj.getRawBits());
}

bool Fixed::operator == (const Fixed &obj)
{
	return (this->_value == obj.getRawBits());
}

bool Fixed::operator != (const Fixed &obj)
{
	return (this->_value != obj.getRawBits());
}

Fixed Fixed::operator + (const Fixed &obj)
{
	Fixed add_res;

	add_res.setRawBits(this->getRawBits() + obj.getRawBits());
	return (add_res);
}

Fixed Fixed::operator - (const Fixed &obj)
{
	Fixed sub_res;

	sub_res.setRawBits(this->getRawBits() - obj.getRawBits());
	return (sub_res);
}


Fixed Fixed::operator * (const Fixed &obj)
{
	Fixed mult_res;

	mult_res.setRawBits(this->toFloat() * obj.toFloat());
	return (mult_res);
}

Fixed Fixed::operator / (const Fixed &obj)
{
	return (this->toFloat() / obj.toFloat());//floatにして計算した方がいい？
}

Fixed& Fixed::operator ++ ()
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

const Fixed Fixed::operator ++ (int)
{
	Fixed	old_value(*this);

	this->setRawBits(this->getRawBits() + 1);
	return (old_value);
}

Fixed& Fixed::operator -- ()
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

const Fixed Fixed::operator -- (int)
{
	Fixed old_value(*this);

	this->setRawBits(this->getRawBits() + 1);
	return (old_value);
}
