/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:47:21 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/06 23:37:21 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POINT_HPP
# define POINT_HPP


#include "Fixed.hpp"
#include <cmath>

class Point
{
private:
    Fixed const _x;
    Fixed const _y;

public:
    Point();
    Point(const Point& other);
    Point& operator=(const Point& other);
    ~Point();
    Fixed const getX() const;
    Fixed const getY() const;
    Point(const float x , const float y); 
};


float area(Point const a, Point const b, Point const c);

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif