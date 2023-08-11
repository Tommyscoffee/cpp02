#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{
	private:
		int					_value;
		static const int	_franctional_bit = 8;
	public:
		Fixed();
		Fixed(const Fixed &obj);//constの参照を受け取るコンストラクタはコピーコンストラクタ、作動時：「関数にオブジェクトを渡すとき」「関数からオブジェクトを受け取るとき」
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		Fixed& operator = (const Fixed &obj);
};

#endif
