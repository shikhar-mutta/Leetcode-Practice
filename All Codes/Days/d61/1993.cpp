// Link: https://leetcode.com/problems/operations-on-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the number of nodes in the tree
// SC: O(n) where n is the number of nodes in the tree
// Approach:
//   1. We will use a vector to store the parent of each node and a vector to store the children of each node
//   2. We will use a vector to store the locked status of each node and the user who locked it
//   3. For the lock operation, we will check if the node is already locked and if not, we will lock it and return true, otherwise return false
//   4. For the unlock operation, we will check if the node is locked by the same user and if so, we will unlock it and return true, otherwise return false
//   5. For the upgrade operation, we will check if the node is unlocked and if it has at least one locked descendant and no locked ancestors, if so, we will lock the node and unlock all its descendants and return true, otherwise return false
class LockingTree
{
private:
    static inline int lkp[2000]{};
    static inline vector<int> adj[2000]{};
    const int n;
    const vector<int> &parent;

public:
    LockingTree(vector<int> &parent)
        : parent{parent}, n{static_cast<int>(parent.size())}
    {
        memset(lkp, 0, sizeof(int) * n);
        for (int i{0}; i < n; ++i)
            adj[i].clear();
        for (int i{1}; i < n; ++i)
            adj[parent[i]].push_back(i);
    }

    bool lock(int num, int user)
    {
        if (lkp[num])
            return false;
        lkp[num] = user;
        return true;
    }

    bool unlock(int num, int user)
    {
        if (!lkp[num] || lkp[num] != user)
            return false;
        lkp[num] = 0;
        return true;
    }

    bool upgrade(int num, int user)
    {
        for (int i{num}; i >= 0; i = parent[i])
        {
            if (lkp[i])
                return false;
        }
        auto chk{[&](this auto &&chk, const int i) -> bool
                 {
                     if (lkp[i])
                         return true;
                     for (const int j : adj[i])
                     {
                         if (chk(j))
                             return true;
                     }
                     return false;
                 }};
        if (!chk(num))
            return false;
        lkp[num] = user;
        auto ulck{[&](this auto &&ulck, const int i) -> void
                  {
                      lkp[i] = 0;
                      for (const int j : adj[i])
                          ulck(j);
                  }};
        for (const int j : adj[num])
            ulck(j);
        return true;
    }
};