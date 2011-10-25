#include "selectsort.h"

using namespace std;

selectsort::selectsort()
{
    //ctor
}

selectsort::selectsort(vector<int> passedArray)
{
    doSort(passedArray);
}

selectsort::~selectsort()
{
    //dtor
}



bool selectsort::sort(vector<int> &passedArray)
{
    //cout << "ss passedArray.size() is: "<<passedArray.size()<<endl;

    int smallestElement;
    int iTemp = 0;
    for (unsigned int i = 0; i < passedArray.size(); ++i)
    {
        smallestElement = passedArray[i];
        for (unsigned int j = i; j < passedArray.size(); ++j)
        {
            //cout << "element ["<<i<<"] is: "<< passedArray[i]<<endl;
            if ( passedArray[j] < smallestElement)
            {
                //cout << "i,j is: "<<i<<","<<j<<endl;
                iTemp = smallestElement;
                smallestElement = passedArray[j];
                passedArray[j] = iTemp;
            }
        }
        //cout <<"leaving ss"<<endl;
    }    return true;
}
