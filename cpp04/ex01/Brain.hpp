/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 20:48:04 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/12 21:27:13 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP


#include <string>
#include <iostream>


class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain( void );
        Brain(const Brain &other);
        Brain& operator=(const Brain &other);
        ~Brain( void );
};

#endif