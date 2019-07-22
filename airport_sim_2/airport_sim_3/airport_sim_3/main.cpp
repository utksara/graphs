// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "graph.h"
#include "airport.h"

int main()
{
	int N_total = 40;
	int BT = 40;
	int RT = 3;
	int RW = 1;

	std::cout << "\noptimum gates : " << calculate_min_gates(N_total, BT, RT, RW);

	//do not go beyond this. 
	std::cin.get();

}
