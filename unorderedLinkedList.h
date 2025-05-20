/******************************************************************************
* Assignment: Exam 3
* Purpose: Serendipity Final Project
* Authors: Kenny Strawn, Romewin Villacorte, William Donnell-Crume, Cade Coxon
* Due Date: 5/21/2025
*******************************************************************************/

#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList  

#include "linkedlist.h"
 
using namespace std; 

template <class Type> 
class unorderedLinkedList: public linkedListType<Type>
{
using linkedListType<Type>::head;
using linkedListType<Type>::tail;
using linkedListType<Type>::count;

public:
    bool search(const Type& searchItem) const;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the 
      //               list, otherwise the value false is 
      //               returned.

    void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //               inserted at the beginning of the list,
      //               last points to the last node in the  
      //               list, and count is incremented by 1.

    void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem 
      //               is inserted at the end of the list,
      //               last points to the last node in the 
      //               list, and count is incremented by 1.

    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing 
      //               deleteItem is deleted from the list.
      //               first points to the first node, last
      //               points to the last node of the updated 
      //               list, and count is decremented by 1.
};


template <class Type>
bool unorderedLinkedList<Type>::
                   search(const Type& searchItem) const
{
    nodeType<Type> *current; //pointer to traverse the list
    bool found = false;
    
    current = head; //set current to point to the first 
                     //node in the list

    while (current != nullptr && !found)    //search the list
        if (current->data == searchItem) //searchItem is found
            found = true;
        else
            current = current->next; //make current point to
                                     //the next node
    return found; 
}//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->data = newItem;    //store the new item in the node
    newNode->next = head;      //insert newNode before first
    head = newNode;            //make first point to the
                                //actual first node
    count++;                    //increment count

    if (tail == nullptr)   //if the list was empty, newNode is also 
                        //the last node in the list
        tail = newNode;
}//end insertFirst

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->data = newItem;  //store the new item in the node
    newNode->next = nullptr;     //set the next field of newNode
                              //to nullptr

    if (head == nullptr)  //if the list is empty, newNode is 
                        //both the first and last node
    {
        head = newNode;
        tail = newNode;
        count++;        //increment count
    }
    else    //the list is not empty, insert newNode after last
    {
        tail->next = newNode; //insert newNode after last
        tail = newNode; //make last point to the actual 
                        //last node in the list
        count++;        //increment count
    }
}//end insertLast


template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;

    if (head == nullptr)    //Case 1; the list is empty. 
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        if (head->data == deleteItem) //Case 2 
        {
            current = head;
            head = head->next;
            count--;
            if (head == nullptr)    //the list has only one node
                tail = nullptr;
            delete current;
        }
        else //search the list for the node with the given data
        {
            found = false;
            trailCurrent = head;  //set trailCurrent to point
                                   //to the first node
            current = head->next; //set current to point to 
                                   //the second node

            while (current != nullptr && !found)
            {
                if (current->data != deleteItem) 
                {
                    trailCurrent = current;
                    current = current->next;
                }
                else
                    found = true;
            }//end while

            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->next = current->next;
                count--;

                if (tail == current)   //node to be deleted 
                                       //was the last node
                    tail = trailCurrent; //update the value 
                                         //of last
                delete current;  //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }//end else
    }//end else
}//end deleteNode


#endif
