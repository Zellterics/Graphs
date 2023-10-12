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
			std::cout << "---HowManyNodes ---\n";
			std::cout << "---Terminate    ---\n";
			break;
		case 'a': case 'A':
			std::cout << "--->Node content:";
			std::cin >> content;
			content = CinFail(content);
			queue->AddElement(content);
			PrintActual(queue);
			break;
		case 'g': case 'G':
			std::cout << "--->NodeID:";
			std::cin >> NodeID;
			NodeID = CinFail(NodeID);
			if (!queue->GoToNodeID(NodeID)) {
				std::cout << "--->ERROR: No Such NodeID\n";
			}
			PrintActual(queue);
			break;
		case 'p': case 'P':
			PrintActual(queue);
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
			PrintActual(queue);
			break;
		case 'h': case 'H':
			std::cout << "There are " << queue->CountNodes() << " Nodes\n";
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
				delete erase;
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
			std::cout << "---HowManyNodes ---\n";
			std::cout << "---Terminate    ---\n";
			break;
		case 'a': case 'A':
			std::cout << "--->Node content:";
			std::cin >> content;
			content = CinFail(content);
			linkedList->AddElement(content);
			PrintActual(linkedList);
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
			PrintActual(linkedList);
			break;
		case 'p': case 'P':
			PrintActual(linkedList);
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
			PrintActual(linkedList);
			break;
		case 'h': case 'H':
			std::cout << "There are " << linkedList->CountNodes() << " Nodes\n";
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
			std::cout << "---HowManyNodes ---\n";
			std::cout << "---Terminate    ---\n";
			break;
		case 'a': case 'A':
			std::cout << "--->Node content:";
			std::cin >> content;
			content = CinFail(content);
			doubleLinkedList->AddElement(content);
			PrintActual(doubleLinkedList);
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
			PrintActual(doubleLinkedList);
			break;
		case 'p': case 'P':
			PrintActual(doubleLinkedList);
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
			PrintActual(doubleLinkedList);
			break;
		case 'h': case 'H':
			std::cout << "There are " << doubleLinkedList->CountNodes() << " Nodes\n";
			break;
		default:
			std::cout << "That's Not An Option" << std::endl;
			break;
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
	std::cout << "Node[content:" << graph->GetActualNode()->GetContent() << " | ID:" << graph->GetActualNode()->GetID() << "]";
}


void Menus::PrintEverything(Graph* graph) {
	if (graph->GetStartNode() == nullptr) {
		std::cout << "ERROR: The Graph Is Empty" << std::endl;
		return;
	}
	Node* move = graph->GetStartNode();
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
		std::cout << "ERROR: Node " << NodeID << " Doesn't Exists" << std::endl;
		return;
	}
	std::cout << "Node[content:" << move->GetContent() << " | ID:" << move->GetID() << "]";
}