#include "CircularDoubleLinkedList.h"

CircularDoubleLinkedList::CircularDoubleLinkedList() : DoubleLinkedList(){

}

bool CircularDoubleLinkedList::AddElement(int content) {
	if (actual == nullptr) {
		AddNode(content);
		return true;
	}
	if (CountNodes() == 1) {
		Node* save = start;
		AddNode(content);
		save->ConectToNodeID(1, actual->GetID(), 2);
		actual->ConectToNodeID(1, save->GetID(), 1);
		return true;
	}
	if (CountNodes() == 2) {
		Node* save1 = start;
		Node* save2 = start->GetNext();
		AddNode(content);
		save2->ConectToNodeID(1, actual->GetID(), 2);
		actual->ConectToNodeID(1, save2->GetID(), 1);
		actual->ConectToNodeID(1, save1->GetID(), 2);
		save1->ConectToNodeID(1, actual->GetID(), 1);
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

Node* CircularDoubleLinkedList::GetEndNode() {
	if (start == nullptr) {
		return nullptr;
	}
	if (CountNodes() == 1) {
		return start;
	}
	if (CountNodes() == 2) {
		return GetNodeWithID(start->GetNodeIDOnListPosition(1));
	}
	return GetNodeWithID(start->GetNodeIDWithExtraUtilitys(1));
}