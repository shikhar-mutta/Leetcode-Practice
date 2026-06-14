// Link: https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log n), SC: O(n)
    int minimumPairRemoval(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return 0;

        vector<long long> val(n);
        vector<int> prv(n), nxt(n); // Doubly linked list of the nodes, to allow O(1) merges.
        for (int i = 0; i < n; i++)
        {
            val[i] = nums[i];
            prv[i] = i - 1;
            nxt[i] = (i + 1 < n) ? i + 1 : -1;
        }

        set<pair<long long, int>> pairs; // {sum, left node index}
        long long bad = 0;
        for (int i = 0; i + 1 < n; i++)
        {
            pairs.insert({val[i] + val[i + 1], i});
            if (val[i] > val[i + 1])
                bad++;
        }

        int ops = 0;
        while (bad > 0)
        {
            ops++;
            int i = pairs.begin()->second; // left of the min-sum pair
            int j = nxt[i];
            int p = prv[i], q = nxt[j];

            // Drop the (up to) three pairs touching i and j.
            if (p != -1)
            {
                pairs.erase({val[p] + val[i], p});
                if (val[p] > val[i])
                    bad--;
            }
            pairs.erase({val[i] + val[j], i});
            if (val[i] > val[j])
                bad--;
            if (q != -1)
            {
                pairs.erase({val[j] + val[q], j});
                if (val[j] > val[q])
                    bad--;
            }

            // Merge j into i.
            val[i] += val[j];
            nxt[i] = q;
            if (q != -1)
                prv[q] = i;

            // Re-add the pairs around the merged node.
            if (p != -1)
            {
                pairs.insert({val[p] + val[i], p});
                if (val[p] > val[i])
                    bad++;
            }
            if (q != -1)
            {
                pairs.insert({val[i] + val[q], i});
                if (val[i] > val[q])
                    bad++;
            }
        }
        return ops;
    }
};
