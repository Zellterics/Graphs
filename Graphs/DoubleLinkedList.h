#pragma once
#include "LinkedList.h"

class DoubleLinkedList:private Graph
{
public:
	DoubleLinkedList();
	bool AddElement(int content);
	bool AddNextToActual(int content);
	bool DeleteActual();
	Node* GetEndNode();
	friend class Menus;
};

