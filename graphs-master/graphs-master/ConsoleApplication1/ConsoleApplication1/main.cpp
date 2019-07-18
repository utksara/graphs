// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "graph.h"
#include "airport.h"

node *g1 = new node(1, 5);
node *g2 = new node(2, 5);
node *end = new node(3, 3);
node *start = new node(0, 3);

float time = 0;

int main()
{
	start->link(g1, g2);
	g1->link(end);
	g2->link(end);

	float globaltime = 0;

	aircraft a0(0,start), a1(1, g1), a2(2, g2);

	aircraft planes[3] = { a0,a1,a2 };

	while (globaltime < 50) {

		show_all(planes,3);
		update_all(planes, 3, globaltime);

		
		std::cout << "\n";

		globaltime++;

		std::cout << "\n";
	}

	
	//do not go beyond this. 
	std::cin.get();

}
