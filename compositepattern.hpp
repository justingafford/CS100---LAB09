#ifndef compositepattern_h
#define compositepattern_h

#include <iostream>
#include <sstream>
#include <math.h>
#include <string>
#include "iterator.hpp"

using namespace std;

class Iterator;
class NullIterator;
class UnaryIterator;

//Abstract Base Class
class Base {
    public:
        virtual string stringify() = 0;
        virtual double evaluate() = 0;
        virtual Iterator* create_iterator() = 0;
        virtual Base* get_left() = 0;
        virtual Base* get_right() = 0;
};

//Leaf Classes
class Op: public Base {
   protected:
        double num;
   public:
	Op();
        Op(double n);
        double evaluate();
        string stringify();
        Base* get_left();
        Base* get_right();  
        Iterator* create_iterator();
};

class Rand : public Base
{
    private:
        double num;
    public:
        Rand();
        double evaluate();
        string stringify();
        Base* get_left();
        Base* get_right();  
        Iterator* create_iterator();
};

//Composite Base Classes
class Operator: public Base {
    protected:
        Base* left, *right;
    public:
        Operator();
        Operator(Base* l, Base* r);
        Base* get_left();
        Base* get_right();
        virtual double evaluate() = 0;
        Iterator* create_iterator();
};

class UnaryOperator: public Base {
    protected:
        Base* child;
    public:
        UnaryOperator();
        UnaryOperator(Base* c);
        Base* get_left();
        Base* get_right();
        virtual double evaluate() = 0;
        Iterator* create_iterator();
};

class Add: public Operator {
 private:
	Base* L1;
	Base* L2;
 public:
	Add(Base*, Base*);
	double evaluate();
	string stringify();
};

class Sub: public Operator {
  private:
	 Base* L1;
	 Base* L2;
  public:
	 Sub(Base*, Base*);
	 double evaluate();
	 string stringify();
};

class Mult: public Operator {
 private:
	Base* L1;
	Base* L2;      
 public:
  Mult(Base*, Base*);
	double evaluate();
	string stringify();
};

class Div: public Operator {
  private:
	 Base* L1;
	 Base* L2;
  public:
	 Div(Base*, Base*);
	 double evaluate();
	 string stringify();
};

class Pow: public UnaryOperator {
  private:
	  Base* L1;
	  Base* L2;   
  public:
    Pow(Base*, Base*);
	  double evaluate();
	  string stringify();
};
#endif
