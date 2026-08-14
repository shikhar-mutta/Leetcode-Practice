// Link: https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        int n = tiles.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + (tiles[i][1] - tiles[i][0] + 1);

        long long best = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            long long carpetEnd = tiles[i][0] + carpetLen - 1;
            if (j < i) j = i;
            while (j < n && tiles[j][0] <= carpetEnd) j++;
            // tiles[i..j-1] are fully or partially covered; tile j-1 might be partial
            long long sum = prefix[j - 1] - prefix[i];
            int lastIdx = j - 1;
            long long covered = min((long long)tiles[lastIdx][1], carpetEnd) - tiles[lastIdx][0] + 1;
            sum += covered;
            best = max(best, sum);
        }
        return (int)best;
    }
};
