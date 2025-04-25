#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template<typename T>
struct node
{
  T data;
  node* next;
  node* prev;
};

// Because this is defined as a template, we risk compiler errors if this code is moved to a different file.
template<typename T>
class linkedList
{
private:
  node<T>* head;
  node<T>* tail;
  int size;
  static int totalNodes;
  static int totalLists;

public:
  linkedList() : head(nullptr), tail(nullptr), size(0)
  {
    ++totalLists;
  }

  ~linkedList()
  {
    while (head != nullptr)
    {
      node<T>* temp = head;
      head = head->next;
      delete temp;
      --totalNodes;
    }
    --totalLists;
  }

  void addNode(const T& value)
  {
    node<T>* newNode = new node<T>{value, nullptr, tail};
    if (tail != nullptr)
    {
      tail->next = newNode;
    }
    else
    {
      head = newNode;
    }
    tail = newNode;
    ++size;
    ++totalNodes;
  }

  void deleteNode(const T& value)
  {
    node<T>* current = head;

    while (current != nullptr)
    {
      if (current->data == value)
      {
        if (current->prev != nullptr)
        {
          current->prev->next = current->next;
        }
        else
        {
          head = current->next;
        }

        if (current->next != nullptr)
        {
          current->next->prev = current->prev;
        }
        else
        {
          tail = current->prev;
        }

        delete current;
        --size;
        --totalNodes;
        return;
      }

      current = current->next;
    }
  }

  bool isEmpty() const
  {
    return size == 0;
  }

  int getSize() const
  {
    return size;
  }

  void display() const
  {
    node<T>* current = head;
    while (current != nullptr)
    {
      cout << current->data << endl;
      current = current->next;
    }
    cout << endl;
  }

  void displayReverse() const
  {
    node<T>* current = tail;
    while (current != nullptr)
    {
      cout << current->data << " ";
      current = current->prev;
    }
    cout << endl;
  }

  // Getters for static members
  static int getTotalNodes()
  {
    return totalNodes;
  }

  static int getTotalLists()
  {
    return totalLists;
  }

  T getNodeData(int index) const
  {
    if (index < 0 || index >= size)
    {
      throw out_of_range("Index out of range");
    }

    node<T>* current = head;
    for (int i = 0; i < index; ++i)
    {
      current = current->next;
    }

    return current->data;
  }
};

// Initialize static members
template<typename T>
int linkedList<T>::totalNodes = 0;

template<typename T>
int linkedList<T>::totalLists = 0;

#endif
