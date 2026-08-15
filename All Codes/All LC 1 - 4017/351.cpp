// Link: https://leetcode.com/problems/android-unlock-patterns/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(9!)  SC: O(9)
// Approach: backtrack over key choices; a jump between two keys is only
// valid if the "skip" key between them (if any) is already visited
class Solution {
    int jump[10][10] = {};
    bool visited[10] = {};

    void setup() {
        jump[1][3] = jump[3][1] = 2;
        jump[1][7] = jump[7][1] = 4;
        jump[3][9] = jump[9][3] = 6;
        jump[7][9] = jump[9][7] = 8;
        jump[1][9] = jump[9][1] = 5;
        jump[3][7] = jump[7][3] = 5;
        jump[2][8] = jump[8][2] = 5;
        jump[4][6] = jump[6][4] = 5;
    }

    int dfs(int cur, int remaining) {
        if (remaining == 0) return 1;
        visited[cur] = true;
        int count = 0;
        for (int next = 1; next <= 9; next++) {
            if (visited[next]) continue;
            int mid = jump[cur][next];
            if (mid != 0 && !visited[mid]) continue;
            count += dfs(next, remaining - 1);
        }
        visited[cur] = false;
        return count;
    }

public:
    int numberOfPatterns(int m, int n) {
        setup();
        int total = 0;
        for (int len = m; len <= n; len++) {
            // corners 1,3,7,9 symmetric (x4), edges 2,4,6,8 symmetric (x4), center 5 (x1)
            total += dfs(1, len - 1) * 4;
            total += dfs(2, len - 1) * 4;
            total += dfs(5, len - 1);
        }
        return total;
    }
};
