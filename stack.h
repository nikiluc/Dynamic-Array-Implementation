//
//  stack.h
//  Dynamic Array
//
//  Created by Luc Nikiema on 10/22/18.
//  Copyright © 2018 Luc Nikiema. All rights reserved.
//

#include "vector.h"
#include "node.h"

using namespace std;

#ifndef stack_h
#define stack_h


template <typename T>
class Stack {
public:
    
    Stack();
    int size() const {
        return vec.size();
    };
    bool empty() const {
        return vec.empty();
    };
    void push(const T &x);
    T pop();
    T top();
    ~Stack();
    void clear();

private:
    
    Vector<T> vec;

};

template<typename T>
Stack<T>::Stack() {
    
    //Default Constructor
    
}

//Pushes element onto the stack
template<typename T>
void Stack<T>::push(const T &x) {
    vec.push_back(x);
}

//Removes first element of the array
template <typename T>
T Stack<T>::pop() {
    
    if (vec.empty()) {
        throw std::out_of_range("Stack is empty");
    }
    
       T x = (vec[size()-1]);
        vec.pop_back();
    
    return x;
    
}

//Returns the value stored at the first element
//in the array
template <typename T>
T Stack<T>::top(){
    
    if (vec.empty()) {
        throw std::out_of_range("Stack is empty");
    }
    T y;
    
     y = (vec[size()-1]);
    
    return y;
    
}

//Clears the stack
template <typename T>
void Stack<T>::clear() {
    
    
        while (size() > 0) {
        
            pop();
        
        }

    
    
}
//Destructor
template <typename T>
Stack<T>::~Stack<T>() {
    
    this->clear();

}

#endif /* stack_h */
