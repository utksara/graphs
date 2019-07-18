#include "stdafx.h"
#include<iostream>
#include"airport.h"

aircraft::aircraft() {
	this->ID = 0001;
}

int aircraft::freedplane =0;

aircraft::aircraft(int ID, node* position) {
	this->ID = ID;
	this->position = position;
	position->occupy();
}

void aircraft::goto_next_position() {
	node* temp = this->position;
	this->position = this->position->goto_next_node();
	temp->reset();
	this->position->occupy();
}

void aircraft::show_position() {
	std::cout <<"plane "<<ID<<": current position: ";
	this->position->show_index();
	std::cout << "\n";
}

void aircraft::check_availability(float time) {
	if (this->position->isterminal()) {
		free();
	}
	else
	{
		if ((this->position->goto_next_node()!=this->position) && time >= minwaittime) {
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

void goto_all(aircraft arr[],  int numberofplanes) {
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
		i=i+1;
	}
};

void aircraft::free() {
	position->reset();
	freedplane++;
	std::cout << "plane freed";
}

void aircraft::wait(float time) {
	if (time >= minwaittime)
		waittime++;
	else{
		std::cout << "\n standing at ";
		position->show_index();
	}

}