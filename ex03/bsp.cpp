/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:40:23 by ntalmon           #+#    #+#             */
/*   Updated: 2024/08/06 16:58:40 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float surface1;
	float surface2;
	float surface3;
	float surface4;

	surface1 = surface(a, b, c);
	surface2 = surface(a, b, point);
	surface3 = surface(b, c, point);
	surface4 = surface(c, a, point);
	if (!surface2 || !surface3 || !surface4 || surface2 + surface3 + surface4 != surface1)
		return (false);
	else
		return (true);

}

float	surface(Point a, Point b, Point c)
{
	float surface;

	surface = 0.5 * (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()));
	if (surface < 0)
		return (surface * -1);
	return (surface);
}
