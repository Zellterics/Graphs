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
			std::cout << "---GoTo         ---\n";
			std::cout << "---Print        ---\n";
			std::cout << "---Everything   ---\n";
			std::cout << "---Delete       ---\n";
			std::cout << "---ModifyContent---\n";
			std::cout << "---Terminate    ---\n";
			break;
		case 'a': case 'A':
			std::cout << "--->Node content:";
			std::cin >> content;
			content = CinFail(content);
			pile->AddElement(content);
			pile->PrintActual();
			break;
		case 'g': case 'G':
			std::cout << "--->NodeID:";
			std::cin >> NodeID;
			NodeID = CinFail(NodeID);
			if (!pile->GoToNodeID(NodeID)) {
				std::cout << "--->ERROR: No Such NodeID\n";
			}
			pile->PrintActual();
			break;
		case 'p': case 'P':
			pile->PrintActual();
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
			pile->PrintActual();
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
			std::cout << "---GoTo         ---\n";
			std::cout << "---Print        ---\n";
			std::cout << "---Everything   ---\n";
			std::cout << "---Delete       ---\n";
			std::cout << "---ModifyContent---\n";
			std::cout << "---Terminate    ---\n";
			break;
		case 'a': case 'A':
			std::cout << "--->Node content:";
			std::cin >> content;
			content = CinFail(content);
			queue->AddElement(content);
			queue->PrintActual();
			break;
		case 'g': case 'G':
			std::cout << "--->NodeID:";
			std::cin >> NodeID;
			NodeID = CinFail(NodeID);
			if (!queue->GoToNodeID(NodeID)) {
				std::cout << "--->ERROR: No Such NodeID\n";
			}
			queue->PrintActual();
			break;
		case 'p': case 'P':
			queue->PrintActual();
			break;
		case 'e': case 'E':
			PrintEverything(queue);
			break;
		case 't': case 'T':
			stop = true;
			break;
		case 'd': case 'D':
			queue->DeleteElement();
			break;
		case 'm': case 'M':
			std::cout << "--->Node content:";
			std::cin >> content;
			content = CinFail(content);
			queue->ChangeActualNodeContent(content);
			queue->PrintActual();
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
			std::cout << "---Terminate    ---\n";
			break;
		case 'a': case 'A':
			std::cout << "--->Node content:";
			std::cin >> content;
			content = CinFail(content);
			graph->AddNode(content);
			graph->PrintActual();
			break;
		case 'c': case 'C':
			std::cout << "--->Conection content:";
			std::cin >> content;
			content = CinFail(content);
			std::cout << "\n--->Conection NodeID:";
			std::cin >> NodeID;
			NodeID = CinFail(NodeID);
			graph->ConectToNodeID(content, NodeID);
			graph->PrintActual();
			std::cout << "--(" << content << ")-->";
			graph->PrintWithNodeID(NodeID);
			break;
		case 'g': case 'G':
			std::cout << "--->NodeID:";
			std::cin >> NodeID;
			NodeID = CinFail(NodeID);
			if (!graph->GoToNodeID(NodeID)) {
				std::cout << "--->ERROR: No Such NodeID\n";
			}
			graph->PrintActual();
			break;
		case 's': case 'S':
			std::cout << "--->NodeID:";
			std::cin >> NodeID;
			NodeID = CinFail(NodeID);
			if (!graph->MoveToNodeID(NodeID)) {
				std::cout << "--->ERROR: Not Such NodeID Conection\n";
			}
			graph->PrintActual();
			break;
		case 'p': case 'P':
			graph->PrintActual();
			break;
		case 'e': case 'E':
			PrintEverything(graph);
			break;
		case 'n': case 'N':
			std::cout << "--->NodeID:";
			std::cin >> NodeID;
			NodeID = CinFail(NodeID);
			if (graph->GetNodeWithID(NodeID) == nullptr) {
				std::cout << "--->ERROR: Not Such NodeID Conection\n";
				graph->PrintActual();
				continue;
			}
			graph->PathFindingToNodeID(NodeID);
			break;
		case 'w': case 'W':
			graph->PathFindingToAll();
			break;
		case 't': case 'T':
			stop = true;
			break;
		case 'b': case 'B':
			graph->PrintActualConections();
			break;
		case 'd': case 'D':
			graph->DeleteActual();
			break;
		case 'm': case 'M':
			std::cout << "--->Node content:";
			std::cin >> content;
			content = CinFail(content);
			graph->ChangeActualNodeContent(content);
			graph->PrintActual();
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
			std::cout << "---InPlaceAdd   ---\n";
			std::cout << "---GoTo         ---\n";
			std::cout << "---Print        ---\n";
			std::cout << "---Everything   ---\n";
			std::cout << "---DeleteActual ---\n";
			std::cout << "---ModifyContent---\n";
			std::cout << "---Terminate    ---\n";
			break;
		case 'a': case 'A':
			std::cout << "--->Node content:";
			std::cin >> content;
			content = CinFail(content);
			linkedList->AddElement(content);
			linkedList->PrintActual();
			break;
		case 'i': case 'I':
			std::cout << "--->Node content:";
			std::cin >> content;
			content = CinFail(content);
			linkedList->AddNextToActual(content);
			break;
		case 'g': case 'G':
			std::cout << "--->NodeID:";
			std::cin >> NodeID;
			NodeID = CinFail(NodeID);
			if (!linkedList->GoToNodeID(NodeID)) {
				std::cout << "--->ERROR: No Such NodeID\n";
			}
			linkedList->PrintActual();
			break;
		case 'p': case 'P':
			linkedList->PrintActual();
			break;
		case 'e': case 'E':
			PrintEverything(linkedList);
			break;
		case 't': case 'T':
			stop = true;
			break;
		case 'd': case 'D':
			linkedList->DeleteActual();
			break;
		case 'm': case 'M':
			std::cout << "--->Node content:";
			std::cin >> content;
			content = CinFail(content);
			linkedList->ChangeActualNodeContent(content);
			linkedList->PrintActual();
			break;
		default:
			std::cout << "That's Not An Option" << std::endl;
			break;
		}
		std::cout << "\n--->";
		std::cin >> input;
	}
}

