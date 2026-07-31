// Link: https://leetcode.com/problems/maximum-elegance-of-a-k-length-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn), SC: O(n)
//  Approach: We can use a greedy approach to find the maximum elegance of a k-length subsequence. We will first sort the items based on their value in descending order. Then, we will iterate through the sorted items and maintain a frequency map to count the number of times each type has been seen. We will also maintain a sum of the values of the selected items and a count of the number of unique types. Finally, we will calculate the maximum elegance by adding the sum of the values and the count of unique types, and return the maximum elegance found during the iteration.
class Solution
{
public:
    using ll = long long;
    long long findMaximumElegance(vector<vector<int>> &items, int k)
    {
        ll sum = 0, ret = 0, cnt = 0;
        ranges::sort(items);
        int n = items.size();
        vector<int> freq(n + 1);
        for (int i = n - 1; i >= n - k; --i)
        {
            sum += items[i][0];
            if (freq[items[i][1]]++ == 0)
            {
                sum += (2 * (cnt++) + 1);
            }
        }
        ret = sum;
        for (int i = n - k, j = n - k - 1; i < n && j >= 0; ++i)
        {
            if (freq[items[i][1]] == 1)
                continue;
            while (j >= 0 && freq[items[j][1]] > 0)
            {
                --j;
            }
            if (j < 0)
                break;
            ++freq[items[j][1]];
            --freq[items[i][1]];
            sum += items[j][0] - items[i][0] + (2 * (cnt++) + 1);
            ret = max(ret, sum);
            --j;
        }
        return ret;
    }
};
