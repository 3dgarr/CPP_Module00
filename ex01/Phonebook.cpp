#include "./Phonebook.hpp"
#include <iomanip>
#include <limits>
bool	Phonebook::get_command_failed(std::string &command)
{
	std::cin.clear();
	std::cout << "Please enter command :" <<std::flush;
	getline(std::cin, command);
	if (std::cin.eof())
		return (true);
	return (false);	
}

bool	Phonebook::is_string(const std::string &information)
{
	for (size_t i = 0; i < information.length(); i++)
	{
		if (!std::isalpha(information[i]))
			return (false);
	}
	return (true);	
}

bool	Phonebook::is_number(const std::string &information)
{
	for (size_t i = 0; i < information.length(); i++)
	{
		if (!std::isdigit(information[i]))
			return (false);
	}
	return (true);	
}

Phonebook::Phonebook(){size = 0;};
Phonebook::~Phonebook(){};

bool	Phonebook::add_contact_failed(int	&i)
{
	std::string		information;
	int				j;

	std::cout << "Enter the information about contact:" << std::endl;
	std::cout << "1.First name" << std::endl;
	std::cout << "2.Last name" << std::endl;
	std::cout << "3.Nickname" << std::endl;
	std::cout << "4.Phone number" << std::endl;
	std::cout << "5.Darkest secret" << std::endl;
	j = 0;
	if (i > 7)
		i %= 8;
	while (j < 5)
	{
		std::cout << j + 1 << "-> ";
		getline(std::cin, information);
		if (std::cin.eof() || std::cin.bad())
			return (true);
		if (j == 0)
		{
			if (is_string(information))
				contacts[i].set_name(information);
			else
			{
				std::cout << "Bad argument passed! Try again" << std::endl;
				continue ;
			}

		}
		else if (j == 1)
		{
			if (is_string(information))
				contacts[i].set_last_name(information);
			else
			{
				std::cout << "Bad argument passed! Try again" << std::endl;
				continue ;
			}
		}
		else if (j == 2)
		{
			contacts[i].set_nickname(information);
		}
		else if (j == 3)
		{	
			if (is_number(information))
				contacts[i].set_phone_number(information);
			else
			{
				std::cout << "Bad argument passed! Try again" << std::endl;
				continue ;
			}
		}
		else if (j == 4)
		{
			contacts[i].set_darkest_secret(information);
		}
		j++;
	}
	std::cout << "User[" << i + 1 << "] was successfully added" << std::endl;
	i++;
	if (size < 8)
		size++;
	return (false);		
}

void	Phonebook::print_information(const std::string	&information)
{
	if (information.length() <= 10)
		std::cout << std::setw(10) << information << "|";
	else
		std::cout << information.substr(0, 9) << ".|";
}

void	Phonebook::print_all_contacts()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		print_information(contacts[i].get_name());
		print_information(contacts[i].get_last_name());
		print_information(contacts[i].get_nickname());
		std::cout << std::endl;
	}
}

void	Phonebook::display_phonebook()
{
	std::cout << std::endl;
	std::cout << "|";
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	print_all_contacts();
		
}

void	Phonebook::print_contact(const int	&index)
{
	std::cout << std::endl;
	std::cout << "First name     -> " << contacts[index - 1].get_name() << std::endl;
	std::cout << "Last name      -> " << contacts[index - 1].get_last_name() << std::endl;
	std::cout << "Nickname       -> " << contacts[index - 1].get_nickname() << std::endl;
	std::cout << "Phone Number   -> " << contacts[index - 1].get_phone_number() << std::endl;
	std::cout << "Darkest Secret -> " << contacts[index - 1].get_darkest_secret() << std::endl;
}

bool	Phonebook::search_failed()
{
	int		index;

	display_phonebook();
	std::cout << "Enter the index of contact you want to see: ";
	std::cin >> index;
	if (std::cin.eof() || std::cin.bad())
		return (true);
	if (index <= 0 || index > size)
		std::cout << "There is no contact in this index" << std::endl;
	else
		print_contact(index);
	std::cin.ignore(8, '\n');
	return (false);
}



void	Phonebook::start_program()
{
	int				i;
	std::string		command;

	i = 0;
	while (true)
	{
		if (get_command_failed(command))
			return ;
		if (command == "ADD")
		{
			if (add_contact_failed(i))
				return ;
		}
		else if (command == "SEARCH")
		{
			if (search_failed())
				return ;
		}
		else if (command == "EXIT")
			return ;
		else
			std::cout << "Bad command: Try only these ['ADD', 'SEARCH', 'EXIT']" << std::endl;
		
	}
}