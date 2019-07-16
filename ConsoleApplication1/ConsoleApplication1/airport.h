#pragma once
#include"graph.h"

class aircraft {
	int ID;
	node* position;

public:
	aircraft();
	aircraft(int ID, node* positon);
	void set_state(node* n);

};