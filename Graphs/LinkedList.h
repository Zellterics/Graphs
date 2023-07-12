#pragma once
#include "Graph.h"

class LinkedList:protected Graph
{
public:
	LinkedList();
	bool AddElement(int content);
	bool DeleteActual();
	using Graph::PrintActual;
	using Graph::GoToNodeID;
	friend class Menus;
};

