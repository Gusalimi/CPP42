/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:53:26 by gsaile            #+#    #+#             */
/*   Updated: 2023/02/12 17:26:44 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds) : _firstName(fn), _lastName(ln), _nickname(nn), _phoneNumber(pn), _darkestSecret(ds)
{
}

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::getFn() const { return (this->_firstName); }
std::string Contact::getLn() const { return (this->_lastName); }
std::string Contact::getNn() const { return (this->_nickname); }
std::string Contact::getPn() const { return (this->_phoneNumber); }
std::string Contact::getDs() const { return (this->_darkestSecret); }
void Contact::setFn(std::string fn) { this->_firstName = fn; }
void Contact::setLn(std::string ln) { this->_lastName = ln; }
void Contact::setNn(std::string nn) { this->_nickname = nn; }
void Contact::setPn(std::string pn) { this->_phoneNumber = pn; }
void Contact::setDs(std::string ds) { this->_darkestSecret = ds; }