#pragma once
#include"graph.h"

class aircraft: public node {
	int ID;
public:
	node* position;
	float standtime=0;
	aircraft();
	aircraft(int ID, node* positon);
	void goto_next_position();
	void show_position();
};