#pragma once
#include "LinkedList.h"
class CircularLinkedList : protected LinkedList
{
public:
	CircularLinkedList();
	bool AddElement(int content);
	using LinkedList::AddNextToActual;
	using LinkedList::DeleteActual;
	using LinkedList::GetPastOfNode;
	using Graph::GoToNodeID;
	using Graph::ChangeActualNodeContent;
	friend class Menus;
};