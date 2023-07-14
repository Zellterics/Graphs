#include "Pile.h"

Pile::Pile() : DoubleLinkedList() {

}

bool Pile::DeleteElement() {
	Node* save = actual;
	actual = GetEndNode();
	DeleteActual();
	if (save == nullptr) {
		actual = start;
	}
	actual = save;
	return true;
}