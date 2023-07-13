#include "Pile.h"

Pile::Pile() : DoubleLinkedList() {

}

bool Pile::DeleteElement() {
	Node* save = actual;
	actual = GetEndNode();
	DeleteActual();
	actual = save;
	return true;
}