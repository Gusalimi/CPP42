/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:53:43 by gsaile            #+#    #+#             */
/*   Updated: 2023/02/12 17:26:28 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact
{
public:
	Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
	Contact();
	~Contact();
	std::string getFn() const;
	std::string getLn() const;
	std::string getNn() const;
	std::string getPn() const;
	std::string getDs() const;
	void setFn(std::string fn);
	void setLn(std::string ln);
	void setNn(std::string nn);
	void setPn(std::string pn);
	void setDs(std::string ds);

private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
};

#endif