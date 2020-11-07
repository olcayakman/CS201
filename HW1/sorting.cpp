/**
 * Title: Algortihm Efficiency and Sorting
 * Author: Olcay Akman
 * ID: 2702671
 * Section: 3
 * Assignment : 1
 * Description: This file includes the implementations for the
 *              bubleSort, mergeSort, quickSort and radixSort
 *              functions and other necessarry functions used in
 *              these, as well as the printArray function and
 *              the performanceAnalysis function to print arrays
 *              and examine the performances of each of these
 *              sorting functions.
*/

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
//#include <chrono>
#include "sorting.h"
using namespace std;

void bubbleSort(int *arr, int size, int &compCount, int &moveCount)
{
    compCount = 0;
    moveCount = 0;

    bool sorted = false; 
   
	for (int pass = 1; (pass < size) && !sorted; ++pass) {
        sorted = true; 
        for (int index = 0; index < size-pass; ++index) {
            int nextIndex = index + 1;
            if (arr[index] > arr[nextIndex]) { 
                swap(arr[index], arr[nextIndex]);
                moveCount += 3;                  //27
                sorted = false; // signal exchange
            }
            ++compCount; //28
        }
    }
}

//-----------------------------------------------------------------

void quickSort(int *arr, int size, int &compCount, int &moveCount)
{
    int pivotIndex = 0;
    if ( size > 1 )
    {
        myPartition(arr, 0, size - 1, pivotIndex, compCount, moveCount);
        quickSubSort(arr, 0, pivotIndex - 1, compCount, moveCount);
        quickSubSort(arr, pivotIndex + 1, size - 1, compCount, moveCount);
    }
}

void quickSubSort(int *arr, int s, int e, int &compCount, int &moveCount)
{
    int pivotIndex;
    if ( s < e )
    {
        myPartition(arr, s, e, pivotIndex, compCount, moveCount);
        quickSubSort(arr, s, pivotIndex - 1, compCount, moveCount);
        quickSubSort(arr, pivotIndex + 1, e, compCount, moveCount);
    }
}

void myPartition(int *arr, int s, int e, int &pivotIndex, int &compCount, int &moveCount)
{
    pivotIndex = s;
    int pivot = arr[s]; //move
    ++moveCount;
    int tailS1 = s;
    int firstUnknown = s + 1;
    for ( ; firstUnknown <= e; ++firstUnknown)
    {
        if ( arr[firstUnknown] < pivot ) //comparison
        {
            ++compCount;
            ++tailS1;
            swap(arr[firstUnknown], arr[tailS1]); //3 moves
            moveCount += 3;
        }
    }
    swap(arr[s], arr[tailS1]); //3 moves
    moveCount += 3;
    pivotIndex = tailS1;
}

//-----------------------------------------------------------------

void mergeSort(int *arr, int size, int &compCount, int &moveCount)
{
    int s = 0;
    int e = size - 1;
    int mid = (s + e) / 2;
    mergeSubSort(arr, size, s, mid, compCount, moveCount);
    mergeSubSort(arr, size, mid + 1, e, compCount, moveCount);
    merge(arr, size, s, mid, e, compCount, moveCount);
}

void mergeSubSort(int *arr, int size, int s, int e, int &compCount, int &moveCount)
{
    if ( s < e )
    {
        int mid = (s + e) / 2;
        mergeSubSort(arr, size, s, mid, compCount, moveCount);
        mergeSubSort(arr, size, mid + 1, e, compCount, moveCount);
        merge(arr, size, s, mid, e, compCount, moveCount);
    }
}

void merge(int *arr, int size, int s, int mid, int e, int &compCount, int &moveCount)
{
    int tempArray[size];
    int head1 = s;
    int tail1 = mid;
    int head2 = mid + 1;
    int tail2 = e;
    int index = head1;
    for ( ; (head1 <= tail1) && (head2 <= tail2); ++index)
    {
        if (arr[head1] < arr[head2]) //comp
        {
            ++compCount;
            tempArray[index] = arr[head1]; //move
            ++moveCount;
            ++head1;
        } else {
            tempArray[index] = arr[head2]; //move
            ++moveCount;
            ++head2;
        }
    }
    for ( ; head1 <= tail1; ++head1, ++index)
    {
        tempArray[index] = arr[head1]; //move
        ++moveCount;
    }
    for ( ; head2 <= tail2; ++head2, ++index)
    {
        tempArray[index] = arr[head2]; //move
        ++moveCount;
    } 
    for (index = s; index <= e; ++index)
    {
        arr[index] = tempArray[index]; //move
        ++moveCount;
    }
}

