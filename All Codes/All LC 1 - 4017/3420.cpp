// Link: https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
//  Approach: Use a sliding window approach with a deque to maintain the indices of the elements in the current window. For each new element, we pop elements from the back of the deque while they are less than the current element, and adjust k accordingly. If k becomes negative, we move the left pointer of the window to the right until k is non-negative again. The number of valid subarrays ending at the current index is then added to the result.
class Solution
{
public:
    long long countNonDecreasingSubarrays(vector<int> &A, long long k)
    {
        reverse(A.begin(), A.end());
        long long res = 0;
        deque<int> q;
        for (int j = 0, i = 0; j < A.size(); ++j)
        {
            while (!q.empty() && A[q.back()] < A[j])
            {
                int r = q.back();
                q.pop_back();
                int l = q.empty() ? i - 1 : q.back();
                k -= 1L * (r - l) * (A[j] - A[r]);
            }
            q.push_back(j);
            while (k < 0)
            {
                k += A[q.front()] - A[i];
                if (q.front() == i)
                {
                    q.pop_front();
                }
                ++i;
            }
            res += j - i + 1;
        }
        return res;
    }
};
