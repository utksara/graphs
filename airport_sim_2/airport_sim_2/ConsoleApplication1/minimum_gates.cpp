#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include "airport.h"
#include <vector>

int calculate_min_gates(int N_total, int BT, int RT) {

	node* start = new node(0, RT, 10);
	node* q1 = new node(1, 5, 100);
	node* g = new node(2, BT, 1);
	node* q2 = new node(3, 5, 100);
	node* end = new node(4, RT, 10);

	start->link(q1);
	q1->link(g);
	g->link(q2);
	q2->link(end);

	int N_air = 1;
	int N_queue = N_total - 1;
	int N_gates = 1;
	int optimum_gates = 1;
	
	float init_freedtime = 1;
	float time = 0;
	float total_simulation_time = 200;

	int* IDs = new int[N_gates];
	int* IDa = new int[N_air];
	int* IDw = new int[N_queue];

	int* Gates_array = new int[N_total];

	for (int i = 0; i < N_queue; i++) {
		IDw[i] = 100+i;
	}
	for (int i = 0; i < N_gates; i++) {
		IDs[i] = 200 + i;
	}
	for (int i = 0; i < N_air; i++) {
		IDa[i] = 300 + i;
	}

		for (N_air = 1; N_air < N_total; N_air++) {
			N_queue = N_total - N_air;
			aircraft* planes_air = create_new_aircrafts(IDa, N_air, start);
			aircraft* planes_standing = create_new_aircrafts(IDw, N_queue, q1);

			for (N_gates = 1; N_gates <= N_total; N_gates++) {
				g->change_vacancy(N_gates);
				aircraft* planes_waiting = create_new_aircrafts(IDs, N_gates, g);

				while (time < total_simulation_time) {

					update_all(planes_standing, N_queue, time);
					update_all(planes_waiting, N_gates, time);
					update_all(planes_air, N_air, time);
					time++;
				//	show_all(planes_waiting, N_queue);
					show_all(planes_air, N_air);
				//	show_all(planes_standing, N_gates);

					std::cout << "\n freed time: " << aircraft::freedtime;
					std::cout << "\n int time: " << init_freedtime;

					if (aircraft::freedtime == init_freedtime && aircraft::freedplane == N_total) {
						optimum_gates = N_gates-1;
						Gates_array[N_air] = optimum_gates;
						std::cout << " \n Hi H \n ";
						break;
					}

					init_freedtime = aircraft::freedtime;
				}
		}
			
			delete planes_air;
			//delete planes_standing;

	}

		return *(std::max_element(Gates_array, Gates_array + N_total));
}