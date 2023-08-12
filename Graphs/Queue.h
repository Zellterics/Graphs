#pragma once
#include "DoubleLinkedList.h"

class Queue : private DoubleLinkedList
{
public:
	Queue();
	bool DeleteElement();
	using DoubleLinkedList::AddElement;
	using Graph::GoToNodeID;
	using Graph::PrintActual;
	using Graph::PrintEverything;
	using Graph::ChangeActualNodeContent;
	friend class Menus;
};

