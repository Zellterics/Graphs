#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() : LinkedList() {

}

bool DoubleLinkedList::AddElement(int content) {
	LinkedList::AddElement(content);
	if (actual->GetPast() != nullptr) {
		actual->ConectToNodeID(1, actual->GetPast()->GetID());
	}
	return true;
}

bool DoubleLinkedList::DeleteActual() {
	if (actual->GetPast() == nullptr) {
		Graph::DeleteActual();
		return true;
	}
	if (actual->GetNext() == nullptr) {
		Graph::DeleteActual();
		return true;
	}
	actual->GetPast()->ConectToNodeID(1, actual->GetNext()->GetID());
	actual->GetNext()->ConectToNodeID(1, actual->GetPast()->GetID());
	Graph::DeleteActual();
}