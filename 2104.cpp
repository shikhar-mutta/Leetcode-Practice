// Link: https://leetcode.com/problems/sum-of-subarray-ranges/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pse(n);
        vector<int> nse(n);
        vector<int> pge(n);
        vector<int> nge(n);
        stack<int> st1;
        stack<int> st2;
        stack<int> st3;
        stack<int> st4;
        for (int i = 0; i < n; i++)
        {
            while (!st1.empty() && nums[st1.top()] > nums[i])
                st1.pop();
            if (st1.empty())
            {
                pse[i] = -1;
            }
            else
            {
                pse[i] = st1.top();
            }
            st1.push(i);
        }

        for (int i = 0; i < n; i++)
        {
            while (!st3.empty() && nums[st3.top()] < nums[i])
                st3.pop();
            if (st3.empty())
            {
                pge[i] = -1;
            }
            else
            {
                pge[i] = st3.top();
            }
            st3.push(i);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st2.empty() && nums[st2.top()] >= nums[i])
                st2.pop();
            if (st2.empty())
            {
                nse[i] = n;
            }
            else
            {
                nse[i] = st2.top();
            }
            st2.push(i);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st4.empty() && nums[st4.top()] <= nums[i])
                st4.pop();
            if (st4.empty())
            {
                nge[i] = n;
            }
            else
            {
                nge[i] = st4.top();
            }
            st4.push(i);
        }
        long long sum1 = 0;
        long long sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            long long l1 = i - pse[i];
            long long l2 = i - pge[i];
            long long r1 = nse[i] - i;
            long long r2 = nge[i] - i;
            sum1 = sum1 + (1LL * nums[i] * l1 * r1);
            sum2 = sum2 + (1LL * nums[i] * l2 * r2);
        }
        return sum2 - sum1;
    }
};