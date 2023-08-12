#pragma once
#include "DoubleLinkedList.h"

class Pile : private DoubleLinkedList
{
public:
	Pile();
	bool DeleteElement();
	using DoubleLinkedList::AddElement;
	using Graph::GoToNodeID;
	using Graph::PrintActual;
	using Graph::PrintEverything;
	using Graph::ChangeActualNodeContent;
	friend class Menus;
};

