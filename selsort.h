/********************************************************************************
* Assignment: Exam 2
* Purpose: Course Enrollment System (AKA rewrite of SOCCCD MySite backend in C++)
* Author: Kenny Strawn
* Due Date: 4/23/2025
********************************************************************************/

#ifndef SELSORT_H
#define SELSORT_H

#include <vector>
#include <functional>

using namespace std;

template <typename T>
void selectionSort(vector<T*>& arr, function<bool(const T*, const T*)> compare)
{
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (compare(arr[j], arr[minIndex])) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

#endif // SELSORT_H