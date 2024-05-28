#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
int partition(vector<int> &arr, int s, int e, int &comp, int &swaps)
{
    int n = e - s + 1;
    int pivot = s + rand() % n;
    int cnt = 0;
    for (int k = s; k <= e; k++)
    {
        if (k != pivot && arr[pivot] >= arr[k])
        {
            comp++;
            cnt++;
        }
    }
    int pIdx = s + cnt;
    swaps++;
    swap(arr[pivot], arr[pIdx]);
    int i = s, j = e;
    while (i < pIdx && j > pIdx)
    {
        while (arr[i] < arr[pIdx])
        {
            comp++;
            i++;
        }
        while (arr[j] > arr[pIdx])
        {
            comp++;
            j--;
        }
        if (i < pIdx && j > pIdx)
        {
            comp++;
            swaps++;
            swap(arr[i++], arr[j--]);
        }
    }
    return pIdx;
}
void quickSort(vector<int> &arr, int s, int e, int &comp, int &swaps)
{
    if (s >= e)
        return;
    int p = partition(arr, s, e, comp, swaps);
    quickSort(arr, s, p - 1, comp, swaps);
    quickSort(arr, p + 1, e, comp, swaps);
}
int main()
{
    int t, n;
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
        int comp = 0, swaps = 0;
        quickSort(arr, 0, n - 1, comp, swaps);
        for (auto i : arr)
        {
            cout << i << " ";
        }
        cout << endl;
        cout << "Comparision : " << comp << endl;
        cout << "Swaps : " << swaps << endl;
        t--;
    }
}
