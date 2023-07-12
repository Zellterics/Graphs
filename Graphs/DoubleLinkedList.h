#pragma once
#include "LinkedList.h"

class DoubleLinkedList:private LinkedList
{
public:
	DoubleLinkedList();
	bool AddElement(int content);
	bool DeleteActual();
	friend class Menus;
};

