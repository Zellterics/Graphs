#pragma once
#include "LinkedList.h"

class DoubleLinkedList:protected Graph
{
public:
	DoubleLinkedList();
	bool AddElement(int content);
	bool AddNextToActual(int content);
	bool DeleteActual();
	Node* GetEndNode();
	Node* GetStartNode();
	using Graph::GoToNodeID;
	using Graph::PrintActual;
	using Graph::ChangeActualNodeContent;
	friend class Menus;
};

