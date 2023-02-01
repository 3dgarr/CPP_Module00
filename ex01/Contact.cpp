#include "./Contact.hpp"

const std::string& Contact::get_name()
{
	return name;
}

const std::string& Contact::get_last_name()
{
	return last_name;
}

const std::string& Contact::get_nickname()
{
	return nickname;
}

const std::string& Contact::get_phone_number()
{
	return phone_number;
}

const std::string& Contact::get_darkest_secret()
{
	return darkest_secret;
}

void	Contact::set_name(const std::string &str)
{
	name = str;
}

void	Contact::set_last_name(const std::string &str)
{
	last_name = str;
}

void	Contact::set_nickname(const std::string &str)
{
	nickname = str;
}

void	Contact::set_phone_number(const std::string &str)
{
	phone_number = str;
}

void	Contact::set_darkest_secret(const std::string &str)
{
	darkest_secret = str;
}