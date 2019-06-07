#include "iterator.hpp"

//BinaryIterator
void BinaryIterator::first()
{
    curr = self_ptr->get_left();
}
void BinaryIterator::next()
{
    if(curr == self_ptr->get_left())
      curr = self_ptr->get_right();
    if(curr == self_ptr->get_right())
      curr = NULL;
}
bool BinaryIterator::is_done()
{ 
    if(curr == NULL){
      return true;
    }  
    return false;
}
Base* BinaryIterator::current()
{
    return curr;
}

//UnaryIterator
void UnaryIterator::first()
{
    curr = self_ptr->get_left();
}
void UnaryIterator::next()
{
    if(curr == self_ptr->get_left())
      curr = NULL;
}
bool UnaryIterator::is_done()
{
    if(curr == NULL){
      return true;
    }  
    return false;
}
Base* UnaryIterator::current()
{
    return curr;
}

//NullIterator
void NullIterator::first()
{
   return;
}
void NullIterator::next()
{
   return;
}
bool NullIterator::is_done()
{
    return true;
}
Base* NullIterator::current() 
{
    return NULL;
}

void PreOrderIterator::first() {
   if(!iterators.empty())
   {
       while(!iterators.empty())
       {
          iterators.pop();
       }
   }
   Iterator* temp = this->self_ptr->create_iterator();
   temp->first();
   iterators.push(temp);
   return;
}

void PreOrderIterator::next() {
    Iterator* p = this->iterators.top()->current()->create_iterator();
    p->first();
    this->iterators.push(p);
    while(this->iterators.size() > 0 && this->iterators.top()->is_done())
    {
       this-> iterators.pop();
        if(!iterators.empty())
        {
            this->iterators.top()->next();
        }
    }
}

bool PreOrderIterator::is_done() {
   if(iterators.empty())
   {
       return true;
   } 
   return false;
}

Base* PreOrderIterator::current() {
    if(this->iterators.size() > 0)
    {
     return iterators.top()->current();
    }
    else
    {
        return NULL;
    }
}
