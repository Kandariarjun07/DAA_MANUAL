#include <iostream>
#include <vector>
using namespace std;
void linearSearch(vector<int> &arr, int n,int k)
{
    int iter_cnt = 0;
    for (auto i : arr)
    {
        iter_cnt++;
        if(i == k){
            cout << "Present " << iter_cnt << endl;
            return;
        }
    }
    cout << "Not present " << iter_cnt << endl;
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
        linearSearch(arr, n, k);
        t--;
    }
    return 0;
}