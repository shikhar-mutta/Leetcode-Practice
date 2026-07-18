// Link: https://leetcode.com/problems/most-profit-assigning-work/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn + mlogn) where n = difficulty.size() and m = worker.size()
    // SC: O(n) for jobs and best arrays
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int n = difficulty.size();

        vector<pair<int, int>> jobs(n);
        for (int i = 0; i < n; i++)
            jobs[i] = {difficulty[i], profit[i]};
        sort(jobs.begin(), jobs.end());

        vector<int> best(n);
        best[0] = jobs[0].second;
        for (int i = 1; i < n; i++)
            best[i] = max(best[i - 1], jobs[i].second);

        int ans = 0;
        for (int wk : worker)
        {
            int l = 0, h = n - 1, idx = -1;
            while (l <= h)
            {
                int mid = l + (h - l) / 2;
                if (jobs[mid].first <= wk)
                {
                    idx = mid; // doable → remember and look right
                    l = mid + 1;
                }
                else
                    h = mid - 1;
            }
            if (idx != -1)
                ans += best[idx];
        }
        return ans;
    }
};
