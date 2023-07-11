#include "Graph.h"

Graph::Graph(int content) {
	start = new Node(content, nullptr);
	move = start;
	end = start;
	actual = start;
}
Graph::Graph() {
	start = nullptr;
	move = nullptr;
	end = nullptr;
	actual = nullptr;
}

bool Graph::AddNode(int content) {
	if (start == nullptr) {
		start = new Node(content, nullptr);
		move = start;
		end = start;
		actual = start;
		return true;
	}
	move = end;
	end = new Node(content, move);
	actual = end;
	return true;
}

void Graph::PrintActual() {
	if (actual == nullptr) {
		std::cout << "ERROR: There's No Actual Node" << std::endl;
		return;
	}
	actual->PrintThis();
}

void Graph::PrintWithNodeID(int NodeID) {
	if (start == nullptr) {
		std::cout << "ERROR: The Graph Is Empty" << std::endl;
		return;
	}
	move = GetNodeWithID(NodeID);
	if (move == nullptr) {
		std::cout << "ERROR: Node " << NodeID << " Doesn't Exists" << std::endl;
		return;
	}
	move->PrintThis();
}

void Graph::PrintAllNodes() {
	if (start == nullptr) {
		std::cout << "ERROR: The Graph Is Empty" << std::endl;
		return;
	}
	move = start;
	while (move != nullptr) {
		move->PrintThis();
		std::cout << "\n";
		move = move->GetNext();
	}
}

void Graph::PrintActualConections() {
	if (actual == nullptr) {
		std::cout << "ERROR: There's No Actual Node" << std::endl;
		return;
	}
	actual->PrintConectionList();
}

bool Graph::ConectToNodeID(int content, int NodeID) {
	if (start == nullptr) {
		std::cout << "ERROR: The Graph Is Empty" << std::endl;
		return false;
	}
	if (NodeID > end->GetID()) {
		std::cout << "ERROR: NODE " << NodeID << " DOESN'T EXISTS" << std::endl;
		return false;
	}
	actual->ConectToNodeID(content, NodeID);
	return true;
}

bool Graph::GoToNodeID(int NodeID) {
	if (start == nullptr) {
		std::cout << "ERROR: The Graph Is Empty" << std::endl;
		return false;
	}
	move = start;
	while (move != nullptr) {
		if (move->GetID() == NodeID) {
			actual = move;
			return true;
		}
		move = move->GetNext();
	}
	return false;
}

bool Graph::MoveToNodeID(int NodeID) {
	if (actual == nullptr) {
		std::cout << "ERROR: There's No Actual Node" << std::endl;
		return false;
	}
	if (actual->ExistedNodeID(NodeID)) {
		GoToNodeID(NodeID);
		return true;
	}
	else {
		return false;
	}
}

void Graph::PrintEverything() {
	if (start == nullptr) {
		std::cout << "ERROR: The Graph Is Empty" << std::endl;
		return;
	}
	move = start;
	while (move != nullptr) {
		move->PrintThis();
		std::cout << "\n";
		move->PrintConectionList();
		std::cout << "\n\n";
		move = move->GetNext();
	}
}

int Graph::PathFindingToNodeID(int NodeID) {
	if (actual == nullptr) {
		std::cout << "ERROR: There's No Actual Node" << std::endl;
		return -1;
	}
	ConectionsList NodeSteps(0, actual->GetID(), 6);
	move = actual;
	for (int i = 1;; i++) {
		for (int j = 0; move->GetNodeIDOnListPosition(j) != -1; j++) {
			if (NodeSteps.GetConectionValueOnNodeID(move->GetNodeIDOnListPosition(j)) > (move->GetConectionValueTowardsNodeID(move->GetNodeIDOnListPosition(j)) + NodeSteps.GetConectionValueOnNodeID(move->GetID()))) {
				NodeSteps.ReplaceValuesOnNodeID(move->GetConectionValueTowardsNodeID(move->GetNodeIDOnListPosition(j)) + NodeSteps.GetConectionValueOnNodeID(move->GetID()), move->GetNodeIDOnListPosition(j), move->GetID());
				i = 1;
			}
			if (!NodeSteps.ExistedID(move->GetNodeIDOnListPosition(j))) {
				NodeSteps.AddConection(move->GetConectionValueTowardsNodeID(move->GetNodeIDOnListPosition(j)) + NodeSteps.GetConectionValueOnNodeID(move->GetID()), move->GetNodeIDOnListPosition(j), move->GetID());
			}
		}
		if (NodeSteps.GetConectionOnListPosition(i) == -1) {
			break;
		}
		move = GetNodeWithID(NodeSteps.GetConectionOnListPosition(i));
	}
	move = GetNodeWithID(NodeID);
	while (move != actual) {
		move->PrintThis();
		std::cout << "----> ";
		move = GetNodeWithID(NodeSteps.GetConectionExtraUtilitysOnNodeID(move->GetID()));
	}
	std::cout << " Nodo" << move->GetContent();
	return NodeSteps.GetConectionValueOnNodeID(NodeID);
}

