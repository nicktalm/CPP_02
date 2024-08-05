/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:17:27 by ntalmon           #+#    #+#             */
/*   Updated: 2024/08/05 12:29:27 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	value = src.getRawBits();
	return (*this);
}

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

std::ostream & operator<<(std::ostream & a, Fixed const & src)
{
	a << src.toFloat();
	return (a);
}
