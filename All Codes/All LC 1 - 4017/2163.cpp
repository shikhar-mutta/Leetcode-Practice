// Link: https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn)  SC: O(n)
// Approach: We can use a priority queue to keep track of the largest n elements in the first 2n elements and the smallest n elements in the last 2n elements. We can then calculate the sum of the largest n elements and the sum of the smallest n elements and return the minimum difference between these two sums.
class Solution
{
public:
    static long long minimumDifference(vector<int> &nums)
    {
        const int n = nums.size() / 3;
        vector<long long> diff(n + 1, 0);
        priority_queue<int> pqL(nums.begin(), nums.begin() + n);
        priority_queue<int, vector<int>, greater<int>> pqR(nums.begin() + 2 * n,
                                                           nums.end());
        long long sum = accumulate(nums.begin(), nums.begin() + n, 0LL);
        for (int i = n; i <= 2 * n; i++)
        {
            diff[i - n] = sum;
            //    cout<<sum<<",";
            int x = nums[i];
            if (x >= pqL.top())
                continue;
            sum += x - pqL.top();
            pqL.pop();
            pqL.push(x);
        }
        //    cout<<endl;
        sum = accumulate(nums.begin() + 2 * n, nums.end(), 0LL);
        for (int i = 2 * n - 1; i >= n - 1; i--)
        {
            diff[i - n + 1] -= sum;
            //    cout<<sum<<",";
            int x = nums[i];
            if (x <= pqR.top())
                continue;
            sum += x - pqR.top();
            pqR.pop();
            pqR.push(x);
        }
        return *min_element(diff.begin(), diff.end());
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();