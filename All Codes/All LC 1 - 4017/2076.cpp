// Link: https://leetcode.com/problems/process-restricted-friend-requests/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(requests * restrictions * alpha)  SC: O(n)
//  Approach: Union-Find over friendships. For each request (u,v), tentatively
//  check whether union(u,v) would place any restricted pair in the same
//  component (by comparing find() of both restriction endpoints against
//  find(u)/find(v)); if not, accept the request and union.
class DisjointSetUnion
{
public:
    int n;
    vector<int> size, parent;
    vector<bitset<1000>> restricts, groups;

    DisjointSetUnion(int n, vector<vector<int>> &restrictions)
    {
        this->n = n;
        size.resize(n, 1);
        restricts.resize(n, 0);
        groups.resize(n, 0);
        parent.resize(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            groups[i][i] = 1;
        }

        for (auto &restriction : restrictions)
        {
            int x = restriction[0], y = restriction[1];
            restricts[x][y] = 1;
            restricts[y][x] = 1;
        }
    }

    int Find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = Find(parent[x]);
    }

    bool Union(int x, int y)
    {
        // True: success, False: failed
        x = Find(x), y = Find(y);
        if (x == y)
            return true;
        if ((groups[x] & restricts[y]).any() || (groups[y] & restricts[x]).any())
            return false;
        if (size[y] > size[x])
            swap(x, y);

        groups[x] |= groups[y];
        restricts[x] |= restricts[y];
        size[x] += size[y];
        parent[y] = x;

        return true;
    }
};

class Solution
{
public:
    vector<bool> friendRequests(int n, vector<vector<int>> &restrictions, vector<vector<int>> &requests)
    {
        DisjointSetUnion djs(n, restrictions);

        vector<bool> result;
        for (auto &request : requests)
        {
            int x = request[0], y = request[1];
            result.push_back(djs.Union(x, y));
        }

        return result;
    }
};