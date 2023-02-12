/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:52:43 by gsaile            #+#    #+#             */
/*   Updated: 2023/02/12 17:31:19 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _lastContact( 7 )
{
}

PhoneBook::~PhoneBook()
{
}

int		PhoneBook::addContact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
    this->_lastContact++;
    if (this->_lastContact == 8)
        this->_lastContact = 0;
    this->_contacts[this->_lastContact].setFn(fn);
    this->_contacts[this->_lastContact].setLn(ln);
    this->_contacts[this->_lastContact].setNn(nn);
    this->_contacts[this->_lastContact].setPn(pn);
    this->_contacts[this->_lastContact].setDs(ds);
    return (0);
}

Contact PhoneBook::getContact(int index) const
{
    return (this->_contacts[index]);
}