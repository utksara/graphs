// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "graph.h"
#include "airport.h"

node *g1 = new node(2, 10);
node *g2 = new node(3, 10);
node *end = new node(4, 3);
node *start = new node(1, 3);
node *fly = new node(5, 0);
node *land = new node(0, 0);

float time = 0;

int main()
{
	land->link(start);
	start->link(g1, g2);
	g1->link(end);
	g2->link(end);
	end->link(fly);

	float gtime = 0;

	aircraft a0(0,start), a1(1, g1), a2(2, g2);

	node* arr[5] = { start,g1,g2,end };

	g1->occupy();
	g2->occupy();

	while (gtime < 50) {

		a0.show_position();
		a0.goto_next_position();

		a1.show_position();
		a1.goto_next_position();

		a2.show_position();
		a2.goto_next_position();

		std::cout << "\n";

		gtime++;

		std::cout << "\n";
	}

	
	//do not go beyond this. 
	std::cin.get();

}
