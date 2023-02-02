#pragma once
#include "./Contact.hpp"
class Phonebook
{

	public:
	Phonebook();
	~Phonebook();
	void	start_program();


	private:
	bool	is_string(const std::string &information);
	bool	is_number(const std::string &information);
	bool	get_command_failed(std::string	&command);
	bool	search_failed();
	bool	add_contact_failed(int	&index);
	void	display_phonebook();
	void	print_all_contacts();
	void	print_contact(const int	&index);
	void	print_information(const std::string	&information);

	private:
	Contact				contacts[8];
	int					size;


};