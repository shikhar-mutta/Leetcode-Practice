// Link: https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + e), e = edges.size() (near-constant per union thanks to the
//     path-halving-style union used here)
// SC: O(n)
// Approach: union-find to group nodes into connected components, then for
// each component of size ct, the number of unreachable pairs it forms with
// every node NOT yet processed is ct * (nodes remaining after removing this
// component) - summing that (with a running "left" count shrinking by each
// component's size) counts every cross-component pair exactly once.
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        int parent[100000];
        for (int i = 0; i < n; i++)
            parent[i] = i;
        for (const vector<int>& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            int aOrg = a;
            int bOrg = b;
            while (a != parent[a])
                a = parent[a];
            while (b != parent[b])
                b = parent[b];
            parent[a] = parent[b] = parent[aOrg] = parent[bOrg] = min(a, b);
        }

        int count[100000] = {};
        int list[100000];
        int listCount = 0;

        for (int i = 0; i < n; i++) {
            int a = i;
            while (parent[a] != a)
                a = parent[a];
            if (count[a] == 0) {
                count[a] = 1;
                list[listCount++] = a;
            } else
                count[a]++;
        }

        long long ret = 0;
        long long left = n;

        for (int i = 0; i < listCount; i++) {
            long long ct = count[list[i]];
            left -= ct;
            ret += ct * left;
        }

        return ret;
    }
};
