/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:53:02 by sngantch          #+#    #+#             */
/*   Updated: 2025/07/31 17:03:39 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

    public:
        Harl(void);
        ~Harl(void);
        void complain(std::string level);
};

enum Level
{
    DEBUG_LVL,
    INFO_LVL,
    WARNING_LVL,
    ERROR_LVL,
    INVALID_LVL
};

#endif