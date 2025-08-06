/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 21:02:19 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/06 23:44:46 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{    
    float total = area(a, b, c);
    float area1 = area(a, b, point);
    float area2 = area(a, c, point);
    float area3 = area(b, c, point);
    
    float sum = area1 + area2 + area3 ;
    
    return std::abs(total - sum) < 1e-6;
}