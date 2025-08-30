/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:53:20 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/19 11:38:58 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "Default constructor called for MateriaSource" << std::endl;
    _nbMaterias = 0;
    for (int i = 0; i < 4; i++)
    {
        _learnedMaterias[i] = NULL;
    }
}

MateriaSource::~MateriaSource()
{
    std::cout << "Destructor called for MateriaSource" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_learnedMaterias[i])
            delete _learnedMaterias[i];
    }
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
    std::cout << "Copy constructor called for MateriaSource" << std::endl;
    
    _nbMaterias = other._nbMaterias;
    for (int i = 0; i < 4; i++)
        _learnedMaterias[i] = NULL;
    for (int i = 0; i < 4; i++)
    {
        if (other._learnedMaterias[i])
            _learnedMaterias[i] = other._learnedMaterias[i]->clone();
    }
}

MateriaSource & MateriaSource::operator=(MateriaSource const & other)
{
    if (this ==  &other)
        return *this;
    
    for (int i = 0; i < 4; i++)
    {
        if (_learnedMaterias[i])
        {
            delete _learnedMaterias[i];
            _learnedMaterias[i] = NULL;
        }
    }
    _nbMaterias = other._nbMaterias;
    for (int i = 0; i < 4; i++)
    {
        if (other._learnedMaterias[i])
            _learnedMaterias[i] = other._learnedMaterias[i]->clone();
    }
    
    return *this;
}


void MateriaSource::learnMateria(AMateria* m)
{
    if (_nbMaterias >= 4  || !m)
    {
        std::cout << "MateriaSource can't learn more materias or materia is NULL" << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!_learnedMaterias[i])
        {
            _learnedMaterias[i] = m;
            _nbMaterias++;
            return;
        }
    }
}

AMateria * MateriaSource::createMateria(std::string const & type)
{
    if (_nbMaterias == 0)
        return NULL;    
    for (int i = 0; i < 4; i++)
    {
        if (_learnedMaterias[i] && _learnedMaterias[i]->getType() == type)
            return _learnedMaterias[i]->clone();
    }
    return NULL;
}

