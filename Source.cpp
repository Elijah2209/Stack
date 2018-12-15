#include<iostream>
using namespace std;

struct node_t {
	node_t() {
		prev = nullptr;
	}
	int value;
	node_t* prev;
};


class stack {
private:
	node_t* top;
public:
	stack() {
		top = nullptr;
	};
	~stack() {
		//TODO
	};
	void read();
	bool is_empty();
	void push(int);
	void revers();
	int* pop();
	void stack_delete();
};


void stack::push(int value) {
	node_t* tmp = new node_t();
	tmp->value = value;
	tmp->prev = top;
	top = tmp;
}


int* stack::pop() {
	if (!is_empty()) {
		int* tmp_val = new int(top->value);
		node_t* tmp_top = top;
		top = top->prev;
		delete tmp_top;
		return tmp_val;
	}
	return nullptr;
}

bool stack::is_empty() {
	return top == nullptr;
}

void stack::read() {
	while (!is_empty()) {
		cout << *(pop()) << endl;
	}
}
void stack::revers() {
	node_t *pre = nullptr;
	node_t *tmp = nullptr;
	while (top != 0) {
		tmp = top;
		top = top->prev;
		tmp->prev = pre;
		pre = tmp;
	}
	top = pre;
}
void stack::stack_delete() {
	while (!is_empty()) {
		node_t*a = top;
		top = top->prev;
		delete a;
	}
}


int main() {
	stack my_stack;

	for (int i = 0; i < 5; ++i) {
		my_stack.push(i);
	}
	my_stack.read();
	for (int i = 0; i < 5; ++i) {
		my_stack.push(i);
	}
	my_stack.revers();
	my_stack.read();
	int* out = my_stack.pop();

	my_stack.stack_delete();



	//TODO: read stack content

	return 0;
}



// API
// Application Programming Interface



