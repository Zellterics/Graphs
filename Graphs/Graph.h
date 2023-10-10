#pragma once
#include "Node.h"
#include <iostream>

class Graph
{
protected:
	Node* start, * move, * end, * actual;
public:
	Graph();
	Graph(int content);
	~Graph();
	bool AddNode(int content);
	bool ConectToNodeID(int content, int NodeID);
	bool ChangeActualNodeContent(int content);
	bool DeleteActual();
	bool DeleteConectionToNodeID(int NodeID);
	bool DeleteConectionToNodeID(int NodeID, bool DeleteDual);
	bool DualConectToNodeID(int content, int NodeID);
	bool ExistedID(int NodeID);
	bool GoToNodeID(int NodeID);
	bool MoveToNodeID(int NodeID);
	int CountNodes();
	int PathFindingToNodeID(int NodeID);
	Node* GetActualNode();
	Node* GetEndNode();
	Node* GetNextNode();
	Node* GetNodeWithID(int NodeID);
	Node* GetPastNode();
	Node* GetStartNode();
	void PathFindingToAll();

	void PrintActual();
	void PrintActualConections();
	void PrintAllNodes();
	void PrintWithNodeID(int NodeID);

	template <typename T>
	T GetActualData() {
		return actual->GetData();
	}
	template <typename T>
	T SetActualData(T data) {
		return actual->SetData(data);
	}
};