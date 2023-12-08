#include "Menus.h"

Menus::Menus(Pile* pile) {
	int content, NodeID;
	bool stop = false;
	std::string input;
	char filteredInput;
	input = 'f';
	while (!stop) {
		filteredInput = input[0];
		switch (filteredInput) {
		case 'f': case 'F':
			std::cout << "---FUNCTIONS    ---\n";
			std::cout << "---AddElement   ---\n";
			std::cout << "---Print        ---\n";
			std::cout << "---Everything   ---\n";
			std::cout << "---Delete       ---\n";
			std::cout << "---ModifyContent---\n";
			std::cout << "---HowManyNodes ---\n";
			std::cout << "---Terminate    ---\n";
			break;
		case 'a': case 'A':
			std::cout << "--->Node content:";
			std::cin >> content;
			content = CinFail(content);
			pile->AddElement(content);
			PrintActual(pile);
			break;
		case 'g': case 'G':
			std::cout << "--->NodeID:";
			std::cin >> NodeID;
			NodeID = CinFail(NodeID);
			if (!pile->GoToNodeID(NodeID)) {
				std::cout << "--->ERROR: No Such NodeID\n";
			}
			PrintActual(pile);
			break;
		case 'p': case 'P':
			PrintActual(pile);
			break;
		case 'e': case 'E':
			PrintEverything(pile);
			break;
		case 't': case 'T':
			stop = true;
			break;
		case 'd': case 'D':
			pile->DeleteElement();
			break;
		case 'm': case 'M':
			std::cout << "--->Node content:";
			std::cin >> content;
			content = CinFail(content);
			pile->ChangeActualNodeContent(content);
			PrintActual(pile);
			break;
		case 'h': case 'H':
			std::cout << "There are " << pile->CountNodes() << " Nodes\n";
			break;
		default:
			std::cout << "That's Not An Option" << std::endl;
			break;
		}
		std::cout << "\n--->";
		std::cin >> input;
	}
}

Menus::Menus(Queue* queue) {
	bool stop = false;
	Node save(0, nullptr);
	Data* data;
	std::string input;
	char filteredInput;
	input = 'f';
	while (!stop) {
		filteredInput = input[0];
		switch (filteredInput) {
		case 'f': case 'F':
			std::cout << "---FUNCTIONS    ---\n";
			std::cout << "---AddElement   ---\n";
			std::cout << "---Get          ---\n";
			std::cout << "---Count        ---\n";
			std::cout << "---Void         ---\n";
			std::cout << "---Erase        ---\n";
			break;
		case 'a': case 'A':
			queue->InQueue(0);
			if (queue->GetActualNode()->GetData() == nullptr) {
				data = new Data;
				queue->GetActualNode()->SetData(data);
			}
			else {
				data = static_cast<Data*>(queue->GetActualNode()->GetData());
			}
			std::cout << "--->Name:";
			std::cin >> data->name;
			data->name = CinFail(data->name);
			std::cout << "--->LastName:";
			std::cin >> data->lastName;
			data->lastName = CinFail(data->lastName);
			std::cout << "--->Age:";
			std::cin >> data->age;
			data->age = CinFail(data->age);
			std::cout << "--->reg:";
			std::cin >> data->reg;
			data->reg = CinFail(data->reg);
			break;
		case 'g': case 'G': 
			save = queue->DeQueue();
			if (save.GetData() == nullptr) {
				std::cout << "ERROR: Empty";
				break;
			}
			std::cout << "Name:     " << ((Data*)save.GetData())->name << std::endl;
			std::cout << "LastName: " << ((Data*)save.GetData())->lastName << std::endl;
			std::cout << "Age:      " << ((Data*)save.GetData())->age << std::endl;
			std::cout << "Reg:      " << ((Data*)save.GetData())->reg << std::endl;
			break; 
		case 'c': case 'C':
			std::cout << "There are " << queue->CountNodes() << " Nodes\n";
			break;
		case 'v': case 'V':
			if (queue->start != nullptr) {
				std::cout << "hay datos\n";
			}
			else {
				std::cout << "no hay datos\n";
			}
			break;
		case 'e': case 'E':
			while (queue->actual != nullptr) {
				queue->DeleteActual();
			}
			break;
		default:
			std::cout << "That's Not An Option" << std::endl;
			break;
		}
		std::cout << "\n--->";
		std::cin >> input;
	}
}

