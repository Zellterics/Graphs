#pragma once
#include "ConectionsList.h"
#include <iostream>

class Node
{
private:
	int ID, content;
	ConectionsList* conectionList = nullptr;
	Node* past, * next = nullptr, * mySelf = this;
public:
	Node(int content, Node* past);
	~Node();
	bool ConectToNodeID(int content, int NodeID);
	bool DeleteConectionToNodeID(int NodeID);
	bool ExistedNodeID(int NodeID);
	bool SetID(int NodeID);
	bool SetNext(Node* next);
	bool SetPast(Node* past);
	int GetConectionValueTowardsNodeID(int NodeID);
	int GetContent();
	int GetGrade();
	int GetID();
	int GetNodeIDOnListPosition(int position);
	Node* GetNext();
	Node* GetPast();
	void PrintConectionList();
	void PrintThis();
};