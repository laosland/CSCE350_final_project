#include "arraySort.h"


using namespace std;

    const float ZVALUE_95 = 1.96;
    const float ZVALUE_99 = 2.58;
    const float STANDARD_ERROR = 0.05;
    const float SAMPLE_PROPORTION = .95; //number of items within 95% of the true mean;
    const float PERCENTAGE_PICK_CHOICE = .5;
    const int LARGEST_INT = numeric_limits<int>::max();
    const int NUMBER_OF_RUNS = 15;
    int quickSort = 1, selectSort = 2;


arraySort::arraySort()
{

    int sample = 0, counter = 0;
    randomArraySize = arraySizeCalibration();
//    quicksortTimes = new int[randomArraySize];
//    selectsortTimes = new int[randomArraySize];
    generateRandomArray(randomArraySize);

    int numberOfSamplings = statisticsGenerator.calculateNumberofSamplings(SAMPLE_PROPORTION, randomArraySize);
    //cout << "numberOfSamplings= " << numberOfSamplings <<endl;
    //cout << "randomArraySize= "<<randomArraySize<<endl;


    while (counter < NUMBER_OF_RUNS)
    {
        numberOfSamplings = statisticsGenerator.calculateNumberofSamplings(SAMPLE_PROPORTION, randomArraySize);
        sample = 0;
        while (sample < numberOfSamplings)
        {
            ///perform sorting and place it's runtime in an array at index "sample".
            //cout << "segfault test" << endl;
            testDo();
            ///delete current random array
            clearRandomArray();
            ///create new random array using
            //cout << "segfault test2" << endl;
            generateRandomArray(randomArraySize);

            ///increment the sample being taken
            ++sample;
        }
        storeStatistics(selectsortTimes, numberOfSamplings, selectSort);
        storeStatistics(quicksortTimes, numberOfSamplings, quickSort);

        ///increase the size of the random array
        randomArraySize += 2000;
        ++counter;

    }
    //printArray(selectsortTimes, randomArraySize);
    //send the sort times for the selectsort to a file;

    sendArrayToFile(quicksortTimes);
    sendStatisticsToFile(quicksortRunStatistics, "quickSort");
    sendStatisticsToScreen(quicksortRunStatistics);
    sendStatisticsToCSV(quicksortRunStatistics, "quickSort");

    sendStatisticsToFile(selectsortRunStatistics, "selectSort");
    sendStatisticsToScreen(selectsortRunStatistics);
    sendStatisticsToCSV(selectsortRunStatistics, "selectSort");

}

arraySort::~arraySort()
{
    //dtor
}

arraySort::arraySort(const arraySort& other)
{
    //copy ctor
}

