/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:52:30 by gsaile            #+#    #+#             */
/*   Updated: 2023/02/12 18:02:45 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void    print_phonebook(PhoneBook pb)
{
    std::string fn;
    std::string ln;
    std::string nn;
    std::string pn;
    std::string ds;
    for (int i = 0; i < 33; i++)
        std::cout << " -";
    std::cout << std::endl;
    for (int i = 0; i < 8; i++)
    {
        fn = pb.getContact(i).getFn();
        ln = pb.getContact(i).getLn();
        nn = pb.getContact(i).getNn();
        pn = pb.getContact(i).getPn();
        ds = pb.getContact(i).getDs();
        if (fn.size() >= 10)
        {
            fn.resize(10);
            fn[9] = '.';
        }
        if (ln.size() >= 10)
        {
            ln.resize(10);
            ln[9] = '.';
        }
        if (nn.size() >= 10)
        {
            nn.resize(10);
            nn[9] = '.';
        }
        if (pn.size() >= 10)
        {
            pn.resize(10);
            pn[9] = '.';
        }
        if (ds.size() >= 10)
        {
            ds.resize(10);
            ds[9] = '.';
        }
        std::cout << "|";
        std::cout << std::right << std::setw(10) << i + 1 << "|";
        std::cout << std::right << std::setw(10) << fn << "|";
        std::cout << std::right << std::setw(10) << ln << "|";
        std::cout << std::right << std::setw(10) << nn << "|";
        std::cout << std::right << std::setw(10) << pn << "|";
        std::cout << std::right << std::setw(10) << ds << "|";
        std::cout << std::endl;
    }
   for (int i = 0; i < 33; i++)
        std::cout << " -";
    std::cout << std::endl;
}

void    print_contact(Contact contact)
{
    std::cout << "First Name : " << contact.getFn() << std::endl;
    std::cout << "Last Name : " << contact.getLn() << std::endl;
    std::cout << "Nickname : " << contact.getNn() << std::endl;
    std::cout << "Phone Number : " << contact.getPn() << std::endl;
    std::cout << "Darkest Secret : " << contact.getDs() << std::endl;
}

int main()
{
    PhoneBook pb;
    pb.addContact("Guillaume", "Saile", "gsaile", "fkjaslfjsakl", "kfjsdlafjlksd");
    print_contact(pb.getContact(0));
    print_phonebook(pb);
}