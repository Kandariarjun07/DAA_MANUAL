#include <iostream>
#include <vector>
using namespace std;
void countMaxOccur(vector<char> &arr, int n)
{
    int map[256] = {0};
    int maxi = 0;
    for (auto i = 0; i < n; i++)
    {
        map[(int)arr[i]]++;
    }
    int ansIdx = -1;
    for (int i = 0; i < 256; i++)
    {
        maxi = max(maxi, map[i]);
        if (map[i] == maxi)
        {
            ansIdx = i;
        }
    }
    if (maxi > 1)
    {
        cout << (char)ansIdx << " - " << maxi << endl;
    }
    else
    {
        cout << "No duplicates found" << endl;
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
        vector<char> arr(n);

        cout << "Enter elements : ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        countMaxOccur(arr, n);
        t--;
    }
    return 0;
}