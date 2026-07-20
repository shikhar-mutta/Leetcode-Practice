// Link: https://leetcode.com/problems/happy-students/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n)
// Approach:
// 1. Create a vector has of size n+1 to keep track of which numbers are present in the input array a.
// 2. Create a vector cnt of size n+1 to keep track of the count of numbers less than or equal to i in the input array a.
// 3. Iterate through the input array a and update the has and cnt vectors accordingly.
// 4. Iterate through the range from 0 to n and check if the number i is not present in the input array a (i.e., has[i] == 0) and the count of numbers less than or equal to i is equal to i (i.e., cnt[i] == i). If both conditions are satisfied, increment the answer
// 5. Return the final answer.
class Solution
{
public:
    int countWays(vector<int> &a)
    {
        int n = a.size();
        vector<int> has(n + 1), cnt(n + 1);
        for (int i : a)
            has[i] = 1, cnt[i]++;
        for (int i = 1; i <= n; i++)
            cnt[i] += cnt[i - 1];
        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            if (!has[i] && cnt[i] == i)
                ans++;
        }
        return ans;
    }
};