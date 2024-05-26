#pragma once

#include <iostream>
#include <fstream>
#include <list>
#include <vector>

class HashTable
{
private:

	std::vector < std::list<std::pair<int, int>>> table;
	int size;

public:

	HashTable(int size)
	{
		this->size = size;
		table.resize(size);
	}
	int hash(int key)
	{
		return key % size;
	}
	void insert(int key, int value)
	{
		int i = hash(key);
		table[i].push_back(std::make_pair(key, value));
	}
	int search(int key)
	{
		int i = hash(key);
		for (auto& element : table[i])
		{
			if (element.first == key) return element.second;
		}
		return -1;
	}
	void printTable()
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << "Casuta " << i << " : ";
			for (auto& element : table[i])
			{
				std::cout << "(" << element.first << "," << element.second << "); ";
			}
			std::cout << std::endl;
		}
	}
};
