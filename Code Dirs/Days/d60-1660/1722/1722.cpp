// Link: https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/description/

#include <bits/stdc++.h>
using namespace std;

//TC: O(n + m * α(n)) where n is the length of source and target, m is the number of allowedSwaps, and α is the inverse Ackermann function. The union-find operations take O(α(n)) time on average, and we perform them for each allowed swap. The rest of the algorithm involves iterating through the components and counting frequencies, which takes O(n) time. 
//SC: O(n) for storing the components and frequency counts.
//Approach: 
// 1. Use union-find to group indices that can be swapped into connected components.
// 2. For each component, count the frequency of elements in the source array and compare it with the target array to determine how many elements can be matched.
// 3. The minimum Hamming distance is the total number of elements minus the number of matched elements.    
constexpr int N = 1e5 + 1;
int Rt[N], Rk[N];
int freq[N];
class UnionFind
{
public:
    UnionFind(int n)
    {
        iota(Rt, Rt + n, 0);
        fill(Rk, Rk + n, 0);
    }
    int Find(int x)
    {
        // compress path
        return (x == Rt[x]) ? x : Rt[x] = Find(Rt[x]);
    }
    bool Union(int x, int y)
    {
        x = Find(x), y = Find(y);
        if (x == y)
            return 0;
        if (Rk[x] > Rk[y])
            swap(x, y);
        Rt[x] = y;
        if (Rk[x] == Rk[y])
            Rk[y]++;
        return 1;
    }
};

class Solution
{
public:
    static int minimumHammingDistance(vector<int> &source, vector<int> &target,
                                      vector<vector<int>> &allowedSwaps)
    {
        const int n = source.size();
        UnionFind G(n);

        for (auto &sw : allowedSwaps)
            G.Union(sw[0], sw[1]);

        // Group indices in the same component
        vector<vector<int>> components(n);
        for (int i = 0; i < n; i++)
            components[G.Find(i)].push_back(i);

        int match = 0;

        // Process each component
        for (int i = 0; i < n; i++)
        {
            if (components[i].empty())
                continue;

            // Count freq of source
            for (int idx : components[i])
                freq[source[idx]]++;

            // Check how many target values in this component
            for (int idx : components[i])
            {
                if (freq[target[idx]] > 0)
                {
                    freq[target[idx]]--;
                    match++;
                }
            }

            // reset freq for the next component
            for (int idx : components[i])
                freq[source[idx]] = 0;
        }
        return n - match;
    }
};