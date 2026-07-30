// Link: https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q) where n is the length of the string s and q is the number of queries
// SC: O(n) where n is the length of the string s
// Approach: We can use a two-pointer approach to find the rightmost index for each starting index of the substring. We can maintain two pointers, i and j, where i is the starting index of the substring and j is the rightmost index that satisfies the k-constraint. We can also maintain a cumulative sum array to store the number of valid substrings ending at each index.
class Solution
{
public:
    vector<long long> countKConstraintSubstrings(string s, int k,
                                                 vector<vector<int>> &queries)
    {
        int n = s.length();
        vector<int> rightMost(n);
        int i = n - 1, j = n - 1;
        int zero = 0, one = 0;
        while (j >= 0)
        {
            if (s[j] == '0')
                zero++;
            else
                one++;
            while (zero > k && one > k)
            {
                if (s[i] == '0')
                    zero--;
                else
                    one--;
                i--;
            }

            rightMost[j] = i;
            j--;
        }
        vector<long long> cumSum(n);

        i = 0;
        j = 0;
        zero = 0;
        one = 0;

        while (j < n)
        {
            if (s[j] == '0')
                zero++;
            else
                one++;

            while (zero > k && one > k)
            {
                if (s[i] == '0')
                    zero--;
                else
                    one--;
                i++;
            }

            if (j == 0)
                cumSum[j] = j - i + 1;
            else
                cumSum[j] = cumSum[j - 1] + (j - i + 1);
            j++;
        }

        vector<long long> ans;
        for (auto &q : queries)
        {
            int low = q[0];
            int high = q[1];
            int validRightIdx = min(high, rightMost[low]);
            long long len = validRightIdx - low + 1;
            long long res = len * (len + 1) / 2;
            if (validRightIdx < high)
                res += cumSum[high] - cumSum[validRightIdx];

            ans.push_back(res);
        }

        return ans;
    }
};
