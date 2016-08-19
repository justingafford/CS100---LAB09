#include "iterator.h"

void PreorderIterator::first() {
    // Empty the stack (just in case we had something leftover from another run)
    // Create an iterator for the Base* that we built the iterator for
    // Initialize that iterator and push it onto the stack
}

void PreorderIterator::next() {
    // Create an iterator for the item on the top of the stack
    // Initialize the iterator and push it onto the stack
    // As long as the top iterator on the stack is_done(), pop it off the stack and then advance whatever iterator is now on top of the stack
}

bool PreorderIterator::is_done() {
    // Return true if there are no more elements on the stack to iterate
}

Base* PreorderIterator::current() {
    // Return the current for the top iterator in the stack
}
