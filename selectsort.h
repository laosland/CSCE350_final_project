#ifndef SELECTSORT_H
#define SELECTSORT_H
#include "sorts.h"
#include <iostream>
#include <vector>

class selectsort: public sorts
{
    public:
        selectsort();
        selectsort(vector<int>);
        virtual ~selectsort();
        bool sort(vector<int> &);
//        bool sort()
    protected:
    private:
};

#endif // SELECTSORT_H
