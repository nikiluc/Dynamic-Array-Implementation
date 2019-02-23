//
//  main.cpp
//  Dynamic Array
//
//  Created by Luc Nikiema on 10/15/18.
//  Copyright © 2018 Luc Nikiema. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <cmath>
#include <random>
#include <iomanip>
#include "vector.h"
#include "node.h"
#include "stack.h"

int main(int argc, const char * argv[]) {
    
    try {
    
    Node<char> *m1 = new Node<char>;
    
    Stack<Node<char>*> s1;
    Stack<Node<char>*> s2;
    
    
    ifstream input_file("/Users/lucnikiema/Downloads/TEST.txt");
    
    if (!input_file.is_open()) {
        cout << "Could not open inputData.txt\n" << endl;
        exit(1);
    }
    
    char x;
    
    while (input_file >> x) {
        
        //If it's a number, push it on the stack
        
        if (isdigit(x)){
           
            s1.push(new Node<char>(x));
            
        }
        
        //If it's a letter, push it on the stack
        else if (isalpha(x)) {
            
            s1.push(new Node<char>(x));
            
        }
        
        else {
            
            //Seperates one postfix expression from another
            if (x == '\n') {
            
            //For when there are multiple postfix expresssions
                
            }
            
            //If its an operator, create a binary tree with the
            //operator as the root and the operands as the left
            //and right subtrees
            else {
                
            s1.push(new Node<char>(x, s1.pop(), s1.pop()));
                
            }
            
        }
    }
    
    
    /*To get the contents of the Stack in the right order,
     as in, the order that they were read in */
    while (s1.size() > 0) {
        s2.push(s1.pop());
    }
    //Print all expressions
    while (s2.size() > 0) {
        m1->PrintExpress(*s2.pop());
        cout << endl;
    }
        
        
    }
    
    
    catch (const out_of_range &oor) {
       cout << "Out of Range error: " << oor.what() << endl;
    }
    
    catch (...) {
        cout << "Exception caught in main" << endl;
    }
    

    return 0;
}
