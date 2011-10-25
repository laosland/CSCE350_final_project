#include "quicksort.h"
using namespace std;

quicksort::quicksort()
{
    //ctor
}

quicksort::quicksort(vector<int> passedArray)
{
        doSort(passedArray);
}

quicksort::quicksort(vector<int> passedArray, int left, int right)
{
    int pivot = findPivot(passedArray.size());
    int i = left, j = right;
    int temp;
    //cout << arraySize <<endl;
    while (i <= j)
    {
        while (passedArray[i] < pivot)
            i++;
        while (passedArray[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = passedArray[i];
            passedArray[i] = passedArray[j];
            passedArray[j] = temp;
            i++;
            j--;
        }
    };

    if (left < j)
        quicksort(passedArray, left, j );

    if (i < right)
        quicksort(passedArray, i, right);
}

int quicksort::findPivot(int arraySize)
{
    //just center of list
    int pivot=0;
        if (arraySize%2 == 1)
    {
        pivot = ((arraySize-1)/2)+1;
    }

    else
    {
        pivot = arraySize/2+1;
    }
    return pivot;
}

quicksort::~quicksort()
{
    //dtor
}

bool quicksort::sort(vector<int> passedArray)
{
    int left, right, pivot;
    if (passedArray.size()%2 == 1)
    {
        left = (passedArray.size()-1)/2;
        pivot = left + 1;
        right = pivot + 1;
    }

    else
    {
        left = passedArray.size()/2-1;
        pivot = left + 1;
        right = pivot + 1;
    }
    quicksort(passedArray, left, right);
    return true;
}

