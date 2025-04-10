/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:15:32 by tkwak             #+#    #+#             */
/*   Updated: 2024/07/26 09:15:35 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

/*  [F]
    [ Orthodox Canonical Form ]
    1. Default constructor
    2. Destructor
    3. Copy constructor
    4. Overloaded assignment operator

    [ Member function ]
    1. getIdea
    2. setIdea
*/
class Brain
{
    private:
        std::string ideas[100];

    public:
        Brain();
        virtual ~Brain();
        Brain(const Brain &rhs);
        Brain& operator=(const Brain &rhs);

        std::string getIdea(int n) const;
        void setIdea(std::string idea, int n);
};

#endif