void Graph::PathFindingToAll() {
	if (actual == nullptr) {
		std::cout << "ERROR: There's No Actual Node" << std::endl;
		return;
	}
	ConectionsList NodeSteps(0, actual->GetID(), 6);
	move = actual;
	for (int i = 1;; i++) {
		for (int j = 0; move->GetNodeIDOnListPosition(j) != -1; j++) {
			if (NodeSteps.GetConectionValueOnNodeID(move->GetNodeIDOnListPosition(j)) > (move->GetConectionValueTowardsNodeID(move->GetNodeIDOnListPosition(j)) + NodeSteps.GetConectionValueOnNodeID(move->GetID()))) {
				NodeSteps.ReplaceValuesOnNodeID(move->GetConectionValueTowardsNodeID(move->GetNodeIDOnListPosition(j)) + NodeSteps.GetConectionValueOnNodeID(move->GetID()), move->GetNodeIDOnListPosition(j), move->GetID());
				i = 1;
			}
			if (!NodeSteps.ExistedID(move->GetNodeIDOnListPosition(j))) {
				NodeSteps.AddConection(move->GetConectionValueTowardsNodeID(move->GetNodeIDOnListPosition(j)) + NodeSteps.GetConectionValueOnNodeID(move->GetID()), move->GetNodeIDOnListPosition(j), move->GetID());
			}
		}
		if (NodeSteps.GetConectionOnListPosition(i) == -1) {
			break;
		}
		move = GetNodeWithID(NodeSteps.GetConectionOnListPosition(i));
	}
	NodeSteps.PrintAllConections();
	return;
}

Node* Graph::GetNodeWithID(int NodeID) {
	if (start == nullptr) {
		std::cout << "ERROR: The Graph Is Empty" << std::endl;
		return nullptr;
	}
	move = start;
	while (move != nullptr) {
		if (move->GetID() == NodeID) {
			return move;
		}
		move = move->GetNext();
	}
	return nullptr;
}

int Graph::GetEndNodeID() {
	if (actual == nullptr) {
		std::cout << "ERROR: There's No End Node" << std::endl;
		return -1;
	}
	move = actual;
	Node* Save = actual;
	while (move != nullptr) {
		Save = move;
		move = move->GetNext();
	}
	move = actual;
	return Save->GetID();
}

bool Graph::DualConectToNodeID(int content, int NodeID) {
	if (start == nullptr) {
		std::cout << "ERROR: The Graph Is Empty" << std::endl;
		return false;
	}
	if (NodeID > end->GetID()) {
		std::cout << "ERROR: Node " << NodeID << " Doesn't Exists" << std::endl;
		return false;
	}
	actual->ConectToNodeID(content, NodeID);
	move = GetNodeWithID(NodeID);
	move->ConectToNodeID(content, actual->GetID());
	return true;
}

bool Graph::DeleteActual() {
	if (actual == nullptr) {
		std::cout << "ERROR: There's No Actual Node" << std::endl;
		return false;
	}
	move = start;
	while (move != nullptr) {
		if (move != actual) {
			move->DeleteConectionToNodeID(actual->GetID());
		}
		move = move->GetNext();
	}
	move = actual;
	if (start == end) {
		delete start;
		start = nullptr;
		end = nullptr;
		move = nullptr;
		actual = nullptr;
		return true;
	}
	Node* Erase = move;
	Node* Past = nullptr;
	Node* Next = nullptr;
	if (move->GetPast() != nullptr) {
		Past = move->GetPast();
		if (move->GetNext() != nullptr) {
			Past->SetNext(move->GetNext());
		}
		else {
			Past->SetNext(nullptr);
			end = Past;
		}
	}
	if (move->GetNext() != nullptr) {
		Next = move->GetNext();
		if (move->GetPast() != nullptr) {
			Next->SetPast(move->GetPast());
		}
		else {
			Next->SetPast(nullptr);
			start = Next;
		}
	}
	move = move->GetNext();
	delete(Erase);
	actual = start;
	return true;
}

bool Graph::DeleteConectionToNodeID(int NodeID) {
	if (actual == nullptr) {
		std::cout << "ERROR: There's No Actual Node" << std::endl;
		return false;
	}
	if (!actual->ExistedNodeID(NodeID)) {
		std::cout << "ERROR: Node " << NodeID << " Doesn't Exists" << std::endl;
	}
	return actual->DeleteConectionToNodeID(NodeID);
}

bool Graph::DeleteConectionToNodeID(int NodeID, bool DeleteDual) {
	if (actual == nullptr) {
		std::cout << "ERROR: There's No Actual Node" << std::endl;
		return false;
	}
	if(!actual->ExistedNodeID(NodeID)) {
		std::cout << "ERROR: Node " << NodeID << " Doesn't Exists" << std::endl;
	}
	if (!DeleteDual) {
		return DeleteConectionToNodeID(NodeID);
	}
	move = GetNodeWithID(NodeID);
	actual->DeleteConectionToNodeID(NodeID);
	move->DeleteConectionToNodeID(actual->GetID());
	return false;
}

/*
TEST:
//a 0 a 1 a 2 a 3 a 4 a 5 a 6 a 7 a 8 a 9 a 10 g 0 c 2 1 c 1 2 g 1 c 2 0 c 3 3 g 2 c 1 4 c 1 6 g 3 c 3 1 g 4 c 3 5 c 6 0 g 5 c 4 6 g 6 c 5 4 c 1 3 c 1 7 g 7 c 1 8 g 8 c 1 9 g 9 c 3 10 g 6
*/
