// Link: https://leetcode.com/problems/find-all-people-with-secret/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    int find(int x) {
        while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
        return x;
    }
    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra != rb) parent[ra] = rb;
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        unite(0, firstPerson);

        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b) { return a[2] < b[2]; });

        int m = meetings.size();
        int idx = 0;
        while (idx < m) {
            int t = meetings[idx][2];
            int j = idx;
            vector<int> people;
            while (j < m && meetings[j][2] == t) {
                unite(meetings[j][0], meetings[j][1]);
                people.push_back(meetings[j][0]);
                people.push_back(meetings[j][1]);
                j++;
            }
            int root0 = find(0);
            for (int p : people) {
                if (find(p) != root0) parent[p] = p;
            }
            idx = j;
        }

        vector<int> res;
        int root0 = find(0);
        for (int i = 0; i < n; i++) if (find(i) == root0) res.push_back(i);
        return res;
    }
};
