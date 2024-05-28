#include <iostream>
#include <vector>
using namespace std;
bool findTriplets(vector<int> &arr, int n)
{
    int k = n - 1;
    while (k > 1)
    {
        int i = 0, j = k - 1;
        while (i < j)
        {
            int sum = arr[i] + arr[j];
            if (sum == arr[k])
            {
                cout << i << "," << j << "," << k << endl;
                return true;
            }
            if (sum > arr[k])
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        k--;
    }
    return false;
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
        if (!findTriplets(arr, n))
        {
            cout << "No sequence found\n";
        }
        t--;
    }
    return 0;
}