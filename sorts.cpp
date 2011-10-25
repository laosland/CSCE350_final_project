#include "sorts.h"

using namespace std;

sorts::sorts()
{
    //ctor
}

sorts::~sorts()
{
    //dtor
}

void sorts::doSort(vector<int> arrayToBeSorted)
{
    //do sort, use generic sort() name in each class.
    gettimeofday(&start,NULL);
    sort(arrayToBeSorted);
    gettimeofday(&finish,NULL);
    sortTime = static_cast<int>(timeval_diff(NULL, &finish, &start));
//    cout << "sort time is: " << sortTime << endl;
}

long long sorts::timeval_diff(struct timeval *difference,
                              struct timeval *end_time,
                              struct timeval *start_time)
{
    struct timeval temp_diff;

    if(difference==NULL)
    {
        difference=&temp_diff;
    }

    difference->tv_sec =end_time->tv_sec -start_time->tv_sec ;
    difference->tv_usec=end_time->tv_usec-start_time->tv_usec;

    /* Using while instead of if below makes the code slightly more robust. */

    while(difference->tv_usec<0)
    {
        difference->tv_usec+=1000000;
        difference->tv_sec -=1;
    }

    return 1000000LL*difference->tv_sec+
           difference->tv_usec;

} /* timeval_diff() */

//    bool sorts::sort(vector<int> passedArray)
 //   {
        //overwrite
  //      return true;
  //  }

    bool sorts::sort(vector<int> &passedArray)
    {
        //overwrite
        return true;
    }

    int sorts::getSortTime()
    {
        return sortTime;
    }
