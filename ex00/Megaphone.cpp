#include <iostream>

namespace Megaphone 
{
	void print_uppercase(int argc, char **argv)
	{
		if (argc == 1)
			std::cout << "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..." << std::endl;
		else
		{
			for (int i = 1; i  < argc; i++)
			{
				for (size_t j = 0; argv[i][j]; j++)
				{
					std::cout << static_cast<char>(std::toupper(argv[i][j]));
				}
			}
			std::cout << std::endl;
		}
	}
}

int	main(int argc, char **argv)
{
	Megaphone::print_uppercase(argc, argv);
	return (0);
}