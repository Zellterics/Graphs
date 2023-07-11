#pragma once
#include "Graph.h"

class LinkedList:private Graph
{
public:
	LinkedList();
	~LinkedList();
	bool AddElement(int content);
	bool DeleteActual();
	using Graph::PrintActual;
	using Graph::GoToNodeID;
	friend class Menus;
};

