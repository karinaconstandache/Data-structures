#pragma once

#include <iostream>

struct node
{
	int info;
	node* prev = nullptr, * next = nullptr;
};

struct list
{
	node* first = nullptr, * last = nullptr;
	int numElem = 0;

	void push_front(int key)
	{
		node* newNode = new node;
		newNode->info = key;
		newNode->prev = nullptr;
		if (first != nullptr)
		{
			newNode->next = first;
			first->prev = newNode;
			first = newNode;
		}
		else first = last = newNode;
		numElem++;
	}
	void push_back(int key)
	{
		node* newNode = new node;
		newNode->info = key;
		newNode->prev = last;
		if (last != nullptr)
		{
			last->next = newNode;
			last = newNode;
		}
		else
		{
			first = last = newNode;
		}
		numElem++;
	}
	void pop_front()
	{
		if (first == nullptr)
		{
			std::cout << "Lista este goala";
			numElem = 0;
			return;
		}
		node* aux;
		aux = first;
		first = aux->next;
		if (first == nullptr)
		{
			last = nullptr;
		}
		delete aux;
		numElem--;
	}
	void pop_back()
	{
		if (last == nullptr)
		{
			std::cout << "Lista este goala";
			numElem = 0;
			return;
		}
		node* aux;
		aux = last;
		last = last->prev;
		if (last == nullptr)
		{
			first = nullptr;
		}
		delete aux;
		numElem--;
	}
	void print(node* first, node* last)
	{
		if (first == nullptr)
		{
			std::cout << "Lista goala \n";
			return;
		}
		node* nod = first;
		while (nod != last)
		{
			std::cout << nod->info << " ";
			nod = nod->next;
		}
		std::cout << nod->info << "\n";
	}
	node* find(int key)
	{
		node* iterator = first;
		while (iterator != nullptr)
		{
			if (iterator->info == key)
				return iterator;
			iterator = iterator->next;
		}
		return nullptr;
	}
	void erase(node* nod)
	{
		if (nod == nullptr)
			return;
		if (nod == first)
		{
			pop_front();
			return;
		}
		else
		{
			if (nod == last)
			{
				pop_back();
				return;
			}
			else
			{
				nod->next->prev = nod->prev;
				nod->prev->next = nod->next;
			}
			delete nod;
		}
	}
	void remove(int key)
	{
		node* it = first;
		while (it != nullptr)
		{
			if (it->info == key)
			{
				node* aux = it->next;
				erase(it);
				it = aux;
			}
			else it = it->next;
		}
	}
	void insert(node* nod, int key)
	{
		node* newNode = new node;
		newNode->info = key;
		nod->prev->next = newNode;
		newNode->next = nod;
		newNode->prev = nod->prev;

	}
	bool empty()
	{
		return first == nullptr;
	}
	void clear()
	{
		while (numElem!=0)
			pop_front();
	}
	int size()
	{
		return numElem;
	}
};

