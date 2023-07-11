#include <iostream>
#include <string>
#include <algorithm>
#include "Graph.h"

int main(){
	int content;
	std::cout << "--->Node content: ";
	std::cin >> content;
	Graph graph;
	graph.TerminalController();
	//graph.Test();
	return 0;
}