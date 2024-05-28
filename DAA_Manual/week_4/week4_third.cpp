#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> &arr, int s, int e)
{
    int cnt = 0;
    for (int k = s + 1; k <= e; k++)
    {
        if (arr[s] > arr[k])
        {
            cnt++;
        }
    }
    int pIdx = s + cnt;
    swap(arr[s], arr[pIdx]);
    int i = s, j = e;
    while (i < pIdx && j > pIdx)
    {
        while (arr[i] < arr[pIdx])
        {
            i++;
        }
        while (arr[j] > arr[pIdx])
        {
            j--;
        }
        if (i < pIdx && j > pIdx)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pIdx;
}
int kthLargest(vector<int> &arr, int s, int e, int k, int n)
{

    if (k >= 0 && k < n)
    {
        int p = partition(arr, s, e);
        if (p == k)
            return arr[p];

        else if (p > k)
            return kthLargest(arr, s, p - 1, k, n);

        else
            return kthLargest(arr, p + 1, e, k, n);
    }
    else
        return -1;
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
        cout << "Enter K : ";
        cin >> k;
        cout << "Enter elements : ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int kthlargest = kthLargest(arr, 0, n - 1, n - k, n);
        cout << "Kth Largest : " << kthlargest << endl;
        int kthsmallest = kthLargest(arr, 0, n - 1, k - 1, n);
        cout << "Kth Smallest : " << kthsmallest << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        t--;
    }
}
