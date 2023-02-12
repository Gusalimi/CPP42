/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:52:30 by gsaile            #+#    #+#             */
/*   Updated: 2023/02/12 17:29:28 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    PhoneBook pb;
    pb.addContact("Guillaume", "Sailé", "gsaile", "fkjaslfjsakl", "kfjsdlafjlksd");
    std::cout << pb.getContact(0).getFn() << " | " << pb.getContact(0).getLn() << " | " << pb.getContact(0).getNn() << " | " << pb.getContact(0).getPn() << " | " << pb.getContact(0).getDs() << std::endl;
}