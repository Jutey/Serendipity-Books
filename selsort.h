/******************************************************************************
* Assignment: Exam 3
* Purpose: Serendipity Final Project
* Authors: Kenny Strawn, Romewin Villacorte, William Donnell-Crume, Cade Coxon
* Due Date: 5/21/2025
*******************************************************************************/

#ifndef SELSORT_H
#define SELSORT_H

#include <vector>
#include <functional>
#include "linkedlist.h"
#include "orderedLinkedList.h"

using namespace std;

template <typename T>
void selectionSort(orderedLinkedList<T*>& arr, function<bool(const T*, const T*)> compare)
{
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i)
  {
    int minIndex = i;
    for (int j = i + 1; j < n; ++j)
    {
      T* a = arr.get(j);
      T* b = arr.get(minIndex);
      if (a && b && compare(a, b))
      {
        minIndex = j;
      }
    }
    if (minIndex != i)
    {
      T* tempA = arr.get(i);
      T* tempB = arr.get(minIndex);
      if (tempA && tempB)
      {
        std::swap(*tempA, *tempB);
      }
    }
  }
}

// Overload for iterator-based containers (e.g., std::vector<T*>)
template <typename RandomIt, typename Compare>
void selectionSort(RandomIt first, RandomIt last, Compare comp)
{
  for (auto i = first; i != last; ++i) {
    auto minIt = i;
    for (auto j = i + 1; j != last; ++j) {
      if (comp(*j, *minIt)) {
          minIt = j;
      }
    }
    if (minIt != i) {
      std::swap(*i, *minIt);
    }
  }
}

#endif // SELSORT_H