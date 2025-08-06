/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 22:30:19 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/06 23:37:08 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point::~Point() {}

Point::Point(const float x , const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point& Point::operator=(const Point& other)
{
    (void)other;
    return *this;
};

Fixed const Point::getX() const { return _x; }
Fixed const Point::getY() const { return _y; }



float area(Point const a, Point const b, Point const c)
{
    float ax = a.getX().toFloat();
    float ay = a.getY().toFloat();
    float bx = b.getX().toFloat();
    float by = b.getY().toFloat();
    float cx = c.getX().toFloat();
    float cy = c.getY().toFloat();
    float result = 0.5f * std::abs(
        ax * (by - cy) + 
        bx * (cy - ay) + 
        cx * (ay - by));
    return result;
}

