#include "stdafx.h"
#include<iostream>
#include "graph.h"


// non member functions
int countspace = 0;

void print(char x, int n) {
	for (int i = 0; i < n; i++)
		std::cout << x;
}

//

node::node() : duration(0) {
	this->index = 0;
}

node::node(int i, float t) : duration(t) {
	this->index = i;
}

bool node::isvacant() {
	if (this!= nullptr)
		return this->state;
	else
		return 0;
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
	this->next1 = n1;
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

std::cout<<(this->index);

}

node* node::goto_next_node() {
	node* thisnode = this;
	if (thisnode->next1->isvacant())
		thisnode = this->next1;
	else if (this->next2->isvacant())
		thisnode = this->next2;
	return thisnode;
}

void node::occupy() {
	this->state = 0;
};

void node::reset() {
	this->state = 1;
}
