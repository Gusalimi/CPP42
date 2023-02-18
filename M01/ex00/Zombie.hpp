/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:46:13 by gsaile            #+#    #+#             */
/*   Updated: 2023/02/18 13:18:16 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

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

#endif