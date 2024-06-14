#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "\"Harl is abnormally silent and blatantly staring at you\"\n", 1);

	Harl harl;
	std::string input = argv[1];
	std::string type[4] = {"debug", "info", "warning", "error"};
	std::string type_upper[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int found = 0;
	for (int i = 0; i < 4; i++)
	{
		if (input == type[i] || input == type_upper[i] ||  found == 1)
		{
			found = 1;
			switch (i)
			{
				case 0:
					harl.complain("debug");
					break;
				case 1:
					harl.complain("info");
					break;
				case 2:
					harl.complain("warning");
					break;
				case 3:
					harl.complain("error");
					break;
			}
		}
	}
	if (found == 0)
		std::cout << "I understood your statements, but I asked for a cola!\n";
	return (0);
}