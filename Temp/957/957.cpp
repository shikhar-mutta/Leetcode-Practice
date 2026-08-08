// Link: https://leetcode.com/problems/prison-cells-after-n-days/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        if (n == 0) return cells;
        unordered_map<int,int> seen;
        vector<vector<int>> history;
        vector<int> cur = cells;
        int day = 0;
        while (day < n) {
            int key = encode(cur);
            if (seen.count(key)) {
                int cycleLen = day - seen[key];
                int remaining = (n - day) % cycleLen;
                for (int i = 0; i < remaining; i++) cur = nextDay(cur);
                return cur;
            }
            seen[key] = day;
            history.push_back(cur);
            cur = nextDay(cur);
            day++;
        }
        return cur;
    }

private:
    int encode(vector<int>& cells) {
        int key = 0;
        for (int c : cells) key = key * 2 + c;
        return key;
    }
    vector<int> nextDay(vector<int>& cells) {
        int n = cells.size();
        vector<int> next(n, 0);
        for (int i = 1; i < n - 1; i++) {
            next[i] = (cells[i-1] == cells[i+1]) ? 1 : 0;
        }
        return next;
    }
};
