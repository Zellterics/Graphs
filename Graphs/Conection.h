#pragma once
#include <iostream>

class Conection
{
private:
	int ID, content, NodeID, extraUtilitys = -2;
	Conection* past, *next = nullptr, *mySelf = this;
public:
	Conection(int content, Conection* past, int NodeID);
	Conection(int content, Conection* past, int NodeID, int extraUtilitys);
	bool SetID(int ID);
	bool SetNext(Conection* next);
	bool SetPast(Conection* past);
	Conection* GetNext();
	Conection* GetPast();
	int GetExtraUtilitys();
	int GetID();
	int GetNodeID();
	int GetValue();
	void PrintConection();
	void ReplaceValues(int content, int extraUtilitys);
};