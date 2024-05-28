#include <iostream>
#include <vector>
using namespace std;
void binarySearch(vector<int> &arr, int n, int k){
    int iter_cnt = 0;
    int s = 0, e = n - 1;
    while (s <= e){
        iter_cnt++;
        int mid = s + (e - s) / 2;
        if (arr[mid] == k){
            cout << "Present " << iter_cnt << endl;
            return;
        }
        else if (arr[mid] > k)
            e = mid - 1;
        else
            s = mid + 1;
    }
    cout << "Not present " << iter_cnt << endl;
}
int main(){
    int t, n, k;
    cout << "Enter number of test cases : ";
    cin >> t;
    while (t){
        cout << "Enter size of Array : ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter elements : ";
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cout << "Enter target element : ";
        cin >> k;
        binarySearch(arr, n, k);
        t--;
    }
    return 0;
}