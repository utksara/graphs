#pragma once
class node {
	int index;
	bool state = 1;
	node *next1 = NULL;
	node *next2 = NULL;

public:
	const float duration ;

	node();
	node(int i, float t);
	
	void show_index();
	void show_network();
	
	bool isvacant();
	bool isterminal();
	
	void link(node*n1, node*n2);
	void link(node*n1);
	
	node* goto_next_node();
	
	void occupy();
	void reset();
};
