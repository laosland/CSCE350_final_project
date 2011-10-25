#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "sorts.h"
#include <iostream>

class quicksort : public sorts
{
    public:
        quicksort();
        quicksort(vector <int>);
            quicksort(vector <int>, int, int);
        virtual ~quicksort();
        bool sort(vector<int>);
    protected:
    private:
    int findPivot( int );
};

#endif // QUICKSORT_H
