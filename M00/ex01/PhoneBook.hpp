/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:53:43 by gsaile            #+#    #+#             */
/*   Updated: 2023/02/12 17:18:52 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	int		addContact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
	Contact	getContact(int index) const;
private:
	Contact _contacts[8];
	int		_lastContact;
};

#endif