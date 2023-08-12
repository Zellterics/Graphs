#pragma once
#include "Pile.h"
#include "LinkedList.h"
#include "DoubleLinkedList.h"
#include "Graph.h"
#include "Queue.h"

class Menus
{
public:
	Menus(Pile* pile);
	Menus(Queue* queue);
	Menus(Graph* graph);
	Menus(LinkedList* linkedList);
	Menus(DoubleLinkedList* doubleLinkedList);


	template <typename T>
	T CinFail(T content) {
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "ERROR: cin overflow, changing the value you entered to 23";
			return (T)23;
		}
		return content;
	}
};