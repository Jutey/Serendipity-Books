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

public:
  linkedList() : head(nullptr), tail(nullptr), size(0) {}

  ~linkedList()
  {
    while (head != nullptr)
    {
      node<T>* temp = head;
      head = head->next;
      delete temp;
    }
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
};

#endif
