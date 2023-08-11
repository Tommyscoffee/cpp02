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
		Fixed& operator = (const Fixed &obj);
		float toFloat(void)const;
		int toInt(void)const;
};
std::ostream& operator<<(std::ostream&, const Fixed& obj);

#endif
