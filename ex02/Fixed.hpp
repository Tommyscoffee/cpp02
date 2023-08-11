#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	private:
		int					_value;
		static const int	_fractional_bits = 8;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &obj);//constの参照を受け取るコンストラクタはコピーコンストラクタ、作動時：「関数にオブジェクトを渡すとき」「関数からオブジェクトを受け取るとき」
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat(void)const;
		int toInt(void)const;
		Fixed& operator = (const Fixed &obj);

		bool operator > (const Fixed &obj)const;
		bool operator < (const Fixed &obj)const;
		bool operator >= (const Fixed &obj)const;
		bool operator <= (const Fixed &obj)const;
		bool operator == (const Fixed &obj)const;
		bool operator != (const Fixed &obj)const;

		Fixed	operator + (const Fixed &obj)const;
		Fixed	operator - (const Fixed &obj)const;
		Fixed	operator * (const Fixed &obj)const;
		Fixed	operator / (const Fixed &obj)const;

		Fixed&	operator ++();//前置だと参照でいい
		const 	Fixed operator ++(int num);
		Fixed&	operator --();
		const	Fixed operator --(int num);


		static const	Fixed& min (const Fixed &obj1, const Fixed &obj2);
		static 			Fixed& min (Fixed &obj1, Fixed &obj2);
		static const 	Fixed& max (const Fixed &obj1, const Fixed &obj2);
		static 			Fixed& max ( Fixed &obj1, Fixed &obj2);
};

std::ostream& operator<<(std::ostream&, const Fixed& obj);

#endif
