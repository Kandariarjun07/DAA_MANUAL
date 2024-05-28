#include <iostream>
#include <vector>
using namespace std;
void findCommon(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr2[j]);
            i++;
            j++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    for (auto k : ans)
    {
        cout << k << " ";
    }
    cout << endl;
}
int main()
{
    int t, n, m;
    cout << "Enter number of test cases : ";
    cin >> t;
    while (t)
    {
        cout << "Enter size of Array 1 : ";
        cin >> n;
        vector<int> arr1(n);

        cout << "Enter elements : ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        cout << "Enter size of Array 2 : ";
        cin >> m;
        vector<int> arr2(m);

        cout << "Enter elements : ";
        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }

        findCommon(arr1, n, arr2, m);
        t--;
    }
    return 0;
}