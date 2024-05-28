#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int> &arr, int n)
{
    int swaps = 0, comparison = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int idx = i;
        for (int j = i + 1; j < n; j++)
        {
            comparison++;
            if (arr[j] < arr[idx])
                idx = j;
        }

        swap(arr[idx], arr[i]);
        swaps++;
    }
    cout << "Swaps : " << swaps << endl
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

        selectionSort(arr, n);
        for (auto i : arr)
        {
            cout << i << " ";
        }
        cout << endl;
        t--;
    }
    return 0;
}