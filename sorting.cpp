/*
 * implementation of the sorting algorithms.
 *
 * Yongyi Ye
 */

#ifndef SORTING_CPP
#define SORTING_CPP

#include<assert.h>
using namespace std;

#include"sorting.hpp"

/***** declaration of private helper functions *****/

template<typename T>
bool is_sorted(T* arr, int size);
/*
 * Function to check if the array is sorted
 *
 * input: arr - pointer to the head of the array to be sorted
 *       size - size of the array
 *
 * output: boolean value indicating whether the array is sorted or not
 */

template<typename T>
void merge_sort(T* arr, T* copy, int low, int high);
/*
 * Function to perform the actual merge sort recursively
 * Using an additional array to perform the tasks.
 *
 * input: arr - the array to be sorted
 *        copy - the array served as temporary holder
 *        low - position of lower bound of the array to be sorted
 *        high - position of higher bound of the array to be sorted
 *
 * output: no returning, performs the tasks in place.
 */

template<typename T>
void merge(T* arr, T*copy, int low, int mid, int high);
/*
 * Function to perform the merging of two sorted sub-arrays into one sorted array.
 * The two arrays are occupying consecutive blocks of memory.
 *
 * input: arr - the array to be sorted
 *       copy - the array served as temporary holder when doing the merging
 *        low - lower bound of the first sub-array
 *        mid - higher bound of the first sub-array, higher bound of the second sub-array
 *       high - higher bound of the second sub-array
 *
 * output: no returns. all changes are in place.
 */

template<typename T>
void quick_sort(T* arr, int low, int high);
/*
 * Function to perform quick sort in place and partition part of the array given the low
 * and upper bounds of an array.
 *
 * input: arr - pointer to the head of the array to be sorted
 *        low - lower bound of the part of array to be sorted
 *       high - upper bound of the part array to be sorted
 *
 * output: no returns.
 */

template<typename T>
int partition(T* arr, int low, int high);
/*
 * Function to partition the array(or part of the array) by referring to the first element,
 * so that after the partitioning the exchanging, the first element is in place.
 *
 * input: arr - pointer to the head of the array to be sorted
 *        low - lower bound of the part of array to be sorted
 *       high - upper bound of the part array to be sorted
 *
 * output: the position of the in-place element will be returned.
 */

template<typename T>
void dijkstra(T* arr, int low, int high);
/*
 * Function to sort an array of items of type T using dijkstra's modified algorithm for  quick
 * sort that deals with duplicate keys effectively.
 *
 * input: arr - pointer to the head of the array to be sorted
 *        low - lower bound of the part of array to be sorted
 *       high - upper bound of the part array to be sorted
 *
 * output: no returning.
 */



/*****   end   *****/


/* insertion sort */
template<typename T>
void insertion_sort(T* arr, int size){
    for(int i=1; i<size; i++){
        for(int j=i; j>0; j--){
        //compare two consecutive elements from right to left
            if(arr[j] < arr[j-1]){
                //switch the elements when an element is larger than the one on left
                T temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }else{
                //break if the element is in place
                break;
            }
        }
    }
    assert(is_sorted<T>(arr, size));
}


/* merge sort */
template<typename T>
void merge_sort(T* arr, int size){
    T* copy = new T[size];
    merge_sort<T>(arr, copy, 0, size-1);
    delete[] copy;
    assert(is_sorted<T>(arr, size));
}


/* quick sort */
template<typename T>
void quick_sort(T* arr, int size){
    quick_sort<T>(arr, 0, size-1);
    assert(is_sorted<T>(arr, size));
}


/* dijkstra 3-way quick sort */
template<typename T>
void dijkstra_3_way(T* arr, int size){
    dijkstra<T>(arr, 0, size-1);
    int i = 0;
    assert(is_sorted<T>(arr, size));
}


/********* private helper functions ********/

template<typename T>
bool is_sorted(T* arr, int size){
/*
 * Function to check if the array is sorted
 *
 * input: arr - pointer to the head of the array to be sorted
 *       size - size of the array
 *
 * output: boolean value indicating whether the array is sorted or not
 */
    for(int i=0; i<size-1; i++){
        if(arr[i]>arr[i+1]){ return false; }
    }
    return true;
}

