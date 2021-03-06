// Str2Value.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	std::string str;
	std::stringstream stm;
	while (true) {
		std::cout << "Please input string(\\q to quit):";
		std::cin >> str;
		if (std::cin.fail())
			break;

		if (!str.compare("\\q")) {
			break;
		}

		if (str.length() > 8) {
			std::cout << "Too long" << std::endl;
			continue;
		}

		stm.str("");
		stm << "0x";
		for (int i = str.length() - 1; i >= 0; i--) {
			stm << std::hex << (int)str[i];
		}
		std::cout << str << " = " << stm.str() << "," << std::endl;
	}

	//_getch();

	return 0;
}

