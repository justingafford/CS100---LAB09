#include "iterator.h"

//BinaryIterator
void BinaryIterator::first()
{
    curr = self_ptr->get_left();
}
void BinaryIterator::next()
{
    curr = self_ptr->get_left();
    if(curr == self_ptr->get_left())
      curr = self_ptr->get_right();
    if(curr == self_ptr->get_right())
      curr = NULL;
}
bool BinaryIterator::is_done()
{ 
    if(curr == NULL)
      return true;
      
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
    curr = self_ptr->get_left();
    if(curr == self_ptr->get_left())
      curr = NULL;
}
bool UnaryIterator::is_done()
{
    if(curr == NULL)
      return true;
      
    return false;
}
Base* UnaryIterator::current()
{
    return curr;
}

//NullIterator
void NullIterator::first()
{
   
}
void NullIterator::next()
{
    
}
bool NullIterator::is_done()
{
    return true;
}
Base* NullIterator::current()
{
    return NULL;
}
