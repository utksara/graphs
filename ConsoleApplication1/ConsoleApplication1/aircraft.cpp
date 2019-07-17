#include "stdafx.h"
#include<iostream>
#include"airport.h"

aircraft::aircraft() {
	this->ID = 0001;
}

aircraft::aircraft(int ID, node* position) {
	this->ID = ID;
	this->position = position;
	position->occupy();
}

void aircraft::goto_next_position() {
	node* temp = this->position;

	if (this->standtime >= this->position->duration) {

		if (this->position->isterminal()) {
			temp->reset();
		}
		else{
			this->position = this->position->goto_next_node();

			if (temp != this->position) {
				this->position->occupy();
				temp->reset();
				this->standtime = 0;
			}
		}
	}
	else {
		this->standtime++;
	}
}

void aircraft::show_position() {
	std::cout <<"plane "<<ID<<": current position: ";
	this->position->show_index();
	std::cout << "\n";
}
