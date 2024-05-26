#include "HashTable.h"
#include <iostream>

void readFile(std::string cale,HashTable& table)
{
	int n,key,value;
	std::ifstream f(cale);
	f >> n;
	for (int i = 0; i < n; i++)
	{
		f >> key >> value;
		table.insert(key, value);
	}
}
int main()
{
	HashTable table(11);
	readFile("HashTable.txt",table);
	int command,key,value;
	std::cout << "\nMeniu:\n";
	std::cout << "1. Cautare\n";
	std::cout << "2. Inserare element\n";
	std::cout << "3. Afisare tabela\n";
	std::cout << "4. Iesire\n";
	do {
		std::cout << "Introduceti comanda: ";
		std::cin >> command;

		switch (command) {
		case 1:
			std::cout << "Introduceti cheia cautata: ";
			std::cin >> key;
			value = table.search(key);
			if (value != -1) {
				std::cout << "Exista : " << value << std::endl;
			}
			else {
				std::cout << "Nu exista\n";
			}
			break;
		case 2:
			std::cout << "Introduceti un element pentru inserare : ";
			std::cin >> key >> value;
			table.insert(key, value);
			std::cout << "Elementul a fost introdus\n";
			break;
		case 3:
			std::cout << "Tabela curenta :\n";
			table.printTable();
			break;
		case 4:
			break;
		default:
			std::cout << "Comanda invalida\n";
		}
	} while (command != 4);
}