#pragma once
class node {
	int index;
	bool state;
	node* next1 = NULL;
	node* next2 = NULL;
	int *vacancy;

public:
	const float duration;

	node();
	node(int index, float Duration, int &vacancy);

	void show_index();
	void show_network();

	bool isvacant();
	bool isterminal();

	void link(node* n1, node* n2);
	void link(node* n1);

	node* goto_next_node();

	void change_vacancy(int N);

	void update_state();
	void occupy();
	void reset();
};



