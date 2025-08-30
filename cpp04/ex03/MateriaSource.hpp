/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:53:28 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/19 12:10:45 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* _learnedMaterias[4];
        int _nbMaterias;
    public:
        MateriaSource();
        MateriaSource(MateriaSource const & other);
        ~MateriaSource();
        
        MateriaSource & operator=(MateriaSource const & other );
        
        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);
};

#endif