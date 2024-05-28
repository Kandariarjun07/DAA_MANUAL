#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &arr, int s, int mid, int e, int &comp)
{
    vector<int> temp;

    int i = s, j = mid + 1;

    while (i <= mid && j <= e)
    {
        comp++;
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= e)
    {
        temp.push_back(arr[j++]);
    }
    for (int i = 0; i < temp.size(); i++)
    {
        arr[s + i] = temp[i];
    }
}
void mergerSort(vector<int> &arr, int s, int e, int &comp)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;
    mergerSort(arr, s, mid,comp);
    mergerSort(arr, mid + 1, e,comp);
    merge(arr, s, mid, e, comp);
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
        int comp = 0 ;
        mergerSort(arr, 0, n - 1, comp);
        for (auto i : arr)
        {
            cout << i << " ";
        }
        cout << endl;
        cout << "Comparision : " << comp << endl;
        t--;
    }
}
