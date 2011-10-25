#include "Statistics.h"

using namespace std;

const float ZVALUE_95 = 1.96;
const float ZVALUE_99 = 2.58;
const float STANDARD_ERROR = 0.05;
const float SAMPLE_PROPORTION = .95; //number of items within 95% of the true mean;
const float PERCENTAGE_PICK_CHOICE = .5;

Statistics::Statistics()
{
    //ctor
}

Statistics::~Statistics()
{
    //dtor
}

int Statistics::calculateNumberofSamplings(const float confidenceLevel,const int populationSize)
{
    float sampleSize = 0.0;
    sampleSize = ((.9604/pow(STANDARD_ERROR, 2))*populationSize)/((.9604/pow(STANDARD_ERROR, 2))+populationSize);
    //cout << "sample size is: " << sampleSize << endl;
    return static_cast<int>(sampleSize);
}

float  Statistics::calculateMean(const vector<long> &passedArray)
{
//    cout <<"in mean calculations"<<endl;
//    cout <<"passed array size is: "<<passedArray.size()<<endl;
    int sum = 0;
    float mean = 0;
    for(unsigned int i = 0; i < passedArray.size(); ++i)
    {
//        cout << "i in calcmean is: "<< i <<"of "<<passedArray.size()<<endl;
        sum = sum + passedArray[i];
    }
    mean = static_cast<float>(sum)/static_cast<float>(passedArray.size());

    return mean;

}

float  Statistics::calculateStandardDeviation(const vector<long> passedArray, const float arrayMean)
{
    float sum = 0, stdDeviation = 0;
    for(unsigned int i = 0; i < passedArray.size(); ++i)
    {
        sum += static_cast<float>(passedArray[i] - arrayMean);
    }
    stdDeviation = sum/static_cast<float>(passedArray.size());
    cout << "Standard deviation is: "<< stdDeviation << endl;
    return stdDeviation;
}

float  Statistics::calculateVariance(const float stdDeviation)
{
//    int square = 2;
    float variance = stdDeviation * stdDeviation;
    cout <<"variance is: "<<variance<<endl;
    return variance;
}

//// TODO (laosland#1#): find the Zvalue

float  Statistics::calculateZvalue(const long &rawTime, const long &mean,
                                  const long &standardDeviation)
{
    //empliment later
    float zValue = 0.0;
    zValue = (rawTime - mean)/standardDeviation;
    return zValue;
}
