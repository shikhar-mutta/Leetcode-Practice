// Link: https://leetcode.com/problems/construct-target-array-with-multiple-sums/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n + log(maxVal))  SC: O(n)
// Approach: reverse simulation with a max-heap. The largest element M
// must have been set to "sum of the rest" (rest = total - M) on the
// last operation touching it, so its previous value was M reduced
// modulo rest (using division to skip many identical reverse steps at
// once for efficiency, since the same index could have been repeatedly
// re-maximized). Continue until the max is 1; impossible if rest==0 or
// M<=rest (no valid reduction exists).
class Solution
{
public:
    bool isPossible(vector<int> &target)
    {
        int n = target.size();
        if (n == 1)
            return target[0] == 1;

        priority_queue<long long> pq(target.begin(), target.end());
        long long sum = accumulate(target.begin(), target.end(), 0LL);

        while (pq.top() > 1)
        {
            long long M = pq.top();
            pq.pop();
            long long rest = sum - M;
            if (rest == 0 || M <= rest)
                return false;
            long long newM = M % rest;
            if (newM == 0)
                newM = rest;
            sum = rest + newM;
            pq.push(newM);
        }
        return true;
    }
};
