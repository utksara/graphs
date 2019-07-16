#pragma once
class node {
	int index;
	bool state = 0;
	const float duration;
	node *next1 = NULL;
	node *next2 = NULL;

public:
	node(int i, float t);
	void show();
	bool isvacant();
	void link(node*n1, node*n2);
	void link(node*n1);

};

class network {
	int states[2][10];
	node* start;

public:
	network(int arr[]);
};