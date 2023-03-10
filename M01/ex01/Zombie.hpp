/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:46:13 by gsaile            #+#    #+#             */
/*   Updated: 2023/02/18 13:18:45 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
public:
	Zombie(std::string name);
	Zombie( void );
	~Zombie( void );
	void	announce( void );
	void	setName(std::string name);
private:
	std::string	name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif