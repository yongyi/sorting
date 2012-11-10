/*
 * Script to test the codes in sorting. Will test both the integer case and character case.
 *
 * Yongyi Ye
 */

#include<iostream>
#include<stdlib.h>
#include"sorting.cpp"

using namespace std;

void shuffle(int* arr, int size);
/*
 * Function to randomly generate numbers to fill an array in the range of 0 to 999
 */

void print(int* arr, int size);
/*
 * Function to print an int array given the size.
 */

int main(){
    int size = 100;
    int* arr = new int[size];

    /* test insertion sort */
    cout << "INSERTION SORT" << endl;

    shuffle(arr, 100);
    cout << "the original array" << endl;
    print(arr, size);
    cout << endl;

    insertion_sort<int>(arr, size);
    cout << "after sorting" << endl;
    print(arr, size);
    cout << endl;


    /* test merge sort */
    cout << "MERGE SORT" << endl;

    shuffle(arr, 100);
    cout << "the original array" << endl;
    print(arr, size);
    cout << endl;

    merge_sort<int>(arr, size);
    cout << "after sorting" << endl;
    print(arr, size);
    cout << endl;


    /* test quick sort */
    cout << "QUICK SORT" << endl;

    shuffle(arr, 100);
    cout << "the original array" << endl;
    print(arr, size);
    cout << endl;

    quick_sort<int>(arr, size);
    cout << "after sorting" << endl;
    print(arr, size);
    cout << endl;

    /* test dijkstra 3-way quick sort */
    cout << "DIJKSTRA SORT" << endl;

    shuffle(arr, 100);
    cout << "the original array" << endl;
    print(arr, size);
    cout << endl;

    dijkstra_3_way<int>(arr, size);
    cout << "after sorting" << endl;
    print(arr, size);
    cout << endl;


}

void shuffle(int* arr, int size){
    for(int i=0; i<size; i++){
        arr[i] = rand()%1000;
    }
    return;
}

void print(int* arr, int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << "  ";
    }
    cout << endl;
    return;
}
