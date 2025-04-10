/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:37:31 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/28 14:37:32 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

#include <iostream>
#include <string>

/*  [F]
    [ Memo ]
    Function (debug, info, warning, error) can be only executable
    in 'complain' method, cuase it's in private. Can't execute directly.
*/
class   Harl
{
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
        
    public:
        Harl();                                 // Construtor.
        void harlFilter(std::string level);     // member function
        ~Harl();                                // Destructor.
};

#endif
