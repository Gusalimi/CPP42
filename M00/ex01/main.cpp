/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:52:30 by gsaile            #+#    #+#             */
/*   Updated: 2023/02/13 17:19:25 by gsaile           ###   ########.fr       */
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
		if (fn.size() > 10)
		{
			fn.resize(10);
			fn[9] = '.';
		}
		if (ln.size() > 10)
		{
			ln.resize(10);
			ln[9] = '.';
		}
		if (nn.size() > 10)
		{
			nn.resize(10);
			nn[9] = '.';
		}
		if (pn.size() > 10)
		{
			pn.resize(10);
			pn[9] = '.';
		}
		if (ds.size() > 10)
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

bool	isANum(std::string pn)
{
	int	i = 0;
	while (std::isspace(pn[i]))
		i++;
	while (pn[i])
	{
		if (std::isspace(pn[i]))
			break ;
		if (pn[i] < '0' || pn[i] > '9')
			return (false);
		i++;
	}
	while (std::isspace(pn[i]))
		i++;
	if (pn[i])
		return (false);
	return (true);
}

int add(PhoneBook *pb)
{
	bool        firstTry = true;
	std::string fn = "";
	std::string ln = "";
	std::string nn = "";
	std::string pn = "";
	std::string ds = "";
	while (fn.empty())
	{
		if (firstTry)
			std::cout << "Enter First Name : ";
		else
			std::cout << "Invalid First Name (can't be empty), please try again : ";
		firstTry = false;
		if (!std::getline(std::cin, fn))
			return (1);
	}
	firstTry = true;
	while (ln.empty())
	{
		if (firstTry)
			std::cout << "Enter Last Name : ";
		else
			std::cout << "Invalid Last Name (can't be empty), please try again : ";
		firstTry = false;
		if (!std::getline(std::cin, ln))
			return (1);
	}
	firstTry = true;
	while (nn.empty())
	{
		if (firstTry)
			std::cout << "Enter Nickname : ";
		else
			std::cout << "Invalid Nickname (can't be empty), please try again : ";
		firstTry = false;
		if (!std::getline(std::cin, nn))
			return (1);
	}
	firstTry = true;
	while (pn.empty() || !isANum(pn))
	{
		if (firstTry)
			std::cout << "Enter Phone Number : ";
		else
			std::cout << "Invalid Phone Number (can't be empty and must be digits only), please try again : ";
		firstTry = false;
		if (!std::getline(std::cin, pn))
			return (1);
	}
	firstTry = true;
	while (ds.empty())
	{
		if (firstTry)
			std::cout << "Enter Darkest Secret : ";
		else
			std::cout << "Invalid Darkest Secret (can't be empty), please try again : ";
		firstTry = false;
		if (!std::getline(std::cin, ds))
			return (1);
	}
	pb->addContact(fn, ln, nn, pn, ds);
	return (0);
}

int search(PhoneBook pb)
{
	bool	firstTry = true;
	std::string	index = "";

	print_phonebook(pb);
	while (index != "1" && index != "2" && index != "3" && index != "4" && index != "5" && index != "6" && index != "7" && index != "8")
	{
		if (firstTry)
			std::cout << "Enter the index of the contact you're searching : ";
		else
			std::cout << "Wrong index, please try again : ";
		firstTry = false;
		if (!std::getline(std::cin, index))
			return (1);
	}
	print_contact(pb.getContact(std::stoi(index) - 1));
	return (0);
}

int main()
{
	PhoneBook pb;
	std::string cmd;
	std::cout << "> ";
	while (std::getline(std::cin, cmd))
	{
		if (cmd == "ADD")
		{
			if (add(&pb) != 0)
				return (1);
		}
		else if (cmd == "SEARCH")
		{
			if (search(pb) != 0)
				return (1);
		}
		else if (cmd == "EXIT")
			return (0);
		std::cout << "> ";
	}
	std::cout << std::endl;
}