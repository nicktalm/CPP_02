/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:32:49 by ntalmon           #+#    #+#             */
/*   Updated: 2024/08/06 15:25:04 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point & src);
		~Point();
		
		Point & operator=(const Point & src);
		
		float getX(void) const;
		float getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
float	surface(Point a, Point b, Point c);

#endif