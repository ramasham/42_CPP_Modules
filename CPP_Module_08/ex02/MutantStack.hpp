#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

//stack is a container adapter
//std::stack<int> s -> std::stack<int, std::deque<int> > s
//stack uses deque to store the data

//typedef -> Used to create an alias (a new name) for an existing type.
//typename -> Used inside templates to tell the compiler that a dependent name is a type.

// Create a custom stack that inherits from std::stack
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
    public:
        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;

        iterator begin() {
            return this->c.begin();
        }
        iterator end() {
            return this->c.end();
        }

        const_iterator begin() const {
            return this->c.begin();
        }
        const_iterator end() const {
            return this->c.end();
        }
};


#endif