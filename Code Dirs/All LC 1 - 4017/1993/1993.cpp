// Link: https://leetcode.com/problems/operations-on-tree/description/

#include <bits/stdc++.h>
using namespace std;

class LockingTree {
public:
    vector<int> parent;
    vector<vector<int>> children;
    vector<int> lockedBy;

    LockingTree(vector<int>& parent_) {
        parent = parent_;
        int n = parent.size();
        children.assign(n, vector<int>());
        lockedBy.assign(n, -1);
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) children[parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user) {
        if (lockedBy[num] != -1) return false;
        lockedBy[num] = user;
        return true;
    }

    bool unlock(int num, int user) {
        if (lockedBy[num] != user) return false;
        lockedBy[num] = -1;
        return true;
    }

    bool hasLockedAncestor(int num) {
        int p = parent[num];
        while (p != -1) {
            if (lockedBy[p] != -1) return true;
            p = parent[p];
        }
        return false;
    }

    bool unlockDescendants(int num) {
        bool any = false;
        for (int c : children[num]) {
            if (lockedBy[c] != -1) {
                lockedBy[c] = -1;
                any = true;
            }
            any = unlockDescendants(c) || any;
        }
        return any;
    }

    bool upgrade(int num, int user) {
        if (lockedBy[num] != -1) return false;
        if (hasLockedAncestor(num)) return false;
        bool unlockedAny = unlockDescendants(num);
        if (!unlockedAny) return false;
        lockedBy[num] = user;
        return true;
    }
};
