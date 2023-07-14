#include "Queue.h"

Queue::Queue() : DoubleLinkedList() {

}

bool Queue::DeleteElement() {
	Node* save = actual;
	actual = GetStartNode();
	DeleteActual();
	if (save == nullptr) {
		actual = start;
	}
	actual = save;
	return true;
}