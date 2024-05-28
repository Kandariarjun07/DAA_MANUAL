#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int countPairs(vector<int> &arr, int n, int k)
{
    int ans = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(arr[i] - arr[j]) == k)
            {
                ans++;
            }
        }
    }
    return ans;
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
        cout << "Enter difference : ";
        cin >> k;
        cout << countPairs(arr, n, k) << endl;
        t--;
    }
    return 0;
}