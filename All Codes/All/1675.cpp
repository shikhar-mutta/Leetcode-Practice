// Link: https://leetcode.com/problems/minimize-deviation-in-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) where n is the size of the input array
// SC: O(n) where n is the size of the input array
//  Approach: We can use a max heap to keep track of the maximum element in the array. We can also keep track of the minimum element in the array. We can then repeatedly divide the maximum element by 2 until it becomes odd. We can then update the minimum element and calculate the deviation. We can keep track of the minimum deviation and return it at the end.
class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        priority_queue<int> pq;
        int mn = INT_MAX;
        for (auto x : nums)
        {
            if (x % 2 != 0)
            {
                pq.push(x * 2);
                mn = min(mn, x * 2);
            }
            else
            {
                pq.push(x);
                mn = min(x, mn);
            }
        }
        int sol = pq.top() - mn;
        while (true)
        {
            if (pq.top() % 2 != 0)
                break;
            else if (pq.top() == mn)
                return 0;

            int n = pq.top();
            pq.pop();
            pq.push(n / 2);
            mn = min(mn, n / 2);
            sol = min(pq.top() - mn, sol);
        }
        return sol;
    }
};