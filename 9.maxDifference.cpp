#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int findMaxDifference(const vector<int> &arr)
{
    if (arr.size() < 2)
    {
        return 0;
    }

    int minElement = arr[0];
    int maxDifference = arr[1] - arr[0];

    for (size_t i = 1; i < arr.size(); ++i)
    {
        if (arr[i] - minElement > maxDifference)
        {
            maxDifference = arr[i] - minElement;
        }
        if (arr[i] < minElement)
        {
            minElement = arr[i];
        }
    }

    return maxDifference;
}

int main()
{

    vector<int> array1 = {7, 1, 5, 3, 6, 4};
    cout << "Array: ";
    for (int num : array1)
    {
        cout << num << " ";
    }
    cout << endl;
    cout << "Maximum difference: " << findMaxDifference(array1) << endl; 

    return 0;
}
