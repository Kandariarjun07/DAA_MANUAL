#include <iostream>
#include <vector>
using namespace std;
void insertionSort(vector<int> &arr, int n)
{
    int shift = 0, comparison = 0;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i;
        while (j > 0 && key < arr[j - 1])
        {
            shift++;
            comparison++;
            arr[j] = arr[j - 1];
            j--;
        }

        arr[j] = key;
        shift++;
    }
    cout << "Shifts : " << shift << endl
         << "comparision : " << comparison << endl;
}
int main()
{
    int t, n, k;
    cout << "Enter number of test cases : ";
    cin >> t;
    while (t)
    {
        cout << "Enter size of Array : ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter elements : ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        insertionSort(arr, n);
        for (auto i : arr)
        {
            cout << i << " ";
        }
        cout << endl;
        t--;
    }
    return 0;
}