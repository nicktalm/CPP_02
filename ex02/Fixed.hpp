/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:17:16 by ntalmon           #+#    #+#             */
/*   Updated: 2024/08/05 15:51:31 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int value;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed & src);
		~Fixed();
		
		Fixed & operator=(const Fixed & src);
		bool operator>(const Fixed & src);
		bool operator<(const Fixed & src);
		bool operator>=(const Fixed & src);
		bool operator<=(const Fixed & src);
		bool operator==(const Fixed & src);
		bool operator!=(const Fixed & src);

		Fixed operator+(const Fixed & src);
		Fixed operator-(const Fixed & src);
		Fixed operator*(const Fixed & src);
		Fixed operator/(const Fixed & src);
		
		Fixed & operator++(void);
		Fixed operator++(int);
		Fixed & operator--(void);
		Fixed operator--(int);
		
		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);

		static Fixed & min(Fixed & a, Fixed & b);
		static Fixed & max(Fixed & a, Fixed & b);
		static const Fixed & min(const Fixed & a, const Fixed & b);
		static const Fixed & max(const Fixed & a, const Fixed & b);
};

std::ostream & operator<<(std::ostream & o, Fixed const & src);

#endif