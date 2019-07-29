// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "graph.h"
#include "airport.h"

int main()
{
	int N_total1 = 150;
	int BT1 = 37;
	int RT1 = 2;
	int RW1 = 1;

	int N_total2 = 10;
	int BT2 = 10;
	int RT2 = 3;
	int RW2 = 1;

	int N_total3 = 10;
	int BT3 = 10;
	int RT3 = 3;
	int RW3 = 1;

	int input1[4] = { N_total1, BT1, RT1, RW1 };
	int input2[4] = {N_total2, BT2, RT2, RW2};
	int input3[4] = {N_total3, BT3, RT3, RW3};

	std::cout << "\noptimum gates : " << calculate_min_gates(N_total1, BT1, RT1, RW1);
	
	//do not go beyond this. 
	std::cin.get();

}
