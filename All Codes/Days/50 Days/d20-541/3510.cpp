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
            val[i] = nums[i];                  // Current value of the node, after merges.
            prv[i] = i - 1;                    // Previous node index, or -1 if none.
            nxt[i] = (i + 1 < n) ? i + 1 : -1; // Next node index, or -1 if none.
        }

        set<pair<long long, int>> pairs; // {sum, left node index}(sorted by sum).
        long long bad = 0;               // Number of pairs that are out of order.
        for (int i = 0; i + 1 < n; i++)
        {
            pairs.insert({val[i] + val[i + 1], i});
            if (val[i] > val[i + 1]) // This pair is out of order.
                bad++;
        }

        int ops = 0; // Number of merge operations performed.
        while (bad > 0)
        {
            ops++;
            int i = pairs.begin()->second; // min Sum index
            int nt = nxt[i];               // next
            int pr = prv[i];               // pre
            int ntt = nxt[nt];             // next of next

            // Drop the (up to) three pairs touching i ans nt.
            if (pr != -1)
            { // Drop the pair (pr, i).
                pairs.erase({val[pr] + val[i], pr});
                if (val[pr] > val[i]) // Reduce bad cnt
                    bad--;
            }

            pairs.erase({val[i] + val[nt], i}); // Drop the pair (i, nt).
            if (val[i] > val[nt])
                bad--;

            if (ntt != -1) // Drop the pair (nt, ntt).
            {
                pairs.erase({val[nt] + val[ntt], nt});
                if (val[nt] > val[ntt])
                    bad--;
            }

            // Merge nt into i.
            val[i] += val[nt];
            nxt[i] = ntt;
            if (ntt != -1)// Update the previous pointer of ntt, if it exists.
                prv[ntt] = i;

            // Re-add the pairs around the merged node.
            if (pr != -1)
            {
                pairs.insert({val[pr] + val[i], pr});
                if (val[pr] > val[i])
                    bad++;
            }
            if (ntt != -1)
            {
                pairs.insert({val[i] + val[ntt], i});
                if (val[i] > val[ntt])
                    bad++;
            }
        }
        return ops;
    }
};
