#pragma once
#include "DoubleLinkedList.h"
class CircularDoubleLinkedList : protected DoubleLinkedList
{
public:
	CircularDoubleLinkedList();
	bool AddElement(int content);
	Node* GetEndNode();
	using DoubleLinkedList::AddNextToActual;
	using DoubleLinkedList::DeleteActual;
	using Graph::GoToNodeID;
	using Graph::ChangeActualNodeContent;
	friend class Menus;
};