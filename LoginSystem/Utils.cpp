#include <iostream>

void displayBorder(char ch, int len) {
	for (int i = 0; i < len; i++) {
		std::cout << ch;
	}
	std::cout << std::endl;
}

void displayMenu() {
	displayBorder('=', 100);
	std::cout << std::endl;
	std::cout << " 1. Login " << std::endl;
	std::cout << " 2. Register " << std::endl;
	std::cout << " 3. Quit " << std::endl;
	std::cout << std::endl;
	displayBorder('=', 100);
}