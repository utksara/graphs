// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "graph.h"
#include "airport.h"

int main()
{
	int N_total = 5;
	int BT = 7;
	int RT = 3;

	/*
	node* start = new node(0, RT, 5);
	node* q1 = new node(1, 0, 10);
	node* g = new node(2, BT, 10);
	node* q2 = new node(3, 0, 10);
	node* end = new node(4, RT, 10);

	start->link(q1);
	q1->link(g);
	g->link(q2);
	q2->link(end);

	float time = 0;
	float total_simulation_time = 100;
	
	aircraft  a1(1, start), a2(2, start), a3(4, start), a4(4, q1), a5(5, q1) ;
	aircraft A[5] = { a1,a2,a3,a4,a5 };

	while (time < total_simulation_time) {

		update_all(A, 5, time);

		time++;
		show_all(A, 5);
	}*/
	
	std::cout <<"\noptimum gates : "<< calculate_min_gates(N_total, BT, RT);

	//do not go beyond this. 
	std::cin.get();

}