Menus::Menus(Graph* graph) {
	int content, NodeID;
	bool stop = false;
	std::string input;
	char filteredInput;
	input = 'f';
	while (!stop) {
		filteredInput = input[0];
		switch (filteredInput) {
		case 'f': case 'F':
			std::cout << "---FUNCTIONS    ---\n";
			std::cout << "---AddNode      ---\n";
			std::cout << "---ConectWith   ---\n";
			std::cout << "---GoTo         ---\n";
			std::cout << "---SlideTo      ---\n";
			std::cout << "---NodeSearch   ---\n";
			std::cout << "---WholeSearch  ---\n";
			std::cout << "---Print        ---\n";
			std::cout << "---Everything   ---\n";
			std::cout << "---BorderNodes  ---\n";
			std::cout << "---DeleteActual ---\n";
			std::cout << "---ModifyContent---\n";
			std::cout << "---HowManyNodes ---\n";
			std::cout << "---Terminate    ---\n";
			break;
		case 'a': case 'A':
			std::cout << "--->Node content:";
			std::cin >> content;
			content = CinFail(content);
			graph->AddNode(content);
			PrintActual(graph);
			break;
		case 'c': case 'C':
			std::cout << "--->Conection content:";
			std::cin >> content;
			content = CinFail(content);
			std::cout << "\n--->Conection NodeID:";
			std::cin >> NodeID;
			NodeID = CinFail(NodeID);
			graph->ConectToNodeID(content, NodeID);
			PrintActual(graph);
			std::cout << "--(" << content << ")-->";
			PrintWithNodeID(graph, NodeID);
			break;
		case 'g': case 'G':
			std::cout << "--->NodeID:";
			std::cin >> NodeID;
			NodeID = CinFail(NodeID);
			if (!graph->GoToNodeID(NodeID)) {
				std::cout << "--->ERROR: No Such NodeID\n";
			}
			PrintActual(graph);
			break;
		case 's': case 'S':
			std::cout << "--->NodeID:";
			std::cin >> NodeID;
			NodeID = CinFail(NodeID);
			if (!graph->MoveToNodeID(NodeID)) {
				std::cout << "--->ERROR: Not Such NodeID Conection\n";
			}
			PrintActual(graph);
			break;
		case 'p': case 'P':
			PrintActual(graph);
			break;
		case 'e': case 'E':
			PrintEverything(graph);
			break;
		case 'n': case 'N': {
			std::cout << "--->NodeID:";
			std::cin >> NodeID;
			NodeID = CinFail(NodeID);
			if (graph->GetNodeWithID(NodeID) == nullptr) {
				std::cout << "--->ERROR: Not Such NodeID Conection\n";
				PrintActual(graph);
				continue;
			}
			ConectionsList temp = graph->PathFindingToNodeID(NodeID);
			Conection* move = temp.GetStart();
			while (move != nullptr) {
				std::cout << "\n";
				std::cout << "--(" << move->GetValue() << ", ID:" << move->GetID() << ")-->NodeID[" << move->GetNodeID() << "]";
				move = move->GetNext();
			}
			break; }
		case 'w': case 'W':
			PathFindingToAll(graph);
			break;
		case 't': case 'T':
			stop = true;
			break;
		case 'b': case 'B': {
			ConectionsList* erase = graph->GetActualConections();
			if (erase->GetConectionOnListPosition(0) == -1) {
				delete erase;
			}
			else {
				Conection* move = erase->GetStart();
				while (move != nullptr) {
					std::cout << "\n";
					std::cout << "--(" << move->GetValue() << ", ID:" << move->GetID() << ")-->NodeID[" << move->GetNodeID() << "]";
					move = move->GetNext();
				}
			}}
			break;
		case 'd': case 'D':
			graph->DeleteActual();
			break;
		case 'm': case 'M':
			std::cout << "--->Node content:";
			std::cin >> content;
			content = CinFail(content);
			graph->ChangeActualNodeContent(content);
			PrintActual(graph);
			break;
		case 'h': case 'H':
			std::cout << "There are " << graph->CountNodes() << " Nodes\n";
			break;
		default:
			std::cout << "That's Not An Option" << std::endl;
			break;
		}
		std::cout << "\n--->";
		std::cin >> input;
	}
}