//-----------------------------------------------------------------

void radixSort(int *arr, int size)
{
    int group0[MAX_SIZE];
    int group1[MAX_SIZE];
    int group2[MAX_SIZE];
    int group3[MAX_SIZE];
    int group4[MAX_SIZE];
    int group5[MAX_SIZE];
    int group6[MAX_SIZE];
    int group7[MAX_SIZE];
    int group8[MAX_SIZE];
    int group9[MAX_SIZE];

    for ( int i = size - 1; i <= 0; i++ )
    {
        //todo
    }
}

//-----------------------------------------------------------------

void printArray(int *arr, int size)
{
    for ( int i = 0; i < size; i++ )
        cout<<arr[i]<<"  ";
}

//-----------------------------------------------------------------


void performanceAnalysis()
{
    int moveCount, compCount;
    srand( (int)time(0) );

    int array2k[2000];
    int array6k[6000];
    int array10k[10000];
    int array14k[14000];
    int array18k[18000];
    int array22k[22000];
    int array26k[26000];
    int array30k[30000];
    
    double duration;
    for ( int i = 0; i < 2000; i++)
        array2k[i] = (rand() % 1000);
    int *array2kPtr = array6k;
    clock_t startTime = clock();
    radixSort(array2k, 2000);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"2000\t\t"<<duration<<"\n";

    for ( int i = 0; i < 6000; i++)
        array6k[i] = (rand() % 1000);
    int *array6kPtr = array6k;
    startTime = clock();
    radixSort(array6kPtr, 6000);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"6000\t\t"<<duration<<"\n";

    int *array10kPtr = array10k;
    startTime = clock();
    radixSort(array10kPtr, 10000);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"10000\t\t"<<duration<<"\n";

    int *array14kPtr = array14kPtr;
    startTime = clock();
    radixSort(array14kPtr, 14000);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"14000\t\t"<<duration<<"\n";

    
    int *array18kPtr = array18k;
    startTime = clock();
    radixSort(array18kPtr, 18000);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"18000\t\t"<<duration<<"\n";

   
    int *array22kPtr = array22k;
    startTime = clock();
    radixSort(array22kPtr, 22000);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"22000\t\t"<<duration<<"\n";

   
    int *array26kPtr = array26k;
    startTime = clock();
    radixSort(array26kPtr, 26000);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"26000\t\t"<<duration<<"\n";

    
    int *array30kPtr = array30k;
    startTime = clock();
    radixSort(array30kPtr, 30000);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"30000\t\t"<<duration<<"\n";



    //*********************************************************


    cout<<"------------------------------------------------\n";
    cout<<"Part c - Time Analysis of Bubble Sort\n";
    cout<<"Array Size\tTime Elapsed\tCompCount\tMoveCount\n";

    for ( int i = 0; i < 2000; i++)
        array2k[i] = (rand() % 1000);
    duration;
    startTime = clock();
    bubbleSort(array2kPtr, 2000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"2000\t\t"<<duration<<"\n";

    for ( int i = 0; i < 6000; i++)
        array6k[i] = (rand() % 1000);
    startTime = clock();
    bubbleSort(array6kPtr, 6000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"6000\t\t"<<duration<<"\n";

    for ( int i = 0; i < 10000; i++)
        array10k[i] = (rand() % 1000);
    startTime = clock();
    bubbleSort(array10kPtr, 10000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"10000\t\t"<<duration<<"\n";

    for ( int i = 0; i < 14000; i++)
        array14k[i] = (rand() % 1000);
    startTime = clock();
    bubbleSort(array14kPtr, 14000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"14000\t\t"<<duration<<"\n";

    for ( int i = 0; i < 18000; i++)
        array18k[i] = (rand() % 1000);
    startTime = clock();
    bubbleSort(array18kPtr, 18000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"18000\t\t"<<duration<<"\n";

    for ( int i = 0; i < 22000; i++)
        array22k[i] = (rand() % 1000);
    startTime = clock();
    bubbleSort(array22kPtr, 22000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"22000\t\t"<<duration<<"\n";

    for ( int i = 0; i < 26000; i++)
        array26k[i] = (rand() % 1000);
    startTime = clock();
    bubbleSort(array26kPtr, 26000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"26000\t\t"<<duration<<"\n";

    for ( int i = 0; i < 30000; i++)
        array30k[i] = (rand() % 1000);
    startTime = clock();
    bubbleSort(array30kPtr, 30000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"30000\t\t"<<duration<<"\n";


    //*********************************************************


    cout<<"------------------------------------------------\n";
    cout<<"Part c - Time Analysis of Quick Sort\n";
    cout<<"Array Size\tTime Elapsed\tCompCount\tMoveCount\n";

    for ( int i = 0; i < 2000; i++)
        array2k[i] = (rand() % 1000);
    duration;
    startTime = clock();
    quickSort(array2kPtr, 2000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"2000\t\t"<<duration<<"\n";

    for ( int i = 0; i < 6000; i++)
        array6k[i] = (rand() % 1000);
    startTime = clock();
    quickSort(array6kPtr, 6000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"6000\t\t"<<duration<<"\n";

    for ( int i = 0; i < 10000; i++)
        array10k[i] = (rand() % 1000);
    startTime = clock();
    quickSort(array10kPtr, 10000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"10000\t\t"<<duration<<"\n";

    for ( int i = 0; i < 14000; i++)
        array14k[i] = (rand() % 1000);
    startTime = clock();
    quickSort(array14kPtr, 14000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"14000\t\t"<<duration<<"\n";

    for ( int i = 0; i < 18000; i++)
        array18k[i] = (rand() % 1000);
    startTime = clock();
    quickSort(array18kPtr, 18000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"18000\t\t"<<duration<<"\n";

    for ( int i = 0; i < 22000; i++)
        array22k[i] = (rand() % 1000);
    startTime = clock();
    quickSort(array22kPtr, 22000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"22000\t\t"<<duration<<"\n";

    for ( int i = 0; i < 26000; i++)
        array26k[i] = (rand() % 1000);
    startTime = clock();
    quickSort(array26kPtr, 26000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"26000\t\t"<<duration<<"\n";

    for ( int i = 0; i < 30000; i++)
        array30k[i] = (rand() % 1000);
    startTime = clock();
    quickSort(array30kPtr, 30000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"30000\t\t"<<duration<<"\n";


    //*********************************************************


    cout<<"------------------------------------------------\n";
    cout<<"Part c - Time Analysis of Merge Sort\n";
    cout<<"Array Size\tTime Elapsed\tCompCount\tMoveCount\n";

    for ( int i = 0; i < 2000; i++)
        array2k[i] = (rand() % 1000);
    duration;
    startTime = clock();
    mergeSort(array2kPtr, 2000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"2000\t\t"<<duration<<"\n";

    for ( int i = 0; i < 6000; i++)
        array6k[i] = (rand() % 1000);
    startTime = clock();
    mergeSort(array6kPtr, 6000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"6000\t\t"<<duration<<"\n";

    for ( int i = 0; i < 10000; i++)
        array10k[i] = (rand() % 1000);
    startTime = clock();
    mergeSort(array10kPtr, 10000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"10000\t\t"<<duration<<"\n";

    for ( int i = 0; i < 14000; i++)
        array14k[i] = (rand() % 1000);
    startTime = clock();
    mergeSort(array14kPtr, 14000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"14000\t\t"<<duration<<"\n";

    for ( int i = 0; i < 18000; i++)
        array18k[i] = (rand() % 1000);
    startTime = clock();
    mergeSort(array18kPtr, 18000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"18000\t\t"<<duration<<"\n";

    for ( int i = 0; i < 22000; i++)
        array22k[i] = (rand() % 1000);
    startTime = clock();
    mergeSort(array22kPtr, 22000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"22000\t\t"<<duration<<"\n";

    for ( int i = 0; i < 26000; i++)
        array26k[i] = (rand() % 1000);
    startTime = clock();
    mergeSort(array26kPtr, 26000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"26000\t\t"<<duration<<"\n";

    for ( int i = 0; i < 30000; i++)
        array30k[i] = (rand() % 1000);
    startTime = clock();
    mergeSort(array30kPtr, 30000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime ) / CLOCKS_PER_SEC;
    cout<<"30000\t\t"<<duration<<"\n";
    cout<<"------------------------------------------------\n";

}