Menus::Menus(DoubleLinkedList* doubleLinkedList) {
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
			std::cout << "---InPlaceAdd   ---\n";
			std::cout << "---GoTo         ---\n";
			std::cout << "---Print        ---\n";
			std::cout << "---Everything   ---\n";
			std::cout << "---DeleteActual ---\n";
			std::cout << "---ModifyContent---\n";
			std::cout << "---Terminate    ---\n";
			break;
		case 'a': case 'A':
			std::cout << "--->Node content:";
			std::cin >> content;
			content = CinFail(content);
			doubleLinkedList->AddElement(content);
			doubleLinkedList->PrintActual();
			break;
		case 'i': case 'I':
			std::cout << "--->Node content:";
			std::cin >> content;
			content = CinFail(content);
			doubleLinkedList->AddNextToActual(content);
			break;
		case 'g': case 'G':
			std::cout << "--->NodeID:";
			std::cin >> NodeID;
			NodeID = CinFail(NodeID);
			if (!doubleLinkedList->GoToNodeID(NodeID)) {
				std::cout << "--->ERROR: No Such NodeID\n";
			}
			doubleLinkedList->PrintActual();
			break;
		case 'p': case 'P':
			doubleLinkedList->PrintActual();
			break;
		case 'e': case 'E':
			PrintEverything(doubleLinkedList);
			break;
		case 't': case 'T':
			stop = true;
			break;
		case 'd': case 'D':
			doubleLinkedList->DeleteActual();
			break;
		case 'm': case 'M':
			std::cout << "--->Node content:";
			std::cin >> content;
			content = CinFail(content);
			doubleLinkedList->ChangeActualNodeContent(content);
			doubleLinkedList->PrintActual();
			break;
		default:
			std::cout << "That's Not An Option" << std::endl;
			break;
		}
		std::cout << "\n--->";
		std::cin >> input;
	}
}