Menus::Menus(LinkedList* linkedList) {
	Data* data = nullptr;
	int content, NodeID;
	bool stop = false, moreStoredData = false;
	std::string input;
	char filteredInput;
	Data dat;
	input = 'f';
	while (!stop) {
		filteredInput = input[0];
		switch (filteredInput) {
		case 'f': case 'F':
			std::cout << "---FUNCTIONS    ---\n";
			std::cout << "---Add          ---\n";
			std::cout << "---Search       ---\n";
			std::cout << "---Delete       ---\n";
			std::cout << "---Modify       ---\n";
			std::cout << "---Count        ---\n";
			std::cout << "---Everything   ---\n";
			std::cout << "---Iterator     ---\n";
			std::cout << "---Wfirst       ---\n";
			std::cout << "---Last         ---\n";
			std::cout << "---Next         ---\n";
			std::cout << "---Prev         ---\n";
			std::cout << "---GetItem      ---\n";
			break;
		case 'a': case 'A':
			linkedList->AddElement(0);
			if (linkedList->GetActualNode()->GetData() == nullptr) {
				data = new Data;
				linkedList->GetActualNode()->SetData(data);
			}
			else {
				data = static_cast<Data*>(linkedList->GetActualNode()->GetData());
			}
			std::cout << "--->Name:";
			std::cin >> data->name;
			data->name = CinFail(data->name);
			std::cout << "--->LastName:";
			std::cin >> data->lastName;
			data->lastName = CinFail(data->lastName);
			std::cout << "--->Age:";
			std::cin >> data->age;
			data->age = CinFail(data->age);
			std::cout << "--->reg:";
			std::cin >> data->reg;
			data->reg = CinFail(data->reg);
			PrintActual(linkedList);
			break;
		case 's': case 'S':
			if (linkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			moreStoredData = false;
			std::cout << "Name/Reg?: 0/1: ";
			std::cin >> content;
			content = CinFail(content);
			if (content != 0 && content != 1) {
				std::cout << "ERROR: Invalid content\n";
				break;
			}
			if (content == 0) {
				std::cout << "--->Name:";
				std::cin >> dat.name;
				dat.name = CinFail(dat.name);
				linkedList->move = linkedList->start;
				while (linkedList->move != nullptr) {
					if (((Data*)linkedList->move->GetData())->name == dat.name) {
						PrintWithNodeID(linkedList, linkedList->move->GetID());
						moreStoredData = true;
					}
					linkedList->move = linkedList->move->GetNext();
				}
				if (moreStoredData == false) {
					std::cout << "ERROR: Not Found";
				}
				break;
			}
			std::cout << "--->reg:";
			std::cin >> dat.reg;
			dat.reg = CinFail(dat.reg);
			linkedList->move = linkedList->start;
			while (linkedList->move != nullptr) {
				if (((Data*)linkedList->move->GetData())->reg == dat.reg) {
					PrintWithNodeID(linkedList, linkedList->move->GetID());
					moreStoredData = true;
				}
				linkedList->move = linkedList->move->GetNext();
			}
			if (moreStoredData == false) {
				std::cout << "ERROR: Not Found";
			}
			break;
		case 'd': case 'D':
			if (linkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			std::cout << "--->reg:";
			std::cin >> dat.reg;
			dat.reg = CinFail(dat.reg);
			linkedList->move = linkedList->start;
			while (linkedList->move != nullptr) {
				if (((Data*)linkedList->move->GetData())->reg == dat.reg) {
					linkedList->actual = linkedList->move;
					linkedList->DeleteActual();
					moreStoredData = true;
					linkedList->actual = linkedList->start;
					linkedList->move = linkedList->start;
					if (linkedList->move == nullptr) {
						break;
					}
				}
				linkedList->move = linkedList->move->GetNext();
			}
			if (moreStoredData == false) {
				std::cout << "ERROR: Not Found";
			}
			break;
		case 'm': case 'M':
			if (linkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			std::cout << "--->reg:";
			std::cin >> dat.reg;
			dat.reg = CinFail(dat.reg);
			linkedList->move = linkedList->start;
			while (linkedList->move != nullptr) {
				if (((Data*)linkedList->move->GetData())->reg == dat.reg) {
					linkedList->actual = linkedList->move;
					if (linkedList->GetActualNode()->GetData() == nullptr) {
						data = new Data;
						linkedList->GetActualNode()->SetData(data);
					}
					else {
						data = static_cast<Data*>(linkedList->GetActualNode()->GetData());
					}
					std::cout << "--->Name:";
					std::cin >> data->name;
					data->name = CinFail(data->name);
					std::cout << "--->LastName:";
					std::cin >> data->lastName;
					data->lastName = CinFail(data->lastName);
					std::cout << "--->Age:";
					std::cin >> data->age;
					data->age = CinFail(data->age);
					std::cout << "--->reg:";
					std::cin >> data->reg;
					data->reg = CinFail(data->reg);

					linkedList->SetActualData(data);
					moreStoredData = true;
					linkedList->actual = linkedList->start;
					linkedList->move = linkedList->start;
					if (linkedList->move == nullptr) {
						break;
					}
				}
				linkedList->move = linkedList->move->GetNext();
			}
			if (moreStoredData == false) {
				std::cout << "ERROR: Not Found";
			}
			break;
		case 'c': case 'C':
			if (linkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			std::cout << "There are " << linkedList->CountNodes() << " Nodes\n";
			break;
		case 'i': case 'I':
			if (linkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			PrintActual(linkedList);
			break;
		case 'w': case 'W':
			if (linkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			linkedList->actual = linkedList->start;
			PrintActual(linkedList);
			break;
		case 'l': case 'L':
			if (linkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			linkedList->actual = linkedList->end;
			PrintActual(linkedList);
			break;
		case 'n': case 'N':
			if (linkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			if (linkedList->actual == linkedList->end) {
				std::cout << "ERROR: Already On End\n";
				break;
			}
			if (linkedList->CountNodes() == 2) {
				if (linkedList->start == linkedList->actual) {
					linkedList->actual = linkedList->start;
				}
				break;
			}
			linkedList->MoveToNodeID(linkedList->actual->GetNodeIDOnListPosition(1));
			PrintActual(linkedList);
			break;
		case 'p': case 'P':
			if (linkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			if (linkedList->actual == linkedList->start) {
				std::cout << "ERROR: Already On Start\n";
				break;
			}
			if (linkedList->CountNodes() == 2) {
				linkedList->GoToNodeID(linkedList->GetPastOfNode(linkedList->actual)->GetID());
				break;
			}
			linkedList->GoToNodeID(linkedList->GetPastOfNode(linkedList->actual)->GetID());
			PrintActual(linkedList);
			break;
		case 'g': case 'G': {
			Node* save = linkedList->actual;
			std::cout << "Name:     " << ((Data*)save->GetData())->name << std::endl;
			std::cout << "LastName: " << ((Data*)save->GetData())->lastName << std::endl;
			std::cout << "Age:      " << ((Data*)save->GetData())->age << std::endl;
			std::cout << "Reg:      " << ((Data*)save->GetData())->reg << std::endl;
			break; }
		case 'e': case 'E':
			PrintEverything(linkedList);
			std::cout << "\n\nactual = " << linkedList->actual << " next = " << linkedList->GetNodeWithID(linkedList->actual->GetNodeIDWithExtraUtilitys(2));

		}
		std::cout << "\n--->";
		std::cin >> input;
	}
}

Menus::Menus(DoubleLinkedList* doubleLinkedList) {
	Data* data = nullptr;
	int content, NodeID;
	bool stop = false, moreStoredData = false;
	std::string input;
	char filteredInput;
	Data dat;
	input = 'f';
	while (!stop) {
		filteredInput = input[0];
		switch (filteredInput) {
		case 'f': case 'F':
			std::cout << "---FUNCTIONS    ---\n";
			std::cout << "---Add          ---\n";
			std::cout << "---Search       ---\n";
			std::cout << "---Delete       ---\n";
			std::cout << "---Modify       ---\n";
			std::cout << "---Count        ---\n";
			std::cout << "---Everything   ---\n";
			std::cout << "---Iterator     ---\n";
			std::cout << "---Wfirst       ---\n";
			std::cout << "---Last         ---\n";
			std::cout << "---Next         ---\n";
			std::cout << "---Prev         ---\n";
			std::cout << "---GetItem      ---\n";
			break;
		case 'a': case 'A':
			doubleLinkedList->AddElement(0);
			if (doubleLinkedList->GetActualNode()->GetData() == nullptr) {
				data = new Data;
				doubleLinkedList->GetActualNode()->SetData(data);
			}
			else {
				data = static_cast<Data*>(doubleLinkedList->GetActualNode()->GetData());
			}
			std::cout << "--->Name:";
			std::cin >> data->name;
			data->name = CinFail(data->name);
			std::cout << "--->LastName:";
			std::cin >> data->lastName;
			data->lastName = CinFail(data->lastName);
			std::cout << "--->Age:";
			std::cin >> data->age;
			data->age = CinFail(data->age);
			std::cout << "--->reg:";
			std::cin >> data->reg;
			data->reg = CinFail(data->reg);
			PrintActual(doubleLinkedList);
			break;
		case 's': case 'S':
			if (doubleLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			moreStoredData = false;
			std::cout << "Name/Reg?: 0/1: ";
			std::cin >> content;
			content = CinFail(content);
			if (content != 0 && content != 1) {
				std::cout << "ERROR: Invalid content\n";
				break;
			}
			if (content == 0) {
				std::cout << "--->Name:";
				std::cin >> dat.name;
				dat.name = CinFail(dat.name);
				doubleLinkedList->move = doubleLinkedList->start;
				while (doubleLinkedList->move != nullptr) {
					if (((Data*)doubleLinkedList->move->GetData())->name == dat.name) {
						PrintWithNodeID(doubleLinkedList, doubleLinkedList->move->GetID());
						moreStoredData = true;
					}
					doubleLinkedList->move = doubleLinkedList->move->GetNext();
				}
				if (moreStoredData == false) {
					std::cout << "ERROR: Not Found";
				}
				break;
			}
			std::cout << "--->reg:";
			std::cin >> dat.reg;
			dat.reg = CinFail(dat.reg);
			doubleLinkedList->move = doubleLinkedList->start;
			while (doubleLinkedList->move != nullptr) {
				if (((Data*)doubleLinkedList->move->GetData())->reg == dat.reg) {
					PrintWithNodeID(doubleLinkedList, doubleLinkedList->move->GetID());
					moreStoredData = true;
				}
				doubleLinkedList->move = doubleLinkedList->move->GetNext();
			}
			if (moreStoredData == false) {
				std::cout << "ERROR: Not Found";
			}
			break;
		case 'd': case 'D':
			if (doubleLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			std::cout << "--->reg:";
			std::cin >> dat.reg;
			dat.reg = CinFail(dat.reg);
			doubleLinkedList->move = doubleLinkedList->start;
			while (doubleLinkedList->move != nullptr) {
				if (((Data*)doubleLinkedList->move->GetData())->reg == dat.reg) {
					doubleLinkedList->actual = doubleLinkedList->move;
					//data = (Data*)doubleLinkedList->actual->GetData();
					//delete data;
					doubleLinkedList->DeleteActual();
					moreStoredData = true;
					doubleLinkedList->actual = doubleLinkedList->start;
					doubleLinkedList->move = doubleLinkedList->start;
					if (doubleLinkedList->move == nullptr) {
						break;
					}
				}
				doubleLinkedList->move = doubleLinkedList->move->GetNext();
			}
			if (moreStoredData == false) {
				std::cout << "ERROR: Not Found";
			}
			break;
		case 'm': case 'M':
			if (doubleLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			std::cout << "--->reg:";
			std::cin >> dat.reg;
			dat.reg = CinFail(dat.reg);
			doubleLinkedList->move = doubleLinkedList->start;
			while (doubleLinkedList->move != nullptr) {
				if (((Data*)doubleLinkedList->move->GetData())->reg == dat.reg) {
					doubleLinkedList->actual = doubleLinkedList->move;
					if (doubleLinkedList->GetActualNode()->GetData() == nullptr) {
						data = new Data;
						doubleLinkedList->GetActualNode()->SetData(data);
					}
					else {
						data = static_cast<Data*>(doubleLinkedList->GetActualNode()->GetData());
					}
					std::cout << "--->Name:";
					std::cin >> data->name;
					data->name = CinFail(data->name);
					std::cout << "--->LastName:";
					std::cin >> data->lastName;
					data->lastName = CinFail(data->lastName);
					std::cout << "--->Age:";
					std::cin >> data->age;
					data->age = CinFail(data->age);
					std::cout << "--->reg:";
					std::cin >> data->reg;
					data->reg = CinFail(data->reg);

					doubleLinkedList->SetActualData(data);
					moreStoredData = true;
					doubleLinkedList->actual = doubleLinkedList->start;
					doubleLinkedList->move = doubleLinkedList->start;
					if (doubleLinkedList->move == nullptr) {
						break;
					}
				}
				doubleLinkedList->move = doubleLinkedList->move->GetNext();
			}
			if (moreStoredData == false) {
				std::cout << "ERROR: Not Found";
			}
			break;
		case 'c': case 'C':
			if (doubleLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			std::cout << "There are " << doubleLinkedList->CountNodes() << " Nodes\n";
			break;
		case 'i': case 'I':
			if (doubleLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			PrintActual(doubleLinkedList);
			break;
		case 'w': case 'W':
			if (doubleLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			doubleLinkedList->actual = doubleLinkedList->start;
			PrintActual(doubleLinkedList);
			break;
		case 'l': case 'L':
			if (doubleLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			doubleLinkedList->actual = doubleLinkedList->end;
			PrintActual(doubleLinkedList);
			break;
		case 'n': case 'N':
			if (doubleLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			if (doubleLinkedList->actual == doubleLinkedList->end) {
				std::cout << "ERROR: Already On End\n";
				break;
			}
			if (doubleLinkedList->CountNodes() == 2) {
				if (doubleLinkedList->start == doubleLinkedList->actual) {
					doubleLinkedList->actual = doubleLinkedList->start;
				}
				break;
			}
			doubleLinkedList->MoveToNodeID(doubleLinkedList->actual->GetNodeIDWithExtraUtilitys(2));
			PrintActual(doubleLinkedList);
			break;
		case 'p': case 'P':
			if (doubleLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			if (doubleLinkedList->actual == doubleLinkedList->start) {
				std::cout << "ERROR: Already On Start\n";
				break;
			}
			if (doubleLinkedList->CountNodes() == 2) {
				doubleLinkedList->actual = doubleLinkedList->GetNodeWithID(doubleLinkedList->actual->GetNodeIDOnListPosition(1));
				break;
			}
			doubleLinkedList->MoveToNodeID(doubleLinkedList->actual->GetNodeIDWithExtraUtilitys(1));
			PrintActual(doubleLinkedList);
			break;
		case 'g': case 'G': {
			Node* save = doubleLinkedList->actual;
			std::cout << "Name:     " << ((Data*)save->GetData())->name << std::endl;
			std::cout << "LastName: " << ((Data*)save->GetData())->lastName << std::endl;
			std::cout << "Age:      " << ((Data*)save->GetData())->age << std::endl;
			std::cout << "Reg:      " << ((Data*)save->GetData())->reg << std::endl;
			break; }
		case 'e': case 'E':
			PrintEverything(doubleLinkedList);
			std::cout << "\n\nactual = " << doubleLinkedList->actual << " next = " << doubleLinkedList->GetNodeWithID(doubleLinkedList->actual->GetNodeIDWithExtraUtilitys(2));

		}
		std::cout << "\n--->";
		std::cin >> input;
	}
}


Menus::Menus(CircularLinkedList* circularLinkedList) {
	Data* data = nullptr;
	int content, NodeID;
	bool stop = false, moreStoredData = false;
	std::string input;
	char filteredInput;
	Data dat;
	input = 'f';
	while (!stop) {
		filteredInput = input[0];
		switch (filteredInput) {
		case 'f': case 'F':
			std::cout << "---FUNCTIONS    ---\n";
			std::cout << "---Add          ---\n";
			std::cout << "---Search       ---\n";
			std::cout << "---Delete       ---\n";
			std::cout << "---Modify       ---\n";
			std::cout << "---Count        ---\n";
			std::cout << "---Everything   ---\n";
			std::cout << "---Iterator     ---\n";
			std::cout << "---Wfirst       ---\n";
			std::cout << "---Last         ---\n";
			std::cout << "---Next         ---\n";
			std::cout << "---Prev         ---\n";
			std::cout << "---GetItem      ---\n";
			break;
		case 'a': case 'A':
			circularLinkedList->AddElement(0);
			if (circularLinkedList->GetActualNode()->GetData() == nullptr) {
				data = new Data;
				circularLinkedList->GetActualNode()->SetData(data);
			}
			else {
				data = static_cast<Data*>(circularLinkedList->GetActualNode()->GetData());
			}
			std::cout << "--->Name:";
			std::cin >> data->name;
			data->name = CinFail(data->name);
			std::cout << "--->LastName:";
			std::cin >> data->lastName;
			data->lastName = CinFail(data->lastName);
			std::cout << "--->Age:";
			std::cin >> data->age;
			data->age = CinFail(data->age);
			std::cout << "--->reg:";
			std::cin >> data->reg;
			data->reg = CinFail(data->reg);
			PrintActual(circularLinkedList);
			break;
		case 's': case 'S':
			if (circularLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			moreStoredData = false;
			std::cout << "Name/Reg?: 0/1: ";
			std::cin >> content;
			content = CinFail(content);
			if (content != 0 && content != 1) {
				std::cout << "ERROR: Invalid content\n";
				break;
			}
			if (content == 0) {
				std::cout << "--->Name:";
				std::cin >> dat.name;
				dat.name = CinFail(dat.name);
				circularLinkedList->move = circularLinkedList->start;
				while (circularLinkedList->move != nullptr) {
					if (((Data*)circularLinkedList->move->GetData())->name == dat.name) {
						PrintWithNodeID(circularLinkedList, circularLinkedList->move->GetID());
						moreStoredData = true;
					}
					circularLinkedList->move = circularLinkedList->move->GetNext();
				}
				if (moreStoredData == false) {
					std::cout << "ERROR: Not Found";
				}
				break;
			}
			std::cout << "--->reg:";
			std::cin >> dat.reg;
			dat.reg = CinFail(dat.reg);
			circularLinkedList->move = circularLinkedList->start;
			while (circularLinkedList->move != nullptr) {
				if (((Data*)circularLinkedList->move->GetData())->reg == dat.reg) {
					PrintWithNodeID(circularLinkedList, circularLinkedList->move->GetID());
					moreStoredData = true;
				}
				circularLinkedList->move = circularLinkedList->move->GetNext();
			}
			if (moreStoredData == false) {
				std::cout << "ERROR: Not Found";
			}
			break;
		case 'd': case 'D':
			if (circularLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			std::cout << "--->reg:";
			std::cin >> dat.reg;
			dat.reg = CinFail(dat.reg);
			circularLinkedList->move = circularLinkedList->start;
			while (circularLinkedList->move != nullptr) {
				if (((Data*)circularLinkedList->move->GetData())->reg == dat.reg) {
					circularLinkedList->actual = circularLinkedList->move;
					circularLinkedList->DeleteActual();
					moreStoredData = true;
					circularLinkedList->actual = circularLinkedList->start;
					circularLinkedList->move = circularLinkedList->start;
					if (circularLinkedList->move == nullptr) {
						break;
					}
				}
				circularLinkedList->move = circularLinkedList->move->GetNext();
			}
			if (moreStoredData == false) {
				std::cout << "ERROR: Not Found";
			}
			break;
		case 'm': case 'M':
			if (circularLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			std::cout << "--->reg:";
			std::cin >> dat.reg;
			dat.reg = CinFail(dat.reg);
			circularLinkedList->move = circularLinkedList->start;
			while (circularLinkedList->move != nullptr) {
				if (((Data*)circularLinkedList->move->GetData())->reg == dat.reg) {
					circularLinkedList->actual = circularLinkedList->move;
					if (circularLinkedList->GetActualNode()->GetData() == nullptr) {
						data = new Data;
						circularLinkedList->GetActualNode()->SetData(data);
					}
					else {
						data = static_cast<Data*>(circularLinkedList->GetActualNode()->GetData());
					}
					std::cout << "--->Name:";
					std::cin >> data->name;
					data->name = CinFail(data->name);
					std::cout << "--->LastName:";
					std::cin >> data->lastName;
					data->lastName = CinFail(data->lastName);
					std::cout << "--->Age:";
					std::cin >> data->age;
					data->age = CinFail(data->age);
					std::cout << "--->reg:";
					std::cin >> data->reg;
					data->reg = CinFail(data->reg);

					circularLinkedList->SetActualData(data);
					moreStoredData = true;
					circularLinkedList->actual = circularLinkedList->start;
					circularLinkedList->move = circularLinkedList->start;
					if (circularLinkedList->move == nullptr) {
						break;
					}
				}
				circularLinkedList->move = circularLinkedList->move->GetNext();
			}
			if (moreStoredData == false) {
				std::cout << "ERROR: Not Found";
			}
			break;
		case 'c': case 'C':
			if (circularLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			std::cout << "There are " << circularLinkedList->CountNodes() << " Nodes\n";
			break;
		case 'i': case 'I':
			if (circularLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			PrintActual(circularLinkedList);
			break;
		case 'w': case 'W':
			if (circularLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			circularLinkedList->actual = circularLinkedList->start;
			PrintActual(circularLinkedList);
			break;
		case 'l': case 'L':
			if (circularLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			circularLinkedList->actual = circularLinkedList->end;
			PrintActual(circularLinkedList);
			break;
		case 'n': case 'N':
			if (circularLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			if (circularLinkedList->CountNodes() == 2) {
				circularLinkedList->actual = circularLinkedList->GetNodeWithID(circularLinkedList->actual->GetNodeIDOnListPosition(1));
				break;
			}
			circularLinkedList->MoveToNodeID(circularLinkedList->actual->GetNodeIDOnListPosition(1));
			PrintActual(circularLinkedList);
			break;
		case 'p': case 'P':
			if (circularLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			if (circularLinkedList->CountNodes() == 2) {
				if (circularLinkedList->start != circularLinkedList->actual) {
					circularLinkedList->actual = circularLinkedList->start;
				}
				circularLinkedList->actual = circularLinkedList->GetNodeWithID(circularLinkedList->actual->GetNodeIDOnListPosition(1));
				break;
			}
			circularLinkedList->actual = circularLinkedList->GetPastOfNode(circularLinkedList->actual);
			PrintActual(circularLinkedList);
			break;
		case 'g': case 'G': {
			Node* save = circularLinkedList->actual;
			std::cout << "Name:     " << ((Data*)save->GetData())->name << std::endl;
			std::cout << "LastName: " << ((Data*)save->GetData())->lastName << std::endl;
			std::cout << "Age:      " << ((Data*)save->GetData())->age << std::endl;
			std::cout << "Reg:      " << ((Data*)save->GetData())->reg << std::endl;
			break; }
		case 'e': case 'E':
			PrintEverything(circularLinkedList);
			std::cout << "\n\nactual = " << circularLinkedList->actual << " next = " << circularLinkedList->GetNodeWithID(circularLinkedList->actual->GetNodeIDWithExtraUtilitys(2));

		}
		std::cout << "\n--->";
		std::cin >> input;
	}
}

Menus::Menus(CircularDoubleLinkedList* circularDoubleLinkedList) {
	Data* data = nullptr;
	int content, NodeID;
	bool stop = false, moreStoredData = false;
	std::string input;
	char filteredInput;
	Data dat;
	input = 'f';
	while (!stop) {
		filteredInput = input[0];
		switch (filteredInput) {
		case 'f': case 'F':
			std::cout << "---FUNCTIONS    ---\n";
			std::cout << "---Add          ---\n";
			std::cout << "---Search       ---\n";
			std::cout << "---Delete       ---\n";
			std::cout << "---Modify       ---\n";
			std::cout << "---Count        ---\n";
			std::cout << "---Everything   ---\n";
			std::cout << "---Iterator     ---\n";
			std::cout << "---Wfirst       ---\n";
			std::cout << "---Last         ---\n";
			std::cout << "---Next         ---\n";
			std::cout << "---Prev         ---\n";
			std::cout << "---GetItem      ---\n";
			break;
		case 'a': case 'A':
			circularDoubleLinkedList->AddElement(0);
			if (circularDoubleLinkedList->GetActualNode()->GetData() == nullptr) {
				data = new Data;
				circularDoubleLinkedList->GetActualNode()->SetData(data);
			}
			else {
				data = static_cast<Data*>(circularDoubleLinkedList->GetActualNode()->GetData());
			}
			std::cout << "--->Name:";
			std::cin >> data->name;
			data->name = CinFail(data->name);
			std::cout << "--->LastName:";
			std::cin >> data->lastName;
			data->lastName = CinFail(data->lastName);
			std::cout << "--->Age:";
			std::cin >> data->age;
			data->age = CinFail(data->age);
			std::cout << "--->reg:";
			std::cin >> data->reg;
			data->reg = CinFail(data->reg);
			PrintActual(circularDoubleLinkedList);
			break;
		case 's': case 'S':
			if (circularDoubleLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			moreStoredData = false;
			std::cout << "Name/Reg?: 0/1: ";
			std::cin >> content;
			content = CinFail(content);
			if (content != 0 && content != 1) {
				std::cout << "ERROR: Invalid content\n";
				break;
			}
			if (content == 0) {
				std::cout << "--->Name:";
				std::cin >> dat.name;
				dat.name = CinFail(dat.name);
				circularDoubleLinkedList->move = circularDoubleLinkedList->start;
				while (circularDoubleLinkedList->move != nullptr) {
					if (((Data*)circularDoubleLinkedList->move->GetData())->name == dat.name) {
						PrintWithNodeID(circularDoubleLinkedList, circularDoubleLinkedList->move->GetID());
						moreStoredData = true;
					}
					circularDoubleLinkedList->move = circularDoubleLinkedList->move->GetNext();
				}
				if (moreStoredData == false) {
					std::cout << "ERROR: Not Found";
				}
				break;
			}
			std::cout << "--->reg:";
			std::cin >> dat.reg;
			dat.reg = CinFail(dat.reg);
			circularDoubleLinkedList->move = circularDoubleLinkedList->start;
			while (circularDoubleLinkedList->move != nullptr) {
				if (((Data*)circularDoubleLinkedList->move->GetData())->reg == dat.reg) {
					PrintWithNodeID(circularDoubleLinkedList, circularDoubleLinkedList->move->GetID());
					moreStoredData = true;
				}
				circularDoubleLinkedList->move = circularDoubleLinkedList->move->GetNext();
			}
			if (moreStoredData == false) {
				std::cout << "ERROR: Not Found";
			}
			break;
		case 'd': case 'D':
			if (circularDoubleLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			std::cout << "--->reg:";
			std::cin >> dat.reg;
			dat.reg = CinFail(dat.reg);
			circularDoubleLinkedList->move = circularDoubleLinkedList->start;
			while (circularDoubleLinkedList->move != nullptr) {
				if (((Data*)circularDoubleLinkedList->move->GetData())->reg == dat.reg) {
					circularDoubleLinkedList->actual = circularDoubleLinkedList->move;
					circularDoubleLinkedList->DeleteActual();
					moreStoredData = true;
					circularDoubleLinkedList->actual = circularDoubleLinkedList->start;
					circularDoubleLinkedList->move = circularDoubleLinkedList->start;
					if (circularDoubleLinkedList->move == nullptr) {
						break;
					}
				}
				circularDoubleLinkedList->move = circularDoubleLinkedList->move->GetNext();
			}
			if (moreStoredData == false) {
				std::cout << "ERROR: Not Found";
			}
			break;
		case 'm': case 'M':
			if (circularDoubleLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			std::cout << "--->reg:";
			std::cin >> dat.reg;
			dat.reg = CinFail(dat.reg);
			circularDoubleLinkedList->move = circularDoubleLinkedList->start;
			while (circularDoubleLinkedList->move != nullptr) {
				if (((Data*)circularDoubleLinkedList->move->GetData())->reg == dat.reg) {
					circularDoubleLinkedList->actual = circularDoubleLinkedList->move;
					if (circularDoubleLinkedList->GetActualNode()->GetData() == nullptr) {
						data = new Data;
						circularDoubleLinkedList->GetActualNode()->SetData(data);
					}
					else {
						data = static_cast<Data*>(circularDoubleLinkedList->GetActualNode()->GetData());
					}
					std::cout << "--->Name:";
					std::cin >> data->name;
					data->name = CinFail(data->name);
					std::cout << "--->LastName:";
					std::cin >> data->lastName;
					data->lastName = CinFail(data->lastName);
					std::cout << "--->Age:";
					std::cin >> data->age;
					data->age = CinFail(data->age);
					std::cout << "--->reg:";
					std::cin >> data->reg;
					data->reg = CinFail(data->reg);

					circularDoubleLinkedList->SetActualData(data);
					moreStoredData = true;
					circularDoubleLinkedList->actual = circularDoubleLinkedList->start;
					circularDoubleLinkedList->move = circularDoubleLinkedList->start;
					if (circularDoubleLinkedList->move == nullptr) {
						break;
					}
				}
				circularDoubleLinkedList->move = circularDoubleLinkedList->move->GetNext();
			}
			if (moreStoredData == false) {
				std::cout << "ERROR: Not Found";
			}
			break;
		case 'c': case 'C':
			if (circularDoubleLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			std::cout << "There are " << circularDoubleLinkedList->CountNodes() << " Nodes\n";
			break;
		case 'i': case 'I':
			if (circularDoubleLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			PrintActual(circularDoubleLinkedList);
			break;
		case 'w': case 'W':
			if (circularDoubleLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			circularDoubleLinkedList->actual = circularDoubleLinkedList->start;
			PrintActual(circularDoubleLinkedList);
			break;
		case 'l': case 'L':
			if (circularDoubleLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			circularDoubleLinkedList->actual = circularDoubleLinkedList->end;
			PrintActual(circularDoubleLinkedList);
			break;
		case 'n': case 'N':
			if (circularDoubleLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			if (circularDoubleLinkedList->CountNodes() == 2) {
				circularDoubleLinkedList->actual = circularDoubleLinkedList->GetNodeWithID(circularDoubleLinkedList->actual->GetNodeIDOnListPosition(1));
				break;
			}
			circularDoubleLinkedList->MoveToNodeID(circularDoubleLinkedList->actual->GetNodeIDWithExtraUtilitys(2));
			PrintActual(circularDoubleLinkedList);
			break;
		case 'p': case 'P':
			if (circularDoubleLinkedList->actual == nullptr) {
				std::cout << "ERROR: The List Is Empty";
				break;
			}
			if (circularDoubleLinkedList->CountNodes() == 2) {
				circularDoubleLinkedList->actual = circularDoubleLinkedList->GetNodeWithID(circularDoubleLinkedList->actual->GetNodeIDOnListPosition(1));
				break;
			}
			circularDoubleLinkedList->MoveToNodeID(circularDoubleLinkedList->actual->GetNodeIDWithExtraUtilitys(1));
			PrintActual(circularDoubleLinkedList);
			break;
		case 'g': case 'G': {
			Node* save = circularDoubleLinkedList->actual;
			std::cout << "Name:     " << ((Data*)save->GetData())->name << std::endl;
			std::cout << "LastName: " << ((Data*)save->GetData())->lastName << std::endl;
			std::cout << "Age:      " << ((Data*)save->GetData())->age << std::endl;
			std::cout << "Reg:      " << ((Data*)save->GetData())->reg << std::endl;
			break; }
		case 'e': case 'E':
			PrintEverything(circularDoubleLinkedList);
			std::cout << "\n\nactual = " << circularDoubleLinkedList->actual << " next = " << circularDoubleLinkedList->GetNodeWithID(circularDoubleLinkedList->actual->GetNodeIDWithExtraUtilitys(2));

		}
		std::cout << "\n--->";
		std::cin >> input;
	}
}


//Functions


void Menus::PathFindingToAll(Graph* graph) {
	if (graph->GetActualNode() == nullptr) {
		std::cout << "ERROR: There's No Actual Node" << std::endl;
		return;
	}
	ConectionsList NodeSteps(0, graph->GetActualNode()->GetID(), 6);
	Node* move = graph->GetActualNode();
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
		move = graph->GetNodeWithID(NodeSteps.GetConectionOnListPosition(i));
	}
	Conection* ConectionMove = NodeSteps.GetStart();
	while (ConectionMove != nullptr) {
		std::cout << "\n";
		std::cout << "--(" << ConectionMove->GetValue() << ", ID:" << ConectionMove->GetID() << ")-->NodeID[" << ConectionMove->GetNodeID() << "]";
		ConectionMove = ConectionMove->GetNext();
	}
	return;
}


void Menus::PrintActual(Graph* graph) {
	if (graph->GetActualNode() == nullptr) {
		std::cout << "ERROR: There's No Actual Node" << std::endl;
		return;
	}
	if (graph->GetActualData() != nullptr) {
		std::cout << "Name:     " << ((Data*)graph->GetActualData())->name << std::endl;
		std::cout << "LastName: " << ((Data*)graph->GetActualData())->lastName << std::endl;
		std::cout << "Age:      " << ((Data*)graph->GetActualData())->age << std::endl;
		std::cout << "Reg:      " << ((Data*)graph->GetActualData())->reg << std::endl;
	}
	std::cout << "Node[content:" << graph->GetActualNode()->GetContent() << " | ID:" << graph->GetActualNode()->GetID() << "]";
}


void Menus::PrintEverything(Graph* graph) {
	if (graph->GetStartNode() == nullptr) {
		std::cout << "ERROR: The Graph Is Empty" << std::endl;
		return;
	}
	Node* move = graph->GetStartNode();
	if (move == nullptr) {
		return;
	}
	if (graph->GetActualData() != nullptr) {
		while (move != nullptr) {
			std::cout << "Name:     " << ((Data*)move->GetData())->name << std::endl;
			std::cout << "LastName: " << ((Data*)move->GetData())->lastName << std::endl;
			std::cout << "Age:      " << ((Data*)move->GetData())->age << std::endl;
			std::cout << "Reg:      " << ((Data*)move->GetData())->reg << std::endl;
			Conection* ConectionMove = move->GetConectionList()->GetStart();
			while (ConectionMove != nullptr) {
				std::cout << "\n";
				std::cout << "--(" << ConectionMove->GetValue() << ", ID:" << ConectionMove->GetID() << ")-->NodeID[" << ConectionMove->GetNodeID() << "]";
				ConectionMove = ConectionMove->GetNext();
			}
			std::cout << "\n*--------------------*\n";
			move = move->GetNext();
		}
		return;
	}
	while (move != nullptr) {
		std::cout << "Node[content:" << move->GetContent() << " | ID:" << move->GetID() << "]";
		std::cout << "\n";
		Conection* ConectionMove = move->GetConectionList()->GetStart();
		while (ConectionMove != nullptr) {
			std::cout << "\n";
			std::cout << "--(" << ConectionMove->GetValue() << ", ID:" << ConectionMove->GetID() << ")-->NodeID[" << ConectionMove->GetNodeID() << "]";
			ConectionMove = ConectionMove->GetNext();
		}
		std::cout << "\n*--------------------*\n";
		move = move->GetNext();
	}
}


void Menus::PrintWithNodeID(Graph* graph, int NodeID) {
	if (graph->GetStartNode() == nullptr) {
		std::cout << "ERROR: The Graph Is Empty" << std::endl;
		return;
	}
	Node* move = graph->GetNodeWithID(NodeID);
	if (move == nullptr) {
		return;
	}
	if (graph->GetActualData() != nullptr) {
		std::cout << "Name:     " << ((Data*)move->GetData())->name << std::endl;
		std::cout << "LastName: " << ((Data*)move->GetData())->lastName << std::endl;
		std::cout << "Age:      " << ((Data*)move->GetData())->age << std::endl;
		std::cout << "Reg:      " << ((Data*)move->GetData())->reg << std::endl;
		Conection* ConectionMove = move->GetConectionList()->GetStart();
		while (ConectionMove != nullptr) {
			std::cout << "\n";
			std::cout << "--(" << ConectionMove->GetValue() << ", ID:" << ConectionMove->GetID() << ")-->NodeID[" << ConectionMove->GetNodeID() << "]";
			ConectionMove = ConectionMove->GetNext();
		}
		return;
	}
	if (move == nullptr) {
		std::cout << "ERROR: Node " << NodeID << " Doesn't Exists" << std::endl;
		return;
	}
	std::cout << "Node[content:" << move->GetContent() << " | ID:" << move->GetID() << "]";
}

//a pepe cacas 21 21100290 a paquito maya 21 21300 a juan alcachofas 10 21300290 a martin julian 17 21300490 a alejandro pinzon 17 211002