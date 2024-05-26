#include "DoublyLinkedList.h"
#include <iostream>

bool palindrom(list lista)
{
	if (lista.empty()) return 0;
	node* it1 = lista.first, * it2=lista.last;
	while (it1 != it2)
	{
		if (it1->info != it2->info) return 0;
		it1 = it1->next;
		it2 = it2->prev;
	}
	return 1;
}
bool compare(list l1, list l2)
{
	if (l1.size() != l2.size()) return 0;
	node* it1 = l1.first , * it2=l2.first;
	while (it1 != nullptr and it2 != nullptr)
	{
		if (it1->info != it2->info) return 0;
		it1 = it1->next;
		it2 = it2->next;
	}
	return 1;

}
int main()
{
	std::cout << "Comenzi:\n";
	std::cout << "1. Push_front\n";
	std::cout << "2. Push_back\n";
	std::cout << "3. Pop_front\n";
	std::cout << "4. Pop_back\n";
	std::cout << "5. Find\n";
	std::cout << "6. Erase\n";
	std::cout << "7. Remove \n";
	std::cout << "8. Insert\n";
	std::cout << "9. Empty\n";
	std::cout << "10. Clear\n";
	std::cout << "11. Print\n";
	std::cout << "12. Size\n";
	std::cout << "13. Palindrom\n";
	std::cout << "14. Exit\n";
	int comanda;
	list lista;
	do {
		int x, n;
		std::cout << " Introduceti o comanda: ";
		std::cin >> comanda;
		switch (comanda)
		{
		case(1):
			int x;
			std::cout << "Introduceti o valoare ";
			std::cin >> x;
			lista.push_front(x);
			break;
		case (2):

			std::cout << "Introduceti o valoare ";
			std::cin >> x;
			lista.push_back(x);
			break;
		case(3):
			lista.pop_front();
			break;
		case(4):
			lista.pop_back();
			break;
		case(5):
			std::cout << "Introduceti o valoare ";
			std::cin >> x;
			std::cout << lista.find(x);
			break;
		case(6):
			std::cout << "Introduceti o valoare ";
			std::cin >> x;
			lista.erase(lista.find(x));
			break;
		case(7):
			std::cout << "Introduceti o valoare ";
			std::cin >> x;
			lista.remove(x);
			break;
		case(8):
			std::cout << "Introduceti o valoare ";
			std::cin >> x;
			std::cout << "Nodul referinta";
			std::cin >> n;
			lista.insert(lista.find(n), x);
			break;
		case(9):
			if (lista.empty())
				std::cout << "Lista este goala\n";
			else std::cout << "Lista este populata\n";
			break;
		case(10):
			lista.clear();
			break;
		case(11):
			lista.print(lista.first, lista.last);
			break;
		case(12):
			std::cout << "Lungimea listei este " << lista.size() << "\n";
			break;
		case(13):
			if (palindrom(lista))
				std::cout << "Palindrom\n";
			else std::cout << "Nu este palindrom\n";
		default:
			break;
		}
	} while (comanda != 14);
}