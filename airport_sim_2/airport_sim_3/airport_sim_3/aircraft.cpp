#include "stdafx.h"
#include<iostream>
#include"airport.h"

aircraft::aircraft() {
	this->ID = 0001;
}

aircraft::aircraft(node* n) {
	this->position = n;
}

void aircraft::alter_position(node* n) {
	this->position->reset();
//	std::cout << " alter";
	this->position = n;
	n->occupy();
}


int aircraft::freedplane = 0;
int aircraft::freedtime = 0;

void aircraft::copy(const aircraft& p) {
	ID = p.ID;
	freed = p.freed;
	minwaittime = p.minwaittime;
	freedplane = p.freedplane;
	position = p.position;
	standtime = p.standtime;
	waittime = p.waittime;
}

aircraft::aircraft(int ID, node* position) {
	this->ID = ID;
	this->position = position;
	position->occupy();
	minwaittime = position->duration;
}

void aircraft::goto_next_position() {
	node* temp = this->position;
	this->position = this->position->goto_next_node();
	temp->reset();
//	std::cout << " goto";
	this->position->occupy();
}

void aircraft::show_position() {
//	std::cout << "\n plane " << ID << ": current position: ";
	this->position->show_index();
}

void aircraft::check_availability(float time) {
	if (this->position->isterminal() == true) {
		free(time);
	}
	else
	{
		if ((this->position->goto_next_node() != this->position) && time >= minwaittime) {
			goto_next_position();
			minwaittime = time + position->duration;
		}
		else
			wait(time);
	}
}

void show_all(aircraft arr[], int numberofplane) {
	int i = 0;
	while (i< numberofplane) {
		arr[i].show_position();
		i++;
	}
}

void goto_all(aircraft arr[], int numberofplanes) {
	int i = 0;
	while (i<numberofplanes) {
		arr[i].goto_next_position();
		i++;
	}
}

void update_all(aircraft arr[], int numberofplane, float time) {
	int i = 0;
	while (i< numberofplane) {
		arr[i].check_availability(time);
		i = i + 1;
	}
};

void aircraft::free(float time) {
	if (this->freed != 1) {
		position->reset();
	//	std::cout << " free";
		freed = 1;
		freedplane++;
//		std::cout << "\n plane freed : " << freedplane << " at time = " << time << " minutes";
		freedtime = time;
	}
	else {
		//	std::cout << " \n plane "<<ID<<" flew already";
	}
}

void aircraft::wait(float time) {
	if (time >= minwaittime) {
		waittime++;
		//	std::cout << " \nplane " << ID << " waiting at ";
		//	position->show_index();
	}
	else {
		//	std::cout <<" \nplane "<<ID<< " standing at ";
		//	position->show_index();
	}

}

void aircraft::show_ID() {
	std::cout << ID;
}


aircraft* create_new_aircrafts(int ID[], int N_total, node* N) {
	aircraft* planes = new aircraft[N_total];
	for (int i = 0; i < N_total; i++) {
		aircraft* newplane = new aircraft(ID[i], N);
		planes[i].copy(*newplane);
		delete newplane;
	}
	return planes;
}

void delete_all(aircraft *A) {

	aircraft::freedplane = 0;
	delete A;
};

void aircraft::show_totalFreeTime() {
	std::cout <<"\ntotal freedtime : " <<aircraft::freedtime<<" minutes";
}