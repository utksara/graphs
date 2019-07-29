#pragma once

#include"graph.h"
/*class Input {

public:
	int N_total = 0;
	float BT = 0;
	float RT = 0;

	Input(int N_total, float BT, float RT) {
		this->N_total = N_total;
		this->BT = BT;
		this->RT = RT;
	}

};*/

class aircraft : protected node {
	int ID;
	int freed = 0;
	float minwaittime = 0;
	node* position;
	float standtime = 0;
	float waittime = 0;
	void free(float time);
	void wait(float time);

public:
	static int freedplane;
	static int freedtime;
	aircraft();
	aircraft(int ID, node* positon);
	aircraft(node* positon);

	//void setinput(int, int, int, float, float, float, float, float, float);
	void copy(const aircraft& p);
	void goto_next_position();
	void show_position();
	void check_availability(float time);
	void show_ID();
	void alter_position(node* n);
	static void show_totalFreeTime();
};

void show_all(aircraft arr[], int numberofplane);
void goto_all(aircraft arr[], int numberofplane);
void update_all(aircraft arr[], int numberofplane, float time);
int calculate_min_gates(int N_total, int BT, int RT, int RW);
aircraft* create_new_aircrafts(int ID[], int N_total, node* N); // create new plane at postion N
void delete_all(aircraft *A);