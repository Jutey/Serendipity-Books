#ifndef H_orderedListType
#define H_orderedListType
 
#include "linkedlist.h"
 
using namespace std; 
 
template <class Type>
class orderedLinkedList: public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const; 
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the 
      //               list, otherwise it returns false.

    void insert(const Type& newItem);
      //Function to insert newItem in the list.
      //Postcondition: first points to the new list, newItem 
      //               is inserted at the proper place in the
      //               list, and count is incremented by 1.

    void insertFirst(const Type& newItem);
      //Function to insert newItem in the list.
      //Because the resulting list must be sorted, newItem is 
      //inserted at the proper in the list.
      //This function uses the function insert to insert newItem.
      //Postcondition: first points to the new list, newItem is
      //               inserted at the proper in the list,
      //               and count is incremented by 1.

    void insertLast(const Type& newItem);
      //Function to insert newItem in the list.
      //Because the resulting list must be sorted, newItem is 
      //inserted at the proper in the list.
      //This function uses the function insert to insert newItem.
      //Postcondition: first points to the new list, newItem is
      //               inserted at the proper in the list,
      //               and count is incremented by 1.

    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing 
      //               deleteItem is deleted from the list;
      //               first points to the first node of the 
      //               new list, and count is decremented by 1.
      //               If deleteItem is not in the list, an
      //               appropriate message is printed.
};


template <class Type>
bool orderedLinkedList<Type>::
                 search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type> *current; //pointer to traverse the list

    current = head;  //start the search at the first node

    while (current != nullptr && !found)
        if (current->data >= searchItem)
            found = true;
        else
            current = current->next;
 
    if (found)
       found = (current->data == searchItem); //test for equality

    return found;
}//end search


template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent = nullptr; //pointer just 
                                      //before current
    nodeType<Type> *newNode;  //pointer to create a node

    bool  found;

    newNode = new nodeType<Type>; //create the node
    newNode->data = newItem;  //store newItem in the node
    newNode->next = nullptr;  //set the link field of the node
                              //to nullptr

    if (head == nullptr)  //Case 1
    {
        head = newNode;
        tail = newNode;
        count++;
    }
    else
    {
        current = head;
        found = false;

        while (current != nullptr && !found) //search the list
           if (current->data >= newItem)
               found = true;
           else
           {
               trailCurrent = current;
               current = current->next;
           }
 
        if (current == head)      //Case 2
        {
            newNode->next = head;
            head = newNode;
            count++;
        }
        else                       //Case 3
        {
            trailCurrent->next = newNode;
            newNode->next = current;

            if (current == nullptr)
                tail = newNode;

            count++;
        }
    }//end else
}//end insert

template<class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    insert(newItem);
}//end insertFirst

template<class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
    insert(newItem);
}//end insertLast

template<class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent = nullptr; //pointer just 
                                            //before current
    bool found;

    if (head == nullptr) //Case 1
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        current = head;
        found = false;

        while (current != nullptr && !found)  //search the list
            if (current->data >= deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->next;
            }

        if (current == nullptr)   //Case 4
            cout << "The item to be deleted is not in the " 
                 << "list." << endl;
        else
            if (current->data == deleteItem) //the item to be 
                                   //deleted is in the list
            {
                if (head == current)       //Case 2
                {
                    head = head->next;

                    if (head == nullptr)
                        tail = nullptr;

                    delete current;
                }
                else                         //Case 3
                {
                    trailCurrent->next = current->next;

                    if (current == tail)
                        tail = trailCurrent;

                    delete current;
                }
                count--;
            }
            else                            //Case 4
                cout << "The item to be deleted is not in the "
                     << "list." << endl;
    }
}//end deleteNode


#endif