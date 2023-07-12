#include "LinkedList.h"

LinkedList::LinkedList() : Graph() {
	
}

bool LinkedList::AddElement(int content) {
	AddNode(content);
	if (actual->GetPast() == nullptr) {
		return true;
	}
	actual->GetPast()->ConectToNodeID(1, actual->GetID());
	return true;
}

bool LinkedList::DeleteActual() {
	if (actual->GetPast() == nullptr) {
		Graph::DeleteActual();
		return true;
	}
	if (actual->GetNext() == nullptr) {
		Graph::DeleteActual();
		return true;
	}
	actual->GetPast()->ConectToNodeID(1, actual->GetNext()->GetID());
	Graph::DeleteActual();
}