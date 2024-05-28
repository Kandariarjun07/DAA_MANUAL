#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &arr, int s, int e, int mid)
{
    vector<int> temp;

    int idx1 = s, idx2 = mid + 1;

    while (idx1 <= mid && idx2 <= e)
    {
        if (arr[idx1] <= arr[idx2])
        {
            temp.push_back(arr[idx1++]);
        }
        else
        {
            temp.push_back(arr[idx2++]);
        }
    }
    while (idx1 <= mid)
    {
        temp.push_back(arr[idx1++]);
    }
    while (idx2 <= e)
    {
        temp.push_back(arr[idx2++]);
    }
    for (int i = 0; i < e - s + 1; i++)
    {
        arr[s + i] = temp[i];
    }
}
void mergeSort(vector<int> &arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    mergeSort(arr, mid + 1, e);
    mergeSort(arr, s, mid);
    merge(arr, s, e, mid);
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
        mergeSort(arr, 0, n - 1);
        int j = 1, flag = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == arr[j])
            {
                flag = 1;
                break;
            }
            j++;
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        t--;
    }
    return 0;
}