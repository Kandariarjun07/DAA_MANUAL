#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void shortest_distance(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == k || j == k || i == j)
                {
                    continue;
                }
                if (matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {0, 10, 5, 5, INT_MAX},
        {INT_MAX, 0, 5, 5, 5},
        {INT_MAX, INT_MAX, 0, INT_MAX, 10},
        {INT_MAX, INT_MAX, INT_MAX, 0, 20},
        {INT_MAX, INT_MAX, INT_MAX, 5, 0}};

    shortest_distance(matrix);
    cout << "Shortest distances between vertices:" << endl;
    for (auto row : matrix)
    {
        for (int val : row)
        {
            if (val == INT_MAX)
            {
                cout << "inf ";
            }
            else
            {
                cout << val << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
