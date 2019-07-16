// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "graph.h"
#include "airport.h"

node *g1 = new node(1, 30);
node *g2 = new node(2, 30);
node *end = new node(3, 15);
node *start = new node(0, 15);

float time = 100;

int main()
{
	start->link(g1, g2);
	g1->link(end);
	g2->link(end);

	aircraft a1, a2, a3;

	while (time > 0) {
	
		if (a1.nextstate == 0) {
			a1.state.reset();
			a1.set_next_state();
		}
		if (a1.nextstate == 0) {
			a1.state.reset();
			a1.set_next_state();
		}
	}

	//do not go beyond this. 
	std::cin.get();

}
