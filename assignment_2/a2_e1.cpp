//e1
#include <iostream>
using namespace std;

int findPairs(int nums[], int diff, int size)
{
    int pairCount = 0;

    for (int idx = 0; idx < size - 1; idx++)
    {
        for (int next = idx + 1; next < size; next++)
        {
            if (abs(nums[next] - nums[idx]) == diff)
            {
                pairCount++;
            }
        }
    }
    return pairCount;
}

int main()
{
    cout << "Enter array length: ";
    int len;
    cin >> len;
    int numbers[len];
    cout << "Enter the elements:" << endl;

    for (int i = 0; i < len; i++)
    {
        cin >> numbers[i];
    }
    int target;
    cout << "Enter target difference: ";
    cin >> target;
    int result = findPairs(numbers, target, len);
    cout << "Number of valid pairs: " << result << endl;

    return 0;
}
