#include "stdafx.h"
#include<iostream>
#include "graph.h"

node::node(int i, float t) : duration(t) {
	this->index = i;
}

bool node::isvacant() {
	return this->state;
}

void node::link(node*n1, node*n2) {
	this->next1 = n1;
	this->next2 = n2;
}

void node::link(node*n1) {
	this->next1 = n1;
}

// non member functions
int countspace = 0;

void print(char x, int n) {
	for (int i = 0; i < n; i++)
		std::cout << x;
}

void node::show() {

	if (this != nullptr) {
		std::cout << this->index << "->";
		countspace++;

		this->next1->show();
		print('\n', 1);
		print(' ', countspace);
		this->next2->show();
	}

	else std::cout << ".";
}