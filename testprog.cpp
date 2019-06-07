#include <iostream>
#include "iterator.hpp"
#include "compositepattern.hpp"

using namespace std;

int main () {
	Op* op3 = new Op(4);
	Op* op4 = new Op(2);
	Op* op2 = new Op(9);
	Add* add = new Add(op3, op4); //6
	Pow* pow = new Pow(add,op4); //36
	Sub* sub = new Sub(pow, op2); //27
	Mult* mult = new Mult(sub,op3); //3
	Root* root = new Root(mult);

	cout << "--- PreOrder Iteration ---" << endl;
	PreOrderIterator* pre_itr = new PreOrderIterator(root);
	
	int i = 1;
	for(pre_itr->first(); !pre_itr->is_done(); pre_itr->next()) {
		cout << "Operation " << i << ": ";
		cout << pre_itr->current()->evaluate();
		cout << endl;
		i++;
	}
	
	Op* op1 = new Op(5);
	Op* op0 = new Op(10);
	Op* op5 = new Op(2);
	Op* op6 = new Op(1);
	Mult* multiply = new Mult(op1, op5); //10
	Sub* Subtract = new Sub(multiply, op0); //0
	Add* addition = new Add(Subtract, op6);//1
	Pow* power = new Pow(addition,op5);//2
	Root* root2 = new Root(power);
	
	cout << "Second test" << endl;
	PreOrderIterator* temp = new PreOrderIterator(root2);
	
	int j = 1;
	for(temp->first(); !temp->is_done(); temp->next())
	{
		cout << "Operation " << j << ": ";
		cout << temp->current()->evaluate();
		cout << endl;
		j++;
	}
	return 0;
};

