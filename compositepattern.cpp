#include "iterator.h"
#include "compositepattern.h"
#include <string>
#include <cmath>
//**Op Class**
Op::Op() : Base(), value(0){}

Op::Op(double val) : Base(), value(val){}

Base* Op::get_left() { return NULL; }

Base* Op::get_right() { return NULL; }

string Op::stringify() {
	return to_string(value);
}

double Op::evaluate() { return this->value; }

Iterator* Op::create_iterator() { return new NullIterator(this); }
 
Base* Rand::get_left() { return NULL; }

Base* Rand::get_right() { return NULL; }

Rand::Rand() {num = rand() % 100;};
 
double Rand::evaluate() {return num;}
 
string Rand::stringify() {return to_string(num);}

Iterator* Rand::create_iterator() { return new NullIterator(this); }
//**Operator Base Class**
Operator::Operator() : Base(){ }

Operator::Operator(Base* l, Base* r) : left(l), right(r){  }

Base* Operator::get_left() { return left; }

Base* Operator::get_right() { return right; }

Iterator* Operator::create_iterator() { return new BinaryIterator(this); }

//**Unary Base Class**
UnaryOperator::UnaryOperator() : Base(){}

UnaryOperator::UnaryOperator(Base* c) : child(c) { }

Base* UnaryOperator::get_left() { return child; }

Base* UnaryOperator::get_right() { return NULL; }

Iterator* UnaryOperator::create_iterator() { return new UnaryIterator(this); }

//**Add Class**
Add::Add() : Operator() { }

Add::Add(Base* left, Base* right) : Operator(left,right) { }

string Add::stringify() {
	string temp = left ->stringify() + " + " + right ->stringify();
	return temp;
}

double Add::evaluate() { return this->left->evaluate() + this->right->evaluate(); }

//**Sub Class**
Sub::Sub() : Operator() { }

Sub::Sub(Base* left, Base* right) : Operator(left,right) { }

string Sub::stringify() {
	string temp = left ->stringify() + " - " + right ->stringify();
	return temp;
}

double Sub::evaluate() { return this->left->evaluate() - this->right->evaluate(); }

//**Mult Class**

Mult::Mult() : Operator() { }

Mult::Mult(Base* left, Base* right) : Operator(left,right) { }

string Mult::stringify() {
	string temp = left ->stringify() + " + " + right ->stringify();
	return temp;
}

double Mult::evaluate() { return this->left->evaluate() * this->right->evaluate(); }


//**Div Class**
Div::Div() : Operator() { }

Div::Div(Base* left, Base* right) : Operator(left,right) { }

string Div::stringify() {
	string temp = left ->stringify() + " / " + right ->stringify();
	return temp;
}

double Div::evaluate() { return this->left->evaluate() / this->right->evaluate(); }

//**Pow Class**
Pow::Pow() : Operator() { }

Pow::Pow(Base* left,Base* right) : Operator(left,right) { }

string Pow::stringify() {
	string temp = left ->stringify() + " ** " + right ->stringify();
	return temp;
}

double Pow::evaluate() { return pow(this-> left  -> evaluate() , this-> right  -> evaluate()); }

//**Root Class**
Root::Root() : UnaryOperator() { }

Root::Root(Base* child) : UnaryOperator(child) { }


string Root::stringify() { cout << "ROOT"; }

double Root::evaluate() { return this->child->evaluate(); }

double Ceil::evaluate()
{
    return ceil(child->evaluate());
}

double Floor::evaluate()
{
    return floor(child->evaluate());
}

double Abs::evaluate()
{
    return abs(child->evaluate());
}

string Trunc::stringify()
{
    return to_string(child->evaluate());
}

string Paren::stringify()
{
    string temp = "(" + child->stringify() + ")";
    return temp;
}

