// Link: https://leetcode.com/problems/count-days-without-meetings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) + O(n)
// SC: O(n)
// Approach:
//   1. Sort the meetings based on the start time.
//   2. Merge the overlapping meetings and store the merged meetings in a new vector.
//   3. Count the number of days without meetings by calculating the gaps between the merged meetings and the days before the first meeting and after the last meeting.
//   4. Return the count of days without meetings.
class Solution
{
public:
    struct data
    {
        int start;
        int end;
    };
    static bool comp(data val1, data val2)
    {
        return val1.start < val2.start;
    }
    int countDays(int days, vector<vector<int>> &meetings)
    {
        vector<vector<int>> ans;
        vector<data> arr;
        for (int i = 0; i < meetings.size(); i++)
        {
            data temp;
            temp.start = meetings[i][0];
            temp.end = meetings[i][1];
            arr.push_back(temp);
        }
        sort(arr.begin(), arr.end(), comp);
        int startTime = arr[0].start;
        int endTime = arr[0].end;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i].start <= endTime)
                endTime = max(endTime, arr[i].end);
            else
            {
                ans.push_back({startTime, endTime});
                startTime = arr[i].start;
                endTime = arr[i].end;
            }
        }
        ans.push_back({startTime, endTime});
        int count = 0;
        int finalDay = ans[ans.size() - 1][1];
        for (int i = 0; i < ans.size() - 1; i++)
        {
            count = count + (ans[i + 1][0] - ans[i][1] - 1);
        }
        if (days > finalDay)
            count = count + (days - finalDay);
        if (ans[0][0] != 1)
            count = count + (ans[0][0] - 1);

        return count;
    }
};
