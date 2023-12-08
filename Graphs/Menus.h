#pragma once
#include "Pile.h"
#include "CircularLinkedList.h"
#include "CircularDoubleLinkedList.h"
#include "Graph.h"
#include "Queue.h"

class Menus
{
private:
	struct Data {
		std::string name = "";
		std::string lastName = "";
		int age = 0;
		int reg = 0;
	};
public:
	Menus(Pile* pile);
	Menus(Queue* queue);
	Menus(Graph* graph);
	Menus(LinkedList* linkedList);
	Menus(DoubleLinkedList* doubleLinkedList);
	Menus(CircularLinkedList* circularLinkedList);
	Menus(CircularDoubleLinkedList* circularDoubleLinkedList);
	

	void PathFindingToAll(Graph* graph);
	void PrintActual(Graph* graph);
	void PrintEverything(Graph* graph);
	void PrintWithNodeID(Graph* graph, int NodeID);


	template <typename T>
	T CinFail(T content) {
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			//std::cout << "ERROR: cin overflow, changing the value you entered to 23";
			return (T)23;
		}
		return content;
	}
	std::string CinFail(std::string content) {
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			//std::cout << "ERROR: cin overflow, changing the value you entered to 23";
			return "23";
		}
		return content;
	}
};