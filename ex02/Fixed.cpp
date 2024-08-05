/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:17:27 by ntalmon           #+#    #+#             */
/*   Updated: 2024/08/05 16:48:03 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Constructor

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	if (value <= (1 << 23) && value >= -(1 << 23))
		this->value = (value * int(1 << fractionalBits));
	else
	{
		std::cerr << "Value is too big" << std::endl;
		std::exit(1);
	}
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	if (value <= (3.402823466e+38F / float(1 << fractionalBits)) && value >= (-3.402823466e+38F / float(1 << fractionalBits)))
		this->value = roundf(value * (1 << fractionalBits));
	else
	{
		std::cerr << "Value is too big" << std::endl;
		std::exit(1);
	}
}

//Destructor

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//Operator overloads

std::ostream & operator<<(std::ostream & a, Fixed const & src)
{
	a << src.toFloat();
	return (a);
}

//comparison operators

Fixed & Fixed::operator=(const Fixed & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	value = src.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed & src)
{
	return (value > src.getRawBits());
}

bool Fixed::operator<(const Fixed & src)
{
	return (value < src.getRawBits());
}

bool Fixed::operator>=(const Fixed & src)
{
	return (value >= src.getRawBits());
}

bool Fixed::operator<=(const Fixed & src)
{
	return (value <= src.getRawBits());
}

bool Fixed::operator==(const Fixed & src)
{
	return (value == src.getRawBits());
}

bool Fixed::operator!=(const Fixed & src)
{
	return (value != src.getRawBits());
}

//arithmetic operators

Fixed Fixed::operator+(const Fixed & src)
{
	return (Fixed(toFloat() + src.toFloat()));
}

Fixed Fixed::operator-(const Fixed & src)
{
	return (Fixed(toFloat() - src.toFloat()));
}

Fixed Fixed::operator*(const Fixed & src)
{
	return (Fixed(toFloat() * src.toFloat()));
}

Fixed Fixed::operator/(const Fixed & src)
{
	if (this->toFloat() != 0 && src.toFloat() != 0)
	{
		Fixed tmp(this->toFloat() / src.toFloat());
		return (tmp);
	}
	else
		std::cerr << "Division by zero" << std::endl;
	return (src);
}

//increment and decrement operators

Fixed & Fixed::operator++(void)
{
	value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed & Fixed::operator--(void)
{
	value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

//member functions

int Fixed::getRawBits(void) const
{
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)value / (1 << fractionalBits));
}

int Fixed::toInt(void) const
{
	return (value >> fractionalBits);
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	return (a < b ? a : b);
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	return (a > b ? a : b);
}

const Fixed	&Fixed::min(const Fixed &s1, const Fixed &s2)
{
	return (s1.toFloat() < s2.toFloat() ? s1 : s2);
}

const Fixed	&Fixed::max(const Fixed &s1, const Fixed &s2)
{
	return (s1.toFloat() > s2.toFloat() ? s1 : s2);
}
