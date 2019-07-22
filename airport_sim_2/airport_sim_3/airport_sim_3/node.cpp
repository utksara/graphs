#include "stdafx.h"
#include<iostream>
#include "graph.h"


// non member functions
int countspace = 0;

void print(char x, int n) {
	for (int i = 0; i < n; i++)
		std::cout << x;
}

node::node() : duration(0) {
	this->index = 0;
}

node::node(int index, float Duration, int &vacancy) : duration(Duration) {
	this->index = index;
	(this->vacancy) = &vacancy;
}
void node::update_state() {
	this->state = (*(this->vacancy) > 0) ? 1 : 0;
}

bool node::isvacant() {

	if (this != nullptr) {
		update_state();
		return this->state;
	}
	else {
		//std::cout << "\nisvacant::node is empty!!";
		return 0;
	}
}

bool node::isterminal() {
	if (this->next1 == nullptr && this->next2 == nullptr)
		return 1;
	else
		return 0;
}

void node::link(node*n1, node*n2) {
	this->next1 = n1;
	this->next2 = n2;
}

void node::link(node*n1) {
	if (this->next1 == nullptr)
		this->next1 = n1;
	else if (this->next2 == nullptr)
		this->next2 = n1;
	else
		std::cout << "link::node already linked!! \n";
}

void node::show_network() {
	if (this != nullptr) {
		std::cout << this->index << "->";
		countspace++;

		this->next1->show_network();
		print('\n', 1);
		print(' ', countspace);
		this->next2->show_network();
	}
	else std::cout << ".";
}

void node::show_index() {
	if (this != nullptr)
		std::cout << "\n            node : " << (index);
	else
		std::cout << "show_index::empty node!! \n";
}

node* node::goto_next_node() {
	if (this != nullptr) {
		if (this->isterminal()) {
			std::cout << "\ngoto_next_node::terminal node!!  ";
			return this;
		}
		else {
			if (this->next1->isvacant())
				return this->next1;
			else if (this->next2->isvacant())
				return this->next2;
			else {
				return this;
			}
		}
	}
	else {
		std::cout << "\ngoto_next_node::empty node!!";
		return this;
	}
}


void node::occupy() {
	*vacancy = *vacancy - 1;
//	std::cout << "\nposition occupied " << index << " vacancy now " << *vacancy;
	this->update_state();
};

void node::reset() {
	*vacancy = *vacancy + 1;
//	std::cout << "\nposition vacant " << index << " vacancy now " << *vacancy;
	this->update_state();
}

void node::change_vacancy(int N) {
	*(this->vacancy) = N;
}