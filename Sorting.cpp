#ifndef SORT_H
#define SORT_H

#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;


//////FUCNTION DECLARATIONS/////
template <typename Comparable>
void insertionSort(vector<Comparable> & a);

template <typename Comparable>
void insertionSort( vector<Comparable> & a, int left, int right );

template <typename Comparable>
void heapsort(vector<Comparable> & a);

template <typename Comparable>
void percDown(vector<Comparable> & a, int i, int n);

template <typename Comparable>
void mergeSort(vector<Comparable> & a, vector<Comparable> & tmpArray, int left, int right);

template <typename Comparable>
void mergeSort(vector<Comparable> & a);

template <typename Comparable>
void merge(vector<Comparable> & a, vector<Comparable> & tmpArray, int leftPos, int rightPos, int rightEnd);

template <typename Comparable>
void quicksort(vector<Comparable> & a);

template <typename Comparable>
const Comparable & median3(vector<Comparable> & a, int left, int right);

template <typename Comparable>
void quicksort(vector<Comparable> & a, int left, int right);

template <typename Comparable>
void print(vector<Comparable> & a);


int main()
{
    
    //in order to fairly sort the array and compare, comment out the srand and then run the program once for each type of sort

    unsigned long begin, end;
    long double ms;
    int numElements;
    cout << "How many things would you like in your vector" << endl;
    cin >> numElements;
    vector<int> myVector;
    vector<int> a;
    vector<int> x;
    vector<int> w;
    vector<int> z;


    srand (time(NULL));

    //for loop to populate the vector with random numbers
    for (int i=0; i<numElements; i++)
    {
        int randomNum;
        randomNum = rand() % 100;
        myVector.push_back(randomNum);
    } 


    char choice = 0;
    string answer;
    char y;

    cout << "Do you want to print the unsorted vector?" << endl;
    cin >> answer;
    if(answer == "yes" || "Yes")
    {
        for(int j=0;j<myVector.size();j++)
        {
            cout << myVector[j] << endl;
        }
        
    }


    do
    {
        ///////MENU///////
        cout << "Please choose which type of sort you would like:" << endl;
        cout << "Press 1 for insertion sort" << endl;
        cout << "Press 2 for heapsort" << endl;
        cout << "Press 3 for mergesort" << endl;
        cout << "Press 4 for quicksort" << endl;
        cout << "Press 5 to quit the program" << endl;
        cin >> choice;


        switch(choice)
        {
            case '1':
                cout << "insertion sort executed" << endl;
                a = myVector;
                begin = clock();
                insertionSort(a);
                end = clock();
                ms = (long double)(end-begin)/CLOCKS_PER_SEC;
                cout << "Time for insertion sort = " << ms << endl;
                cout << "Do you want to print the sorted vector?" << endl;
                cin >> answer;
                if(answer == "yes" || answer == "Yes")
                {
                    for(int j=0; j<a.size();j++)
                    {
                        cout << a[j] << endl;
                    }
                
                }
                else
                {
                    break;
                }
                break;

            case '2':
                cout << "heapsort executed" << endl;
                x = myVector;
                begin = clock();
                heapsort(x);
                end = clock();
                ms = (long double)(end-begin)/CLOCKS_PER_SEC;
                cout << "Time for heapsort = " << ms << endl;
                cout << "Do you want to print the sorted vector?" << endl;
                cin >> answer;
                if(answer == "yes" || answer == "Yes")
                {
                    for(int j=0; j<x.size();j++)
                    {
                        cout << x[j] << endl;
                    }
                
                }
                break;

            case '3':
                cout << "mergesort executed" << endl;
                w = myVector;
                begin = clock();
                mergeSort(w);
                end = clock();
                ms = (long double)(end-begin)/CLOCKS_PER_SEC;
                cout << "Time for insertion sort = " << ms << endl;
                cout << "Do you want to print the sorted vector?" << endl;
                cin >> answer;
                if(answer == "yes" || answer == "Yes")
                {
                    for(int j=0; j<w.size();j++)
                    {
                        cout << w[j] << endl;
                    }
                
                }
                break;

            case '4':
                cout << "quicksort executed" << endl;
                z = myVector;
                begin = clock();
                quicksort(z);
                end = clock();
                ms = (long double)(end-begin)/CLOCKS_PER_SEC;
                cout << "Time for quicksort = " << ms << endl;
                cout << "Do you want to print the sorted vector?" << endl;
                cin >> answer;
                if(answer == "yes" || answer == "Yes")
                {
                    for(int j=0; j<z.size();j++)
                    {
                        cout << z[j] << endl;
                    }
                
                }
                break;

            case '5':
                cout << "quitting the program..." << endl;
                break;
            
            default:
                cout << "Please make a selection" << endl;
                break; 
        } 
    } while(choice != '5');

}







//////Print Function//////
template <typename Comparable>
void print(vector<Comparable> & a)
{
    for(int i=0; i<a.size(); i++)
    {
        cout << a[i] << endl;
    }
    cout << endl;
}


////////INSERTION SORT////////////
template <typename Comparable>
void insertionSort( vector<Comparable> & a )
{
    for( int p = 1; p < a.size( ); ++p )
    {
        Comparable tmp = std::move( a[ p ] );

        int j;
        for( j = p; j > 0 && tmp < a[ j - 1 ]; --j )
            a[ j ] = std::move( a[ j - 1 ] );
        a[ j ] = std::move( tmp );
    }
}

