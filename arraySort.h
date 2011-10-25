#ifndef ARRAYSORT_H
#define ARRAYSORT_H
#include "quicksort.h"
#include "selectsort.h"
#include <math.h>
#include <cstdlib>
#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <fstream>
#include "Statistics.h"
#include <limits>
#include <string>
#include <vector>


using namespace std;

class arraySort
{
    public:
        arraySort();
        virtual ~arraySort();
        arraySort(const arraySort& other);
        arraySort& operator=(const arraySort& other);
    protected:
    private:

    struct sortStats {float mean;
            float standardDeviation; float variance; float Zvalue; int arraySize; int sampleSize; };


    void   generateRandomArray(int);
    void   testDo();

    int arraySizeCalibration();

    ofstream outputFile;

    vector<int> randomArray;
    vector<long> quicksortTimes, selectsortTimes;
    vector<sortStats>  selectsortRunStatistics, quicksortRunStatistics;

    int   randomArraySize;



    Statistics statisticsGenerator;

    void printArray(const vector<int> &);
    void sendArrayToFile(const vector<long> &);
    void sendStatisticsToFile(const vector<sortStats> &, string);
    void sendStatisticsToScreen(const vector<sortStats> &);
    void sendStatisticsToCSV(const vector<sortStats> &, string);

    void storeStatistics(vector<long> &, int, int);

    void clearRandomArray();
};

#endif // ARRAYSORT_H
