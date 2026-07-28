// Link: https://leetcode.com/problems/find-all-people-with-secret/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(m log m + n)  SC: O(n + m)
// Approach: sort meetings by time, process in same-time groups (secret only
// spreads to people met AT THE SAME TIME as someone who already knows it,
// not chained across a later time). Union each group's meeting pairs, then
// for any person in the group not connected to 0, revert (undo) that
// person's union so the secret doesn't falsely propagate through them.
class Solution {
    vector<int> par;
    int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a != b) par[a] = b;
    }
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        unite(0, firstPerson);

        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b) { return a[2] < b[2]; });
        int m = meetings.size();
        int i = 0;
        while (i < m) {
            int j = i;
            vector<int> people;
            while (j < m && meetings[j][2] == meetings[i][2]) {
                unite(meetings[j][0], meetings[j][1]);
                people.push_back(meetings[j][0]);
                people.push_back(meetings[j][1]);
                j++;
            }
            int root0 = find(0);
            for (int p : people) {
                if (find(p) != root0) par[p] = p; // revert isolated person
            }
            i = j;
        }

        vector<int> res;
        int root0 = find(0);
        for (int p = 0; p < n; p++) if (find(p) == root0) res.push_back(p);
        return res;
    }
};