template <typename Comparable>
void insertionSort( vector<Comparable> & a, int left, int right )
{
    for( int p = left + 1; p <= right; ++p )
    {
        Comparable tmp = std::move( a[ p ] );
        int j;

        for( j = p; j > left && tmp < a[ j - 1 ]; --j )
            a[ j ] = std::move( a[ j - 1 ] );
        a[ j ] = std::move( tmp );
    }
}


///////Heap Sort//////////////
/**
 * Standard heapsort.
 */
template <typename Comparable>
void heapsort( vector<Comparable> & a )
{
    for( int i = a.size( ) / 2 - 1; i >= 0; --i )  /* buildHeap */
        percDown( a, i, a.size( ) );
    for( int j = a.size( ) - 1; j > 0; --j )
    {
        std::swap( a[ 0 ], a[ j ] );               /* deleteMax */
        percDown( a, 0, j );
    }
}

/**
 * Internal method for heapsort.
 * i is the index of an item in the heap.
 * Returns the index of the left child.
 */
inline int leftChild( int i )
{
    return 2 * i + 1;
}

/**
 * Internal method for heapsort that is used in
 * deleteMax and buildHeap.
 * i is the position from which to percolate down.
 * n is the logical size of the binary heap.
 */
template <typename Comparable>
void percDown( vector<Comparable> & a, int i, int n )
{
    int child;
    Comparable tmp;

    for( tmp = std::move( a[ i ] ); leftChild( i ) < n; i = child )
    {
        child = leftChild( i );
        if( child != n - 1 && a[ child ] < a[ child + 1 ] )
            ++child;
        if( tmp < a[ child ] )
            a[ i ] = std::move( a[ child ] );
        else
            break;
    }
    a[ i ] = std::move( tmp );
}




////////MERGE SORT/////////
/**
 * Internal method that makes recursive calls.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void mergeSort( vector<Comparable> & a, vector<Comparable> & tmpArray, int left, int right )
{
    if( left < right )
    {
        int center = ( left + right ) / 2;
        mergeSort( a, tmpArray, left, center );
        mergeSort( a, tmpArray, center + 1, right );
        merge( a, tmpArray, left, center + 1, right );
    }
}


/**
 * Mergesort algorithm (driver).
 */
template <typename Comparable>
void mergeSort( vector<Comparable> & a )
{
    vector<Comparable> tmpArray( a.size( ) );

    mergeSort( a, tmpArray, 0, a.size( ) - 1 );
}


/**
 * Internal method that merges two sorted halves of a subarray.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * leftPos is the left-most index of the subarray.
 * rightPos is the index of the start of the second half.
 * rightEnd is the right-most index of the subarray.
 */
template <typename Comparable>
void merge( vector<Comparable> & a, vector<Comparable> & tmpArray, int leftPos, int rightPos, int rightEnd)
{
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    // Main loop
    while( leftPos <= leftEnd && rightPos <= rightEnd )
        if( a[ leftPos ] <= a[ rightPos ] )
            tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );
        else
            tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );

    while( leftPos <= leftEnd )    // Copy rest of first half
        tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );

    while( rightPos <= rightEnd )  // Copy rest of right half
        tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );

    // Copy tmpArray back
    for( int i = 0; i < numElements; ++i, --rightEnd )
        a[ rightEnd ] = std::move( tmpArray[ rightEnd ] );
}



///////QUICK SORT///////////////////////////

/**
 * Quicksort algorithm (driver).
 */
template <typename Comparable>
void quicksort( vector<Comparable> & a )
{
    quicksort( a, 0, a.size( ) - 1 );
}



/**
 * Return median of left, center, and right.
 * Order these and hide the pivot.
 */
template <typename Comparable>
const Comparable & median3( vector<Comparable> & a, int left, int right )
{
    int center = ( left + right ) / 2;
    
    if( a[ center ] < a[ left ] )
        std::swap( a[ left ], a[ center ] );
    if( a[ right ] < a[ left ] )
        std::swap( a[ left ], a[ right ] );
    if( a[ right ] < a[ center ] )
        std::swap( a[ center ], a[ right ] );

        // Place pivot at position right - 1
    std::swap( a[ center ], a[ right - 1 ] );
    return a[ right - 1 ];
}


/**
 * Internal quicksort method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff of 10.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void quicksort( vector<Comparable> & a, int left, int right )
{
    if( left + 10 <= right )
    {
        const Comparable & pivot = median3( a, left, right );

            // Begin partitioning
        int i = left, j = right - 1;
        for( ; ; )
        {
            while( a[ ++i ] < pivot ) { }
            while( pivot < a[ --j ] ) { }
            if( i < j )
                std::swap( a[ i ], a[ j ] );
            else
                break;
        }

        std::swap( a[ i ], a[ right - 1 ] );  // Restore pivot

        quicksort( a, left, i - 1 );     // Sort small elements
        quicksort( a, i + 1, right );    // Sort large elements
    }
    else  // Do an insertion sort on the subarray
        insertionSort( a, left, right );
}

#endif