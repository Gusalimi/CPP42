/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:28:19 by gsaile            #+#    #+#             */
/*   Updated: 2023/02/20 14:11:26 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int replace(int argc, char **argv)
{
	std::ifstream	ifs;
	std::string		name;
	std::ofstream	ofs;
	std::string		line;
	int				pos;
	int				old_pos;
	if (argc != 4)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return (1);
	}
	ifs.open(argv[1]);
	if (ifs.fail())
	{
		std::cerr << "Can't open " << argv[1] << " for reading" << std::endl;
		return (1);
	}
	name = (std::string)argv[1] + (std::string)".replace";
	ofs.open(name);
	if (ofs.fail())
	{
		std::cerr << "Can't open " << name << " for writing" << std::endl;
		return (1);
	}
	while(std::getline(ifs, line))
	{
		old_pos = 0;
		pos = line.find(argv[2]);
		if (pos == (int)std::string::npos)
			ofs << line << std::endl;
		else
		{
			while (pos != (int)std::string::npos)
			{
				ofs << line.substr(0, pos) << argv[3];
				line = line.substr(pos + strlen(argv[2]), line.length());
				pos = line.find(argv[2]);
			}
			ofs << line;
			ofs << std::endl;
		}
	}
	ofs.close();
	ifs.close();
	return (0);
}

int	main(int argc, char **argv)
{
	return (replace(argc, argv));
}