template<typename T>
void merge_sort(T* arr, T* copy, int low, int high){
/*
 * Function to perform the actual merge sort recursively
 * Using an additional array to perform the tasks.
 *
 * input: arr - the array to be sorted
 *        copy - the array served as temporary holder
 *        low - position of lower bound of the array to be sorted
 *        high - position of higher bound of the array to be sorted
 *
 * output: no returning, performs the tasks in place.
 */
    if( high <= low){ return; }
    else{
        //the partition position
        int mid =  (low+high)/2;
        merge_sort<T>(arr, copy, low, mid);
        merge_sort<T>(arr, copy, mid+1, high);
        merge<T>(arr, copy, low, mid, high);
        return;
    }
}

template<typename T>
void merge(T* arr, T* copy, int low, int mid, int high){
/*
 * Function to perform the merging of two sorted sub-arrays into one sorted array.
 * The two arrays are occupying consecutive blocks of memory.
 *
 * input: arr - the array to be sorted
 *       copy - the array served as temporary holder when doing the merging
 *        low - lower bound of the first sub-array
 *        mid - higher bound of the first sub-array, higher bound of the second sub-array
 *       high - higher bound of the second sub-array
 *
 * output: no returns. all changes are in place.
 */

    //copy the contents of the two sub-arrays into the temporary holder
    for(int i=low; i<=high; i++){ copy[i] = arr[i]; }

    //positional pointer for the sub-arrays
    int ptr_1 = low;
    int ptr_2 = mid+1;

    for(int i=low; i<=high; i++){
        //if the first sub-array is exhausted
        if(ptr_1 > mid){
            arr[i] = copy[ptr_2++];
        }
        //if the second sub-array is exhausted
        else if(ptr_2 > high){
            arr[i] = copy[ptr_1++];
        }
        //comparison of the elements in the sub-arrays
        else if(copy[ptr_1] < copy[ptr_2]){
            arr[i] = copy[ptr_1++];
        }
        else{
            arr[i] = copy[ptr_2++];
        }
    }
}

template<typename T>
void quick_sort(T* arr, int low, int high){
/*
 * Function to perform quick sort in place and partition part of the array given the low
 * and upper bounds of an array.
 *
 * input: arr - pointer to the head of the array to be sorted
 *        low - lower bound of the part of array to be sorted
 *       high - upper bound of the part array to be sorted
 *
 * output: no returns.
 */
    if(high <= low){ return; }
    else{
        int j = partition<T>(arr, low, high);
        quick_sort<T>(arr, low, j-1);
        quick_sort<T>(arr, j+1, high);
        return;
    }
}

template<typename T>
int partition(T* arr, int low, int high){
/*
 * Function to partition the array(or part of the array) by referring to the first element,
 * so that after the partitioning the exchanging, the first element is in place.
 *
 * input: arr - pointer to the head of the array to be sorted
 *        low - lower bound of the part of array to be sorted
 *       high - upper bound of the part array to be sorted
 *
 * output: the position of the in-place element will be returned.
 */
    //two pointers one searching from left to right and one from right to left
    int i = low+1;
    int j = high;

    //the element that is to be compared against with
    T pivot = arr[low];

    while(true){

        while(arr[i] < pivot){
            if(i >= high) break;
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        //exchange i and j if i and j don't go across each other
        if(j <= i){ break; }

        T temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }

    //exchange the first element with the element at position j
    T temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;
    return j;
}


template<typename T>
void dijkstra(T* arr, int low, int high){
/*
 * Function to sort an array of items of type T using dijkstra's modified algorithm for quick
 * sort that deals with duplicate keys effectively.
 *
 * input: arr - pointer to the head of the array to be sorted
 *        low - lower bound of the part of array to be sorted
 *       high - upper bound of the part array to be sorted
 *
 * output: no returning.
 */
    if(high <= low){ return; }

    //recursive part

    int lo = low;   //tracker of the lower bound of duplicate elements, also pointing to the pivot element
    int hi = high;  //tracker of upper bound of duplicate elements

    int i = low+1;  //the moving scanner to partition the keys

    while(true){
        //terminate if the scanner go across the upper bound of duplicate keys
        if(i > hi){ break; }

        //move smaller-than-pivot elements to the left
        if(arr[i] < arr[lo]){
            T temp = arr[i];
            arr[i] = arr[lo];
            arr[lo] = temp;

            i++;
            lo++;
        }

        //move larger-than-pivot elements to the right
        if(arr[i] > arr[lo]){
            T temp = arr[i];
            arr[i] = arr[hi];
            arr[hi] = temp;

            hi--;
        }

        //only increment the scanner if the keys are equal
        if(arr[i] == arr[lo]){
            i++;
        }

    }

    //recursion
    dijkstra<T>(arr, low, lo-1);
    dijkstra<T>(arr, hi+1, high);

    return;
}
#endif
