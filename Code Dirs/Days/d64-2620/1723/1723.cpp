// Link: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) SC: O(n)
//  Approach: Binary Search + Backtracking
//   We can use binary search to find the minimum time required to finish all jobs. We can use backtracking to check if we can assign the jobs to the workers such that the maximum time taken by any worker is less than or equal to the mid value. If we can assign the jobs, we update the answer and search for a smaller value. Otherwise, we search for a larger value.
class Solution
{
public:
    bool dfs(int ind, vector<int> &jobs, vector<int> &workers, int mid)
    {
        if (ind == jobs.size())
            return true;
        for (int i = 0; i < workers.size(); i++)
        {
            if (jobs[ind] + workers[i] <= mid)
            {
                workers[i] += jobs[ind];

                if (dfs(ind + 1, jobs, workers, mid))
                    return true;
                workers[i] -= jobs[ind];
            }
            if (workers[i] == 0)
                break;
            if (workers[i] + jobs[ind] == mid)
                break;
        }
        return false;
    }

    bool canassign(int mid, vector<int> &jobs, int k)
    {
        vector<int> workers(k, 0);
        return dfs(0, jobs, workers, mid);
    }
    int minimumTimeRequired(vector<int> &jobs, int k)
    {
        int low = *max_element(jobs.begin(), jobs.end());
        int high = accumulate(jobs.begin(), jobs.end(), 0);
        sort(jobs.rbegin(), jobs.rend());
        int mid;
        int ans = -1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (canassign(mid, jobs, k))
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};