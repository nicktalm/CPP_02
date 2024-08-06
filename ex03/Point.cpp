/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:32:40 by ntalmon           #+#    #+#             */
/*   Updated: 2024/08/06 15:26:03 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point::Point(const Point & src) : x(src.x), y(src.y)
{
}

Point::~Point()
{
}

Point & Point::operator=(const Point & src)
{
	return (*this);
}

float Point::getX(void) const
{
	return (this->x.toFloat());
}

float Point::getY(void) const
{
	return (this->y.toFloat());
}
