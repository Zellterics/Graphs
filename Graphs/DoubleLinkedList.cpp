#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() : Graph() {

}

bool DoubleLinkedList::AddElement(int content) {
	if (actual == nullptr) {
		AddNode(content);
		return true;
	}
	AddNode(content);
	move = GetEndNode();
	move->ConectToNodeID(1, actual->GetID(), 2);
	actual->ConectToNodeID(1, move->GetID(), 1);
	return true;
}

bool DoubleLinkedList::AddNextToActual(int content) {
	if (actual == nullptr) {
		AddNode(content);
		return true;
	}
	if (actual == GetEndNode()) {
		AddElement(content);
		return true;
	}
	Node* save = actual;
	AddNode(content);
	move = GetNodeWithID(save->GetNodeIDWithExtraUtilitys(2));
	move->DeleteConectionToNodeID(save->GetID());
	move->ConectToNodeID(1, actual->GetID(), 1);
	actual->ConectToNodeID(1, move->GetID(), 2);
	save->DeleteConectionToNodeID(actual->GetNodeIDWithExtraUtilitys(2));
	save->ConectToNodeID(1, actual->GetID(), 2);
	actual->ConectToNodeID(1, save->GetID(), 1);
	return true;
}

bool DoubleLinkedList::DeleteActual() {
	if (actual == nullptr) {
		//std::cout << "ERROR: There's No Actual";
		return false;
	}
	if (GetNodeWithID(actual->GetNodeIDWithExtraUtilitys(1)) == nullptr) {
		Graph::DeleteActual();
		return true;
	}
	if (GetNodeWithID(actual->GetNodeIDWithExtraUtilitys(2)) == nullptr) {
		Graph::DeleteActual();
		return true;
	}
	GetNodeWithID(actual->GetNodeIDWithExtraUtilitys(1))->DeleteConectionToNodeID(actual->GetID());
	GetNodeWithID(actual->GetNodeIDWithExtraUtilitys(1))->ConectToNodeID(1, actual->GetNodeIDWithExtraUtilitys(2), 2);
	GetNodeWithID(actual->GetNodeIDWithExtraUtilitys(2))->DeleteConectionToNodeID(actual->GetID());
	GetNodeWithID(actual->GetNodeIDWithExtraUtilitys(2))->ConectToNodeID(1, actual->GetNodeIDWithExtraUtilitys(1), 1);
	Graph::DeleteActual();
	return true;
}

Node* DoubleLinkedList::GetEndNode() {
	if (start == nullptr) {
		return nullptr;
	}
	move = start;
	while (move != nullptr) {
		if (move->GetNodeIDWithExtraUtilitys(2) == -1) {
			return move;
		}
		move = move->GetNext();
	}
	return nullptr;
}

Node* DoubleLinkedList::GetStartNode() {
	if (start == nullptr) {
		return nullptr;
	}
	move = start;
	while (move != nullptr) {
		if (move->GetNodeIDWithExtraUtilitys(1) == -1) {
			return move;
		}
		move = move->GetNext();
	}
	return nullptr;
}