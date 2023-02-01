#pragma once
#include <iostream>

class Contact
{
	public:

	void				set_name(const std::string &str);		
	void				set_last_name(const std::string &str);	
	void				set_nickname(const std::string &str);		
	void				set_phone_number(const std::string &str);		
	void				set_darkest_secret(const std::string &str);		

	const std::string&	get_name();
	const std::string&	get_last_name();
	const std::string&	get_nickname();
	const std::string&	get_phone_number();
	const std::string&	get_darkest_secret();
	
	private:

	std::string			name;
	std::string			last_name;
	std::string			nickname;
	std::string			phone_number;
	std::string			darkest_secret;
};
