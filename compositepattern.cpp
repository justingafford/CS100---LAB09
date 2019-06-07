#include "compositepattern.hpp"
#include "iterator.hpp"
#include <string>

using namespace std;

//**Add Class Functions**
Add::Add(Base* l1, Base* l2): L1(l1), L2(l2) {}

double Add::evaluate() {
	return L1 ->evaluate() + L2 ->evaluate();
}

string Add::stringify() {
	string temp = L1 ->stringify() + " + " + L2 ->stringify();
	return temp;
}

//**Sub Class Functions**
Sub::Sub(Base* l1, Base* l2): L1(l1), L2(l2) {}

double Sub::evaluate() {
	return L1 ->evaluate() - L2 ->evaluate();
}

string Sub::stringify() {
	string temp = L1 ->stringify() + " - " + L2 ->stringify();
	return temp;
}

//**Div Class Functions**
Div::Div(Base* l1, Base* l2): L1(l1), L2(l2) {}

double Div::evaluate() {
	return L1 ->evaluate() / L2 ->evaluate();
}

string Div::stringify() {
	string temp = L1 ->stringify() + " / " + L2 ->stringify();
	return temp;
}

//**Mult Class Functions**
Mult::Mult(Base* l1, Base* l2): L1(l1), L2(l2) {}

double Mult::evaluate() {
	return L1 ->evaluate() * L2 ->evaluate();
}

string Mult::stringify() {
	string temp = L1 ->stringify() + " * " + L2 ->stringify();
	return temp;
}

//**Pow Class Functions**
Pow::Pow(Base* l1, Base* l2): L1(l1), L2(l2) {}

double Pow::evaluate() {
	return pow(L1 -> evaluate() , L2 -> evaluate());
}
	
string Pow::stringify() {
	string temp = L1 ->stringify() + " ** " + L2 ->stringify();
	return temp;
}

//**Op Class Functions**
Op::Op () {
	num = 0;
}
Op::Op(double  n) {
	num = n;
}
double Op::evaluate() {
	return num;
}

string Op::stringify() {
	return to_string(num);
}

Base* Op::get_left() { return NULL; }

Base* Op::get_right() { return NULL; }

Iterator* Op::create_iterator() { return new NullIterator(this); }

//**Rand Class Functions**
Rand::Rand() {num = rand() % 100;};

double Rand::evaluate() {return num;}

string Rand::stringify() {return to_string(num);}

Base* Rand::get_left() { return NULL; }

Base* Rand::get_right() { return NULL; }

Iterator* Rand::create_iterator() { return new NullIterator(this); }

//**Operator Class Function**
Operator::Operator() : Base(){ }

Operator::Operator(Base* l, Base* r) : left(l), right(r){  }

Base* Operator::get_left() { return left; }

Base* Operator::get_right() { return right; }

Iterator* Operator::create_iterator() { return new BinaryIterator(this); }

//**UnaryOperator Fucntion**
UnaryOperator::UnaryOperator() : Base(){}

UnaryOperator::UnaryOperator(Base* c) : child(c) { }

Base* UnaryOperator::get_left() { return child; }

Base* UnaryOperator::get_right() { return NULL; }

Iterator* UnaryOperator::create_iterator() { return new UnaryIterator(this); }

