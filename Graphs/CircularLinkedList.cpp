#include "CircularLinkedList.h"

CircularLinkedList::CircularLinkedList() : LinkedList() {

}

bool CircularLinkedList::AddElement(int content) {
	if (start == nullptr) {
		AddNode(content);
		return true;
	}
	if (CountNodes() == 1) {
		Node* save = actual;
		AddNode(content);
		DualConectToNodeID(1, save->GetID());
		return true;
	}
	Node* save = actual;
	AddNode(content);
	actual->ConectToNodeID(1, save->GetNodeIDOnListPosition(1));
	save->DeleteConectionToNodeID(save->GetNodeIDOnListPosition(1));
	save->ConectToNodeID(1, actual->GetID());
	return true;
}