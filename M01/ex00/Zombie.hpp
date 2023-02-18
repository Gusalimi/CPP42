/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:46:13 by gsaile            #+#    #+#             */
/*   Updated: 2023/02/18 11:57:18 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
public:
    Zombie(std::string name);
    ~Zombie();
    void    announce( void );
private:
    std::string name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);