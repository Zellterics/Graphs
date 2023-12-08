#include "Queue.h"

Queue::Queue() : LinkedList() {

}

Node Queue::DeQueue() {
	if (start == nullptr) {
		AddElement(0);
	}
	Node Save(start->GetContent(), nullptr);
	Save.SetData(start->GetData());
	actual = start;
	DeleteActual();
	actual = start;
	return Save;
}

bool Queue::InQueue(int content) {
	return AddElement(content);
}

