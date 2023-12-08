#pragma once
#include "DoubleLinkedList.h"

class Queue : private LinkedList
{
public:
	Queue();
	bool InQueue(int content);
	Node DeQueue();
	using LinkedList::AddElement;
	using Graph::GoToNodeID;
	using Graph::ChangeActualNodeContent;
	friend class Menus;
};