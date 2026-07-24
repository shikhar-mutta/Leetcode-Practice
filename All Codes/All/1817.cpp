// Link: https://leetcode.com/problems/finding-the-users-active-minutes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn), SC: O(n)
// Approach: Sort + Count
// 1. We can solve this problem by sorting the logs based on user_id and then counting the unique minutes for each user.
// 2. We can use a vector to store the result and return it at the end.
// 3. We can use a static vector to avoid reallocation and improve performance.
// 4. We can use a static lambda to disable synchronization with C I/O and untie cin from cout to improve performance.
class Solution
{
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k)
    {
        static const auto fast_io = []()
        {
            std::ios::sync_with_stdio(false);
            std::cin.tie(nullptr);
            std::cout.tie(nullptr);
            return nullptr;
        }();

        // Flatten to avoid pointer chasing.
        static std::vector<std::pair<int, int>> flat_logs(10000, {0, 0});
        for (int i = 0; i < logs.size(); ++i)
        {
            flat_logs[i].first = logs[i][0];
            flat_logs[i].second = logs[i][1];
        }
        std::sort(flat_logs.begin(), flat_logs.begin() + logs.size());
        auto unique_end =
            std::unique(flat_logs.begin(), flat_logs.begin() + logs.size());
        const int n = unique_end - flat_logs.begin();
        std::vector<int> result(k, 0);
        for (int i = 0; i < n;)
        {
            const int id = flat_logs[i].first;
            int scan = 0;
            for (; i < n && flat_logs[i].first == id; ++i)
            {
                ++scan;
            }
            ++result[scan - 1];
        }
        return result;
    }
};