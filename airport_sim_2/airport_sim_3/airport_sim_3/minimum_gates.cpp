#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include "airport.h"
#include <vector>

int calculate_min_gates(int N_total, int BT, int RT, int RW) {

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


			int qv1 = 100;
			int rv1 = RW;
			int qv2 = 100;
			int gv = 1;
			int av = 200;

			float TT = 5;

			node* start = new node(0, 0, av);
			node* landing = new node(1, RT, rv1);
			node* q1 = new node(2, TT, qv1);
			node* g = new node(3, BT, gv);
			node* q2 = new node(4, TT, qv2);
			node* takeoff = new node(5, RT, rv1);
			node* end = new node(6, 0, av);

			start->link(landing);
			landing->link(q1);
			q1->link(g);
			g->link(q2);
			q2->link(takeoff);
			takeoff->link(end);

			std::cout << "\n Starting run for " << N_gates << " no. of gates :";

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
				}
			else
				for (int i = 0; i < N_queue; i++) {
					planes_standing[i].alter_position(g);
				}

			float time = 0;
			float total_simulation_time = 1000;

			while (/*time < total_simulation_time*/aircraft::freedplane != N_total) {

				//std::cout << "\n\nsimulation starts : tick "<<time<<" minutes\n";

				update_all(planes_standing, N_queue, time);
				update_all(planes_air, N_air, time);
				time++;
				if (aircraft::freedplane == N_total) {
			//		std::cout << "\nfreedplanes : " << aircraft::freedplane;
					time = total_simulation_time;
				}

			}
			aircraft::show_totalFreeTime();
			delete_all(planes_air);
			delete_all(planes_standing);


			delete start;
			delete q1;
			delete g;
			delete q2;
			delete end;

			if (init_freedtime == aircraft::freedtime) {
				Gates_array[N_air - 1] = N_gates;
				N_gates = N_total;
			}
			else
				init_freedtime = aircraft::freedtime;
		}
		std::cout << "\n..............\n";
	}

	return *(std::max_element(Gates_array, Gates_array + N_total - 1));
}