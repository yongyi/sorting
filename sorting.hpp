/*
 * Declaration of the sorting methods, including insertion sort, merge sort,
 *      quick sort, and dijkstra 3-way quick sort, to sort an array in ascending
 *      order, assuming that the comparison operators are defined.
 *
 * Implemented using generic approach.
 *
 * Yongyi Ye
 */

#ifndef SORTING_HPP
#define SORTING_HPP

template<typename T>
void insertion_sort(T* arr, int size);
/*
 * Function that performs insertion sort to sort an array of objects of type T.
 *
 * input: arr - pointer pointing to the head of the array
 *        size - size of the array
 *
 * output: does not return anything but change the array in place
 */

template<typename T>
void merge_sort(T* arr, int size);
/*
 * Function that performs merge sort to sort an array of objects of type T.
 *
 * input: arr - pointer pointing to the head of the array
 *        size - size of the array
 *
 * output: does not return anything but change the array in place
 */


template<typename T>
void quick_sort(T* arr, int size);
/*
 * Function that performs quick sort to sort an array of objects of type T.
 *
 * input: arr - pointer pointing to the head of the array
 *        size - size of the array
 *
 * output: does not return anything but change the array in place
 */


template<typename T>
void dijkstra_3_way(T* arr, int size);
/*
 * Function that performs dijkstra 3-way quick sort to sort an array of objects of type T.
 * Good for arrays with duplicates.
 *
 * input: arr - pointer pointing to the head of the array
 *        size - size of the array
 *
 * output: does not return anything but change the array in place
 */



#ifndef SORTING_CPP
#include"sorting.cpp"
#endif

#endif
