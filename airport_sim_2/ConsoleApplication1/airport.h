#pragma once

#include"graph.h"

/*static int runway_vacancy;
float RT;
float BT;
float TT;*/

class aircraft {
	int ID;
	int freed = 0;
public:
	float minwaittime = 0;
	static int freedplane ;
	static int freedtime;
	node* position;
	float standtime = 0;
	float waittime = 0;
	aircraft();
	aircraft(int ID, node* positon);
	aircraft(node* positon);
	void copy(const aircraft& p);
	void goto_next_position();
	void show_position();
	void check_availability(float time);
	void free(float time);
	void wait(float time);
	void show_ID();
	void alter_position(node* n);
};

void show_all(aircraft arr[], int numberofplane);
void goto_all(aircraft arr[], int numberofplane );
void update_all(aircraft arr[], int numberofplane, float time );
int calculate_min_gates(int N_total, int BT, int RT, int RW);
aircraft* create_new_aircrafts(int ID[], int N_total, node* N); // create new plane at postion N