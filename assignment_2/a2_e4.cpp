#include <iostream>
using namespace std;

void sorting(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 2)
        {
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
        else if (arr[mid] == 0)
        {
            int temp = arr[mid];
            arr[mid] = arr[low];
            arr[low] = temp;

            mid++;
            low++;
        }
        else
        {
            mid++;
        }
    }
}
int main()
{
    cout << "Enter size of array: ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the numbers:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sorting(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
