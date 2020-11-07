/**
 * Title: Algortihm Efficieny and Sorting
 * Author: Olcay Akman
 * ID: 21702671
 * Section: 3
 * Assignment: 1
 * Description: sorting.h (refer to the header of 
 *              the file sorting.cpp for more info)
 */

#ifndef sorting_h
#define sorting_h

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
//#include <chrono>
using namespace std;

const int MAX_SIZE = 20;

void bubbleSort(int *arr, int size, int &compCount, int &moveCount);

void quickSort(int *arr,int size, int &compCount, int &moveCount);
void quickSubSort(int *arr, int s, int e, int &compCount, int &moveCount);
void myPartition(int *arr, int s, int e, int &pivotIndex, int &compCount, int &moveCount);

void mergeSort(int *arr, int size, int &compCount, int &moveCount);
void mergeSubSort(int *arr, int size, int s, int e, int &compCount, int &moveCount);
void merge(int *arr, int size, int s, int mid, int e, int &compCount, int &moveCount);

void radixSort(int *arr, int size);

void printArray(int *arr, int size);
void performanceAnalysis();

#endif