// Link: https://leetcode.com/problems/most-frequent-prime/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(long long x) {
        if (x < 2) return false;
        for (long long i = 2; i * i <= x; i++)
            if (x % i == 0) return false;
        return true;
    }

    int mostFrequentPrime(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int dx[] = {-1,-1,-1,0,0,1,1,1};
        int dy[] = {-1,0,1,-1,1,-1,0,1};
        unordered_map<long long, int> freq;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int d = 0; d < 8; d++) {
                    long long num = mat[i][j];
                    int x = i + dx[d], y = j + dy[d];
                    while (x >= 0 && x < n && y >= 0 && y < m) {
                        num = num * 10 + mat[x][y];
                        if (num > 9 && isPrime(num)) freq[num]++;
                        x += dx[d]; y += dy[d];
                    }
                }
            }
        }
        long long best = -1;
        int bestFreq = 0;
        for (auto& [val, f] : freq) {
            if (f > bestFreq || (f == bestFreq && val > best)) {
                bestFreq = f;
                best = val;
            }
        }
        return (int)best;
    }
};
