#ifndef STATISTICS_H
#define STATISTICS_H
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;
class Statistics
{
    public:
        Statistics();
        virtual ~Statistics();

        int    calculateNumberofSamplings(const float,const int);
        float  calculateMean(const vector <long> &);
        float  calculateStandardDeviation(const vector <long> ,const float);
        float  calculateVariance(const float);
        float  calculateZvalue(const vector <long> &);

    protected:
    private:
};

#endif // STATISTICS_H
