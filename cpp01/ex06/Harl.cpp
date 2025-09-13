/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:55:07 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/02 15:05:30 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. \nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. \nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Level getLevel(std::string level)
{
    if(level == "DEBUG")
        return DEBUG_LVL;
    if (level ==  "INFO")
        return INFO_LVL;
    if (level == "WARNING")
        return WARNING_LVL;
    if (level == "ERROR")
        return ERROR_LVL;
    return INVALID_LVL;
}

void Harl::complain(std::string level)
{
    // Array of levels names
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    //Array of function pointeer
    void (Harl::*functions[4])(void) = {
        &Harl::debug, 
        &Harl::info, 
        &Harl::warning, 
        &Harl::error
    };

    Level levelCode = getLevel(level);

    switch (levelCode)
    {
        case DEBUG_LVL:
            (this->*functions[0])();
        case INFO_LVL:
            (this->*functions[1])();
        case WARNING_LVL:
            (this->*functions[2])();
        case ERROR_LVL:
            (this->*functions[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

