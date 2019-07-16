#include<iostream>
#include"airport.h"

aircraft::aircraft() {
	this->ID = 0001;
}

void aircraft::set_state(node* n) {
	if (n->isvacant)
		this->position = n;
	else
		std::cout << "state not vacant";
}