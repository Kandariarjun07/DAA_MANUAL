#include <iostream>
#include <vector>
using namespace std;
void findPair(vector<char> &arr, int n)
{
    
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