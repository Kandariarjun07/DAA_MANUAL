#include <iostream>
#include <vector>
using namespace std;
void linearSearch(vector<int> &arr, int s, int e, int k, int &iter_cnt)
{
    for (int i = s; i <= e; i++)
    {
        iter_cnt++;
        if (arr[i] == k)
        {
            cout << "Present " << iter_cnt << endl;
            return;
        }
        else if (arr[i] > k)
        {
            break;
        }
    }
    cout << "Not present " << iter_cnt << endl;
}
void jumpSearch(vector<int> &arr, int n, int k)
{
    int iter_cnt = 0;

    if (arr[0] == k)
    {
        iter_cnt++;
        cout << "Present " << iter_cnt << endl;
        return;
    }
    if (n >= 1 && arr[1] == k)
    {
        iter_cnt++;
        cout << "Present " << iter_cnt << endl;
        return;
    }
    int i = 2;
    for (i; i < n; i *= 2)
    {
        iter_cnt++;
        if (arr[i] == k)
        {
            cout << "Present " << iter_cnt << endl;
            return;
        }
        else if (arr[i] > k)
        {
            linearSearch(arr, i / 2, i - 1, k, iter_cnt);
            return;
        }
    }
    linearSearch(arr, i / 2, n - 1, k, iter_cnt);
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
        jumpSearch(arr, n, k);
        t--;
    }
    return 0;
}