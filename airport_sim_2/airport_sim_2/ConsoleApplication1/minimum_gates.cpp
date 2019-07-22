#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include "airport.h"
#include <vector>

int calculate_min_gates(int N_total, int BT, int RT) {

	int* Gates_array = new int[N_total - 1];

	for (int N_air = 1; N_air < N_total; N_air++) {
		aircraft::freedplane = 0;
		std::cout << "\nHi dear : " << N_air << " in air ";

		int optimum_gates = 1;

		int N_queue = N_total - N_air;

		int* IDa = new int[N_air];
		int* IDw = new int[N_queue];

		for (int i = 0; i < N_queue; i++) {
				IDw[i] = 100 + i;
		}

		for (int i = 0; i < N_air; i++) {
				IDa[i] = 300 + i;
		}
		float init_freedtime = -1;
			for (int N_gates = 1; N_gates <= N_total; N_gates++) {

				node* start = new node(0, 0, 10);
				node* q1 = new node(1, 5, 100);
				node* g = new node(2, BT, 1);
				node* q2 = new node(3, 5, 100);
				node* end = new node(4, 0, 10);

				start->link(q1);
				q1->link(g);
				g->link(q2);
				q2->link(end);

				aircraft::freedplane = 0;

				std::cout << "\n\n Starting run for " << N_gates << " no. of gates :\n";

				aircraft* planes_air = create_new_aircrafts(IDa, N_air, start);
				aircraft* planes_standing = create_new_aircrafts(IDw, N_queue, q1);
				int* IDs = new int[N_gates];

				g->change_vacancy(N_gates);
				for (int i = 0; i < N_gates; i++) {
					IDs[i] = 200 + i;
				}

				if (N_gates < N_queue)
					for (int i = 0; i < N_gates; i++) {
						planes_standing[i].alter_position(g);
						//q1->reset();
					}
				else
					for (int i = 0; i < N_queue; i++) {
						planes_standing[i].alter_position(g);
						//q1->reset();
					}

				float time = 0;
				float total_simulation_time = 110;

				while (time < total_simulation_time) {

					//std::cout << "\n\nsimulation starts : tick "<<time<<" minutes\n";

					update_all(planes_standing, N_queue, time);
					update_all(planes_air, N_air, time);
					time++;
					if (aircraft::freedplane == N_total) {
						std::cout << "\nfreedplanes : " << aircraft::freedplane;
						time = total_simulation_time;
					}

				}

				std::cout << "\n\n\n\n\n";
				delete planes_air;
				delete planes_standing;

				delete start;
				delete q1;
				delete g;
				delete q2;
				delete end;

				if (init_freedtime == aircraft::freedtime) {
					Gates_array[N_air - 1] = N_gates;
					N_gates = N_total;
					std::cout << "\n	big boobies" ;
				}
				else
					init_freedtime = aircraft::freedtime;
			}
			std::cout << "\n\n\n..............\n\n\n";
	}

	return *(std::max_element(Gates_array, Gates_array + N_total-1));
}