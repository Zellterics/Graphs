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
	bool AddNode(int content);
	bool ConectToNodeID(int content, int NodeID);
	bool DeleteActual();
	bool DeleteConectionToNodeID(int NodeID);
	bool DeleteConectionToNodeID(int NodeID, bool DeleteDual);
	bool DualConectToNodeID(int content, int NodeID);
	bool GoToNodeID(int NodeID);
	bool MoveToNodeID(int NodeID);
	int GetEndNodeID();
	int PathFindingToNodeID(int NodeID);
	Node* GetNodeWithID(int NodeID);
	void PathFindingToAll();
	void PrintActual();
	void PrintActualConections();
	void PrintAllNodes();
	void PrintEverything();
	void PrintWithNodeID(int NodeID);
};