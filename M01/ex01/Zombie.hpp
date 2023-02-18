/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:46:13 by gsaile            #+#    #+#             */
/*   Updated: 2023/02/18 12:20:27 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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