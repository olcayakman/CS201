/**
 * Title: Algorithm Efficieny and Sorting
 * Author: Olcay Akman
 * ID: 21702671
 * Section: 3
 * Assignment: 1
 * Description: ...
 */

#include "sorting.h"
#include <iostream>

using namespace std;

int main()
{
    const int MAX_SIZE = 20;
    int arr[MAX_SIZE] = {7,3,6,12,13,4,1,9,15,0,11,14,2,8,10,5};
    int *a = arr;
    
    cout<<"Initial state of the array: \n";
    printArray(a, 16);
    cout<<"\n";
    cout<<"***************************************";
    cout<<"\n";

    int compCount, moveCount;
    bubbleSort(a, 16, compCount, moveCount);
    cout<<"\n";
    cout<<"************** bubbleSort **************";
    cout<<"\n";
    printArray(a, 16);
    cout<<"\n";
    cout<<"***************************************";
    cout<<"\n";

    quickSort(a, 16, compCount, moveCount);
    cout<<"\n";
    cout<<"************** quickSort **************";
    cout<<"\n";
    printArray(a, 16);
    cout<<"\n";
    cout<<"***************************************";
    cout<<"\n";

    mergeSort(a, 16, compCount, moveCount);
    cout<<"\n";
    cout<<"************** mergeSort **************";
    cout<<"\n";
    printArray(a, 16);
    cout<<"\n";
    cout<<"***************************************";
    cout<<"\n";

    radixSort(a, 16);
    cout<<"\n";
    cout<<"************** radixSort **************";
    cout<<"\n";
    printArray(a, 16);
    cout<<"\n";
    cout<<"***************************************";
    cout<<"\n";

    performanceAnalysis();


    return 0;
}