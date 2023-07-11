#include "Menus.h"

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
			std::cout << "---Terminate    ---\n";
			std::cout << "---BorderNodes  ---\n";
			std::cout << "---DeleteNode   ---\n";
			break;
		case 'a': case 'A':
			std::cout << "--->Node content:";
			std::cin >> content;
			graph->AddNode(content);
			graph->PrintActual();
			break;
		case 'c': case 'C':
			std::cout << "--->Conection content:";
			std::cin >> content;
			std::cout << "\n--->Conection NodeID:";
			std::cin >> NodeID;
			graph->ConectToNodeID(content, NodeID);
			graph->PrintActual();
			std::cout << "--(" << content << ")-->";
			graph->PrintWithNodeID(NodeID);
			break;
		case 'g': case 'G':
			std::cout << "--->NodeID:";
			std::cin >> NodeID;
			if (!graph->GoToNodeID(NodeID)) {
				std::cout << "--->ERROR: No Such NodeID\n";
			}
			graph->PrintActual();
			break;
		case 's': case 'S':
			std::cout << "--->NodeID:";
			std::cin >> NodeID;
			if (!graph->MoveToNodeID(NodeID)) {
				std::cout << "--->ERROR: Not Such NodeID Conection\n";
			}
			graph->PrintActual();
			break;
		case 'p': case 'P':
			graph->PrintActual();
			break;
		case 'e': case 'E':
			graph->PrintEverything();
			break;
		case 'n': case 'N':
			std::cout << "--->NodeID:";
			std::cin >> NodeID;
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
		default:
			std::cout << "That's Not An Option" << std::endl;
			break;
		}
		std::cout << "\n--->";
		std::cin >> input;
	}
	delete(this);
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
			std::cout << "---GoTo         ---\n";
			std::cout << "---Print        ---\n";
			std::cout << "---Everything   ---\n";
			std::cout << "---Terminate    ---\n";
			std::cout << "---DeleteActual ---\n";
			break;
		case 'a': case 'A':
			std::cout << "--->Node content:";
			std::cin >> content;
			linkedList->AddElement(content);
			linkedList->PrintActual();
			break;
		case 'g': case 'G':
			std::cout << "--->NodeID:";
			std::cin >> NodeID;
			if (!linkedList->GoToNodeID(NodeID)) {
				std::cout << "--->ERROR: No Such NodeID\n";
			}
			linkedList->PrintActual();
			break;
		case 'p': case 'P':
			linkedList->PrintActual();
			break;
		case 'e': case 'E':
			linkedList->PrintEverything();
			break;
		case 't': case 'T':
			stop = true;
			break;
		case 'd': case 'D':
			linkedList->DeleteActual();
			break;
		default:
			std::cout << "That's Not An Option" << std::endl;
			break;
		}
		std::cout << "\n--->";
		std::cin >> input;
	}
	delete(this);
}