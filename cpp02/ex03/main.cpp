/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:26:05 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/09 17:33:03 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"


// int main() {
//     Point A(0.0f, 0.0f);
//     Point B(5.0f, 0.0f);
//     Point C(0.0f, 5.0f);

//     Point P_inside(2.0f, 2.0f);
//     Point P_outside(6.0f, 6.0f);
//     Point P_on_edge(2.5f, 0.0f);

//     std::cout << "P_inside is " << (bsp(A, B, C, P_inside) ? "inside ✅" : "outside ❌") << std::endl;
//     std::cout << "P_outside is " << (bsp(A, B, C, P_outside) ? "inside ❌" : "outside ✅") << std::endl;
//     std::cout << "P_on_edge is " << (bsp(A, B, C, P_on_edge) ? "inside or on edge ⚠️" : "outside ❌") << std::endl;

//     return 0;
// }


int main() {
    Point A(0.0f, 0.0f);
    Point B(10.0f, 0.0f);
    Point C(0.0f, 10.0f);

    Point P_inside(4.0f, 4.0f);
    Point P_outside(12.0f, 12.0f);
    Point P_on_edge(5.0f, 0.0f);

    std::cout << "P_inside is " << (bsp(A, B, C, P_inside) ? "inside  🚀 " : "outside ❌") << std::endl;
    std::cout << "P_outside is " << (bsp(A, B, C, P_outside) ? "inside ❌" : "outside  🚀 ") << std::endl;
    std::cout << "P_on_edge is " << (bsp(A, B, C, P_on_edge) ? "inside or on edge  🚀 " : "outside ❌") << std::endl;

    return 0;
}