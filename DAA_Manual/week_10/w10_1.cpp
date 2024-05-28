#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> selectActivities(vector<pair<int, int>> &activities)
{
    int n = activities.size();
    vector<int> selectedActivities;
    int lastFinishTime = 0;

    for (int i = 0; i < n; ++i)
    {
        int start = activities[i].second;
        int finish = activities[i].first;
        if (start >= lastFinishTime)
        {
            selectedActivities.push_back(i + 1); 
            lastFinishTime = finish;
        }
    }

    return selectedActivities;
}

int main()
{
    int N;
    cout << "Enter the number of activities: ";
    cin >> N;

    vector<int> startTimes(N), finishTimes(N);
    cout << "Enter the starting times: ";
    for (int i = 0; i < N; ++i)
    {
        cin >> startTimes[i];
    }
    cout << "Enter the finishing times: ";
    for (int i = 0; i < N; ++i)
    {
        cin >> finishTimes[i];
    }

    vector<pair<int, int>> activities(N);
    for (int i = 0; i < N; ++i)
    {
        activities[i] = {finishTimes[i], startTimes[i]};
    }

    // Sort activities based on their finishing times
    sort(activities.begin(), activities.end());

    vector<int> result = selectActivities(activities);

    cout << "No. of non-conflicting activities: " << result.size() << endl;
    cout << "List of selected activities: ";
    for (size_t i = 0; i < result.size(); ++i)
    {
        cout << result[i];
        if (i != result.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}
