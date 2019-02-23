

#ifndef node_h
#define node_h


#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <exception>



using std::string;
using std::endl;
using std::cout;



/****************************************************************************
 *                                                                          *
 *                      class Node declaration                            *
 *                                                                          *
 ****************************************************************************/

template <typename T>
class Node
{
public:
    T info;
    Node<T> *left;
    Node<T> *right;
    
    Node(T = T(), Node<T> *left = NULL, Node<T> *right = NULL);
    void PrintExpress(Node<T>);
    
}; //END declaration class Node

//Explicit constructor for Node (with Binary Node implementation)
template <typename T>
Node<T>::Node(T infoValue, Node<T> *leftPtr, Node<T> *rightPtr)
{
    info = infoValue;
    left = leftPtr;
    right = rightPtr;
}

template <typename T>
void Node<T>::PrintExpress(Node<T> binaryNode){
    
    //If current node is a leaf node
    if (binaryNode.left == NULL && binaryNode.right == NULL) {
        
        cout << binaryNode.info <<" ";
    }
    
    //in order traversal
    else {
        PrintExpress(*binaryNode.right);
        cout << binaryNode.info <<" ";
        PrintExpress(*binaryNode.left);
        
    }
    
}







#endif /* dlnode_h */
