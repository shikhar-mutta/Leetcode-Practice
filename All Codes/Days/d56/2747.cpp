// Link: https://leetcode.com/problems/count-zero-request-servers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn)
    // SC: O(n)
    //  Approach:
    //  1. Sort the queries and logs based on the time.
    //  2. Use two pointers to maintain a sliding window of logs that fall within the time range of the current query.
    //  3. Use an array to keep track of the number of active servers at each time point.
    //  4. For each query, count the number of servers that have not received any requests in the last x seconds and store the result in the output array.
    //  5. Return the output array after processing all queries.
    vector<int> countServers(int n, vector<vector<int>> &logs, int x, vector<int> &queries)
    {
        int N = queries.size();
        vector<int> arr(N, 0);
        vector<pair<int, int>> sortedQueries(N);

        for (int i = 0; i < N; i++)
        {
            sortedQueries[i] = {queries[i], i};
        }
        // sort
        sort(sortedQueries.begin(), sortedQueries.end());
        sort(logs.begin(), logs.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });

        vector<int> active(n, 0);
        int nServersUsed = 0;
        int l = 0, r = 0;
        for (const auto [t, i] : sortedQueries)
        {
            while (r < logs.size() && logs[r][1] <= t)
            {
                if (active[logs[r++][0] - 1]++ == 0)
                {
                    nServersUsed++;
                }
            }
            while (l < logs.size() && logs[l][1] < t - x)
            {
                if (active[logs[l++][0] - 1]-- == 1)
                {
                    nServersUsed--;
                }
            }
            arr[i] = n - nServersUsed;
        }
        return arr;
    }
};
