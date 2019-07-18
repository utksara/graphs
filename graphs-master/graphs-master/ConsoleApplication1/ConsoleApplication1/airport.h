#pragma once
#include"graph.h"

class aircraft: public node {
	int ID;
public:
	float minwaittime = 0;
	static int freedplane ;
	node* position;
	float standtime = 0;
	float waittime = 0;
	aircraft();
	aircraft(int ID, node* positon);
	void goto_next_position();
	void show_position();
	void check_availability(float time);
	void free();
	void wait(float time);
};

void show_all(aircraft arr[], int numberofplane);
void goto_all(aircraft arr[], int numberofplane );
void update_all(aircraft arr[], int numberofplane, float time );