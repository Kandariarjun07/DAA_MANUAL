#include <iostream>
#include <vector>
using namespace std;
int firstOccurence(vector<int> &arr, int n, int k)
{
    int s = 0, e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == k)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] > k)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}
int lastOccurence(vector<int> &arr, int n, int k)
{
    int s = 0, e = n - 1;
    int ans = -1;
    while (s <= e)
    {

        int mid = s + (e - s) / 2;
        if (arr[mid] == k)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] > k)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}
void countOccurence(vector<int> &arr, int n, int k)
{
    int first_occur = firstOccurence(arr, n, k);
    int last_occur = lastOccurence(arr, n, k);
    int occ = last_occur - first_occur + 1;
    if (first_occur >= 0)
    {
        cout << k << " - " << occ << endl;
    }
    else
    {
        cout << "Key not present" << endl;
    }
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
        cout << "Enter target element : ";
        cin >> k;
        countOccurence(arr, n, k);
        t--;
    }
    return 0;
}