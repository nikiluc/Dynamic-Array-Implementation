//
//  Vector.h
//  Dynamic Array
//
//  Created by Luc Nikiema on 10/18/18.
//  Copyright © 2018 Luc Nikiema. All rights reserved.
//
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;

#ifndef Vector_h
#define Vector_h

#include <algorithm>
/*Dynamic Array/Vector class*/
template <typename T>
class Vector
{
public:
    //Explicit Constructor
    explicit Vector( int initSize = 0 ) : theSize{ initSize },
    theCapacity{ initSize + SPARE_CAPACITY }
    { objects = new T[theCapacity]; }
    
    //Copy Constructor
Vector( const Vector & rhs ) : theSize{ rhs.theSize },
    theCapacity{ rhs.theCapacity }, objects{ nullptr }
    {
        objects = new T[ theCapacity ];
        for (int k = 0 ; k < theSize; ++k) {
            
            objects[k] = rhs.objects[k];
            
        }
    }
 //Overloaded operator
Vector & operator= ( const Vector & rhs ) {
        
        Vector copy = rhs;
        swap( *this, copy );
        return *this;
    
    }
    
~Vector( )  {
    delete [ ] objects;
}
    
    
    //Determines if array is to be resized
    void resize( int newSize )
    {
        if( newSize > theCapacity )
            reserve( newSize * 2);
        theSize = newSize;
    }
    //Creates new array with newSize
    void reserve(int newCapacity )
    {
        if (newCapacity < theSize) {
            
             return;
            
        }
        
        T *newArray = new T[newCapacity];
        
        for (int k = 0; k < theSize; ++k) {
            newArray[k] = std::move( objects[k] );
            theCapacity = newCapacity;
            std::swap( objects, newArray );
            
        }
        
        delete [ ] newArray;
        
        
    }
    //Overloaded [] operator
    T & operator[]( int index)
    {
        return objects [index];
        
    }
    
    bool empty( ) const
    { return size( ) == 0; }
    
    int size( ) const
    { return theSize; }
    
    int capacity( ) const
    { return theCapacity; }
    
    //Pushes stuff onto the vector
    void push_back( const T &x ) {
        
        if (theSize == theCapacity) {
            reserve( 2 * theCapacity + 1);
        }
        objects[theSize++] = x;
        
    }
    
    //Reduces the size by 1 removing element that
    //was stored
    void pop_back()
    {
        
        
        --theSize;
        
    }
    
    
    
    typedef T * iterator;
    typedef const T * const_iterator;
    //Iterator at the first element of the arary
    iterator begin( )
    {
        return &objects[0];
        
    }
    //Iterator one position after the last element
    iterator end( )
    {
        
      
        return &objects[size()];
        
    }
    
    static const int SPARE_CAPACITY = 16;
    
private:
    int theSize = 0;
    int theCapacity = 0;
    T * objects;
};


//Implementation of Insertion Sort
template<typename T>
void InsertionSort(Vector<T> &a){
    
    //Sorts like how one sorts playing cards
    //Sorts by comparing elements in the array until
    //element is in proper location
    for (int p = 1; p < a.size( ); ++p) {
        
        T tmp = a[p];
        int j;
        for( j = p; j > 0 && tmp < a[j-1]; --j) {
            
            a[j] = (a[j-1]);
            
        }
        a[j] = (tmp);
        
    }
    
}

/*Quicksort Implementation
 -Takes the first and last position in
 the array in order to pick the pivot
 and sort recursively
 */
template<typename T>
void QuickSort(Vector<T> &a, int left, int right)
{
    int pivot;
    
    if (left<=right) {
        
        pivot = Partition(a, left, right);
        QuickSort(a, left, pivot-1);
        QuickSort(a, pivot+1, right);
    }
}

/*Picks and properly sorts the pivot*/
template<typename T>
int Partition(Vector<T> &a, int low, int high){
    
    int pivot;
    int index;

        index = low;
    
    //Pivot is the last element of the array
        pivot = high;
    
    //Puts partition in the correct place
        for (int i = low; i < high; i++)
        {
            if(a[i] < a[pivot])
            {
                swap(a[i], a[index]);
                index++;
            }
        }
  
        swap(a[pivot], a[index]);
        
        return index;
    }



/**
 * Mergesort (driver function)
 */
template <typename T>
void mergeSort(Vector<T> &a){
    
    //Will hold sorted array temporarily
    Vector<T> tmpArray(a.size( ));
    
    mergeSort(a, tmpArray, 0, a.size( )-1);
    
}

//Recursively sort via MergeSort and then finally merge.
template <typename T>
void mergeSort(Vector<T> &a, Vector<T> &tmpArray, int left, int right ) {
    
    if (left < right ) {
        int center=(left+right)/2;
        
        mergeSort(a, tmpArray, left, center);
        mergeSort(a, tmpArray, center+1, right);
        merge(a, tmpArray, left, center+1, right );
    }
}

//Merge two arrays
template <typename T>
void merge(Vector<T> & a, Vector<T> &tmpArray, int leftpo, int rightpo, int rightEnd){
    int leftEnd = rightpo-1;
    int tmpo = leftpo;
    int numofE = rightEnd - leftpo+1;
    
    /*Populating temporary by comparing the elements of the left
     and right sub arrays*/
    while (leftpo <= leftEnd && rightpo <= rightEnd) {
        if (a[leftpo] <= a[rightpo]) {
            tmpArray[tmpo++] = move(a[leftpo++]);
        }
        else {
            tmpArray[tmpo++] = move(a[rightpo++]);
        }
    }
    
    while (leftpo <= leftEnd) {
        tmpArray[tmpo++] = move(a[leftpo++]);
    }
    
    while (rightpo <= rightEnd) {
        tmpArray[tmpo++] = move(a[rightpo++]);
    }
    
    //Repopulating original array
    for (int i = 0; i < numofE; ++i, --rightEnd) {
        a[rightEnd] = move(tmpArray[rightEnd]);
    }
    
}


    
    
#endif /* Vector_h */
