#include <iostream>


void boot() {
	std::cout << "Uruchamianie systemu..." << std::endl;
}
int main() {
	boot();
	std::cin.ignore(1);
	return 0;
}