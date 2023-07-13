#pragma once
#include "Pile.h"
#include "LinkedList.h"
#include "DoubleLinkedList.h"
#include "Graph.h"

class Menus
{
public:
	Menus(Pile* pile);
	Menus(Graph* graph);
	Menus(LinkedList* linkedList);
	Menus(DoubleLinkedList* doubleLinkedList);


	template <typename T>
	T CinFail(T content) {
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return (T)69;
		}
		return content;
	}
};