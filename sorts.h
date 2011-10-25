#ifndef SORTS_H
#define SORTS_H
#include <sys/time.h>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
class sorts
{
    public:
        sorts();
        virtual ~sorts();
        virtual void doSort(vector<int> );
//        virtual bool sort(vector<int> );
        virtual bool sort(vector<int> &);
        int getSortTime();
    protected:
    private:
        struct timeval start;
        struct timeval finish;
        struct timeval interval;

        int sortTime;

        long long timeval_diff(struct timeval *, struct timeval *,
             struct timeval *);

};

#endif // SORTS_H
