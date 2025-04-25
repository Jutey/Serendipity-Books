#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

template<typename T>
struct node
{
  T data;
  node* next;
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
    node<T>* newNode = new node<T>{value, nullptr};
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
    node<T>* previous = nullptr;

    while (current != nullptr)
    {
      if (current->data == value)
      {
        if (previous != nullptr)
        {
          previous->next = current->next;
        }
        else
        {
          head = current->next;
        }

        if (current == tail)
        {
          tail = previous;
        }

        delete current;
        --size;
        --totalNodes;
        return;
      }

      previous = current;
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
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << std::endl;
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
};

// Initialize static members
template<typename T>
int linkedList<T>::totalNodes = 0;

template<typename T>
int linkedList<T>::totalLists = 0;

#endif
