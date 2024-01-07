#include <iostream>
#include <time.h>
#include <windows.h>
#include <algorithm>

using namespace std;

void bubbleSort(int table[], int elements);
void quickSort(int table[], int left, int right);
void mergeSort(int table[], int start, int last);
void merging(int table[], int start, int mid, int last);
void selectionSort( int table[], int elements );
void insertSort(int table[], int elements);
void sortingTest(int table[], int elements);

int main()
{
    int elements;
    clock_t start, stop;
    double bubbleSortTime, insertSortTime, selectionSortTime, quickSortTime, mergeSortTime;

    cout << "Please enter the number of random elements to sort: " << endl;
    cin >> elements;
    cout << endl;

    int *table;
    table = new int [elements];

    int *table2;
    table2 = new int [elements];

    int *table3;
    table3 = new int [elements];

    int *table4;
    table4 = new int [elements];

    int *table5;
    table5 = new int [elements];

    srand(time(NULL));

    for(int i = 0; i < elements; i++)
    {
        table[i] = rand()%100000+1;
    }
    for(int i = 0; i < elements; i++)
    {
        table2[i] = table[i];
    }
    for(int i = 0; i < elements; i++)
    {
        table3[i] = table[i];
    }
    for(int i = 0; i < elements; i++)
    {
        table4[i] = table[i];
    }
    for(int i = 0; i < elements; i++)
    {
        table5[i] = table[i];
    }

    cout << "Bubble sort in progress. Please wait." << endl;
    start = clock();
    bubbleSort(table,elements);
    stop = clock();
    bubbleSortTime = (double)(stop-start) / CLOCKS_PER_SEC;
    sortingTest(table, elements);

    cout<<endl<< "Quick sort in progress. Please wait." << endl;
    start = clock();
    quickSort(table2, 0, elements - 1);
    stop = clock();
    quickSortTime = (double)(stop-start) / CLOCKS_PER_SEC;
    sortingTest(table2, elements);

    cout << endl << "Merge sort in progress. Please wait." << endl;
    start = clock();
    mergeSort (table3, 0, elements - 1);
    stop = clock();
    mergeSortTime = (double)(stop-start) / CLOCKS_PER_SEC;

    sortingTest(table3, elements);

    cout << endl << "Selection sort in progress. Please wait." << endl;
    start = clock();
    selectionSort (table4, elements);
    stop = clock();
    selectionSortTime = (double)(stop-start) / CLOCKS_PER_SEC;
    sortingTest(table4, elements);

    cout << endl << "Insert sort in progress. Please wait." << endl;
    start = clock();
    insertSort (table5, elements);
    stop = clock();
    insertSortTime = (double)(stop-start) / CLOCKS_PER_SEC;
    sortingTest(table5, elements);

    cout << endl << "Execution time bubble sort: " << bubbleSortTime <<" s" << endl;
    cout << endl << "Execution time quick sort: " << quickSortTime <<" s" << endl;
    cout << endl << "Execution time merge sort: " << mergeSortTime <<" s" << endl;
    cout << endl << "Execution time selection sort: " << selectionSortTime << " s" << endl;
    cout << endl << "Execution time insert sort: " << insertSortTime << " s" << endl;

    delete [] table;
    delete [] table2;
    delete [] table3;
    delete [] table4;
    delete [] table5;

    return 0;
}

void bubbleSort(int table[], int elements)
{
    for(int i = 1; i < elements; i++)
    {
        for(int j = elements-1; j >= 1; j--)
        {
            if(table[j] < table[j-1])
            {
                int temp;
                temp = table[j-1];
                table[j-1] = table[j];
                table[j] = temp;
            }
        }
    }
}

void quickSort(int table[], int left, int right)
{
    int v = table[(left+right)/2];
    int i,j,x;
    i = left;
    j = right;
    do
    {
        while(table[i] < v) i++;
        while(table[j] > v) j--;
        if(i <= j)
        {
            x = table[i];
            table[i] = table[j];
            table[j] = x;
            i++;
            j--;
        }
    }
    while(i <= j);
    if(j > left) quickSort(table,left, j);
    if(i < right) quickSort(table, i, right);
}

void merging(int table[], int start, int mid, int last)
{
    int *tab_pom = new int[(last-start+1)];
    int i = start, j = mid+1, k = 0;
    while (i <= mid && j <= last)
    {
        if (table[j] < table[i])
        {
            tab_pom[k] = table[j];
            j++;
        }
        else
        {
            tab_pom[k] = table[i];
            i++;
        }
        k++;
    }

    if (i <= mid)
    {
        while (i <= mid)
        {
            tab_pom[k] = table[i];
            i++;
            k++;
        }
    }
    else
    {
        while (j <= last)
        {
            tab_pom[k] = table[j];
            j++;
            k++;
        }
    }

    for (i = 0; i <= last-start; i++)
        table[start+i] = tab_pom[i];

    delete [] tab_pom;
}

void mergeSort(int table[], int start, int last)
{
    int mid;

    if (start != last)
    {
        mid = (start+last)/2;
        mergeSort(table, start, mid);
        mergeSort(table, mid+1, last);
        merging(table, start, mid, last);
    }
}

void selectionSort( int table[], int elements )
{
    int k;
    for( int i = 0; i < elements; i++ )
    {
        k = i;
        for( int j = i+1; j < elements; j++ )
            if( table[ j ] < table[ k ] )
            {
                k = j;
            }
        swap ( table[ k ], table[ i ] );
    }
}

void insertSort(int table[], int elements)
{
    int temp, j;
    for(int i = 1; i < elements; i++)
    {
        temp = table[i];
        j = i-1;

        while(j >= 0 && table[j] > temp)
        {
            table[j+1] = table[j];
            --j;
        }
        table[j+1] = temp;
    }
}

void sortingTest(int table[], int elements)
{
    string result = "Sort successful.";
    for (int i = 0; i < elements-1; i++)
    {
        if (table[i] > table[i+1])
            result = "Sort failed.";
    }
    cout << result << endl;
}


