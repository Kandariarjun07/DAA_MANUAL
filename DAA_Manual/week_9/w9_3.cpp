#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int mergeCost(vector<int> &sizes)
{
    priority_queue<int, vector<int>, greater<int>> pq(sizes.begin(), sizes.end());

    int cost = 0;

    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        int c = a + b;

        cost += c;

        pq.push(c);
    }

    return cost;
}

int main()
{
    int n;
    cout << "Enter the number of files: ";
    cin >> n;
    vector<int> sizes(n);
    cout << "Enter the sizes of the files: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> sizes[i];
    }

    int result = mergeCost(sizes);

    cout << "Minimum computation cost to merge all files: " << result << endl;

    return 0;
}
