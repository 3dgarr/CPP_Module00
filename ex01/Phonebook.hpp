#pragma once
#include "./Contact.hpp"
class Phonebook
{
	private:
	Contact				contacts[8];
	const std::string	commands[3];
	int					size;

	private:
	bool	add_contact_failed(int	&index);
	bool	search_failed();
	bool	is_string(const std::string &information);
	bool	is_number(const std::string &information);
	bool	get_command_failed(std::string	&command);
	void	display_phonebook();
	void	print_information(const std::string	&information);
	void	print_all_contacts();
	void	print_contact(const int	&index);



	public:
	Phonebook();
	~Phonebook();
	void	start_program();

};