#ifndef ITERATOR_H
#define ITERATOR_H

class Iterator 
{
    protected:
        Base* self_ptr;

    public:
        Iterator(Base* ptr) { this->self_ptr = ptr; }

        /* Sets up the iterator to start at the beginning of traversal */
        virtual void first() = 0;
        
        /* Move onto the next element */
        virtual void next() = 0;
    
        /* Returns if you have finished iterating through all elements */
        virtual bool is_done() = 0;

        /* Return the element the iterator is currently at */
        virtual Base* current() = 0;
};

class BinaryIterator : public Iterator 
{
    public:
        Iterator(Base* ptr) : Iterator(ptr){};
        void first();
        void next();
        bool is_done();
        Base* current();
};

class UnaryIterator : public Iterator 
{
    public:
        Iterator(Base* ptr) : Iterator(ptr){};
        void first();
        void next();
        bool is_done();
        Base* current();
};

class NullIterator : public Iterator 
{
    public:
        Iterator(Base* ptr) : Iterator(ptr){};
        void first();
        void next();
        bool is_done();
        Base* current();
};

#endif