arraySort& arraySort::operator=(const arraySort& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void arraySort::testDo()
{
    ///perform select sort on the randomArray.
    //cout << "segfault test in testDo" << endl;
   // selectsort ss(randomArray);
    ///add the runtime for the ss to the select sort runtimes array
    ///using the passed int "iteration" to set index.
    //selectsortTimes.push_back(ss.getSortTime());

    quicksort qs(randomArray);
    quicksortTimes.push_back(qs.getSortTime());
}


void   arraySort::generateRandomArray(int arraySize)
{
    srand(static_cast<unsigned>(time(NULL)));
//    cout << "arraySize is: "<< arraySize <<endl;
    for (int i = 0; i < arraySize; ++i)
    {
        randomArray.push_back(rand());
    }

}

int arraySort::arraySizeCalibration()
{
    int testArraySize = 0;
    long arrayTestResults=0;
    quicksort calibrate_quicksort;
    //selectsort calibrate_selectsort;
    while (arrayTestResults <= 0.0)
    {
        testArraySize +=1000;
        generateRandomArray(testArraySize);
        //calibrate_quicksort = new quicksort();
        calibrate_quicksort.doSort(randomArray);
        //calibrate_selectsort.doSort(randomArray);
        arrayTestResults = calibrate_quicksort.getSortTime();
        //arrayTestResults = calibrate_selectsort.getSortTime();
        clearRandomArray();
        //run arraysort over and over until get sort time > 0
    }
    return testArraySize;
}

void arraySort::printArray(const vector<int> &passedArray)
{
    for (unsigned int i = 0; i < passedArray.size() -1; ++i)
    {
        cout << "element:" << i << " is:" << passedArray[i] << "**" <<endl;
    }
}

void arraySort::sendArrayToFile(const vector<long> &passedArray)
{

    outputFile.open("testfile.txt");
    for (unsigned int i = 0; i < passedArray.size() -1; ++i)
    {
        outputFile << "element:" << i << " is:" << passedArray[i] << endl;
    }

    outputFile.close();

}

void arraySort::sendStatisticsToFile(const vector<sortStats> &statisticsArray, string sortType)
{
string filename = "statstest_"+ sortType + ".txt";
outputFile.open(filename.c_str());
for (unsigned int i = 0; i < statisticsArray.size(); ++i)
    {
        outputFile << "Mean for test " << i << " is:" << statisticsArray[i].mean << endl;
        outputFile << "Standard Deviation for test " << i << " is:" << statisticsArray[i].standardDeviation << endl;
        outputFile << "Variance test " << i << " is:" << statisticsArray[i].variance << endl;
        outputFile << "Zvalue for test " << i << " is:" << statisticsArray[i].Zvalue << endl;
        outputFile << "***********************************************************" << endl;
    }

outputFile.close();

}

void arraySort::sendStatisticsToScreen(const vector<sortStats> &statisticsArray)
{

for (unsigned int i = 0; i < statisticsArray.size(); ++i)
    {
        cout << "***********************************************************"<< endl;
        cout << "Mean for test " << i << " is:" << statisticsArray[i].mean << endl;
        cout << "Standard Deviation for test " << i << " is:" << statisticsArray[i].standardDeviation << endl;
        cout << "Variance test " << i << " is:" << statisticsArray[i].variance << endl;
        cout << "Zvalue for test " << i << " is:" << statisticsArray[i].Zvalue << endl;
        cout << "***********************************************************" << endl;
    }
}

void arraySort::sendStatisticsToCSV(const vector<sortStats> &statisticsArray, string sortType)
{
string filename = "statstest_"+ sortType + ".csv";
outputFile.open(filename.c_str());
outputFile << "\"Mean\",\"Standard Deviation\",\"Variance\",\"ZValue\",\"ArraySize\",\"Sample Size\",\"Test Number\"" <<endl;
for (unsigned int i = 0; i < statisticsArray.size(); ++i)
    {
        outputFile << statisticsArray[i].mean <<","<<statisticsArray[i].standardDeviation<<","<<
            statisticsArray[i].variance<<","<<statisticsArray[i].Zvalue<<","<<statisticsArray[i].arraySize<<
            ","<<statisticsArray[i].sampleSize<<","<<i+1<<endl;
    }

outputFile.close();

}

void arraySort::clearRandomArray()
{
//    cout << " clearRandomArray is problem?" << endl;
    randomArray.clear();
}

void arraySort::storeStatistics(vector<long> &passedStats, int numberOfSamplings, int sortType)
{
        sortStats tempElement;
    //        cout << "starting stats calculations for counter: "<< counter <<" of "<< NUMBER_OF_RUNS << endl;
        if (sortType == quickSort)
        {
            ///calculate the current array size's mean and store it in testRunStatistics
            tempElement.mean = statisticsGenerator.calculateMean(quicksortTimes);

            ///calculate the current array size's Standard Deviation and store it in testRunStatistics
            tempElement.standardDeviation = statisticsGenerator.calculateStandardDeviation(quicksortTimes, tempElement.mean);

            ///calculate the current array size's variance and store it in testRunStatistics
            tempElement.variance = statisticsGenerator.calculateVariance(tempElement.standardDeviation);

            ///calculate the current array size's Z score and store it in testRunStatistics
            tempElement.Zvalue = 0.0;
            tempElement.arraySize = passedStats.size();
            tempElement.sampleSize = numberOfSamplings;
            //testRunStatistics[counter].Zvalue = statisticsGenerator.calculateZvalue();
            quicksortRunStatistics.push_back(tempElement);
        }


        if (sortType == selectSort)
        {
            ///calculate the current array size's mean and store it in testRunStatistics
            tempElement.mean = statisticsGenerator.calculateMean(selectsortTimes);

            ///calculate the current array size's Standard Deviation and store it in testRunStatistics
            tempElement.standardDeviation = statisticsGenerator.calculateStandardDeviation(selectsortTimes, tempElement.mean);

            ///calculate the current array size's variance and store it in testRunStatistics
            tempElement.variance = statisticsGenerator.calculateVariance(tempElement.standardDeviation);

            ///calculate the current array size's Z score and store it in testRunStatistics
            tempElement.Zvalue = 0.0;
            tempElement.arraySize = randomArraySize;
            tempElement.sampleSize = numberOfSamplings;
            //testRunStatistics[counter].Zvalue = statisticsGenerator.calculateZvalue();
            selectsortRunStatistics.push_back(tempElement);
        }




}
