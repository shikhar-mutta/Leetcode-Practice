// Link: https://leetcode.com/problems/widest-possible-fence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        int n = planks.size();
        map<long long, long long> freq;
        for (int v : planks) freq[v]++;

        vector<long long> vals, cnt;
        for (auto& [v, c] : freq) { vals.push_back(v); cnt.push_back(c); }
        int d = vals.size();

        set<long long> candidates;
        for (int v : planks) candidates.insert(v);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                candidates.insert((long long)planks[i] + planks[j]);

        long long best = 1;
        for (long long H : candidates) {
            long long singles = freq.count(H) ? freq[H] : 0;
            long long pairs = 0;
            int lo = 0, hi = d - 1;
            while (lo <= hi) {
                long long s = vals[lo] + vals[hi];
                if (s < H) lo++;
                else if (s > H) hi--;
                else {
                    if (lo == hi) pairs += cnt[lo] / 2;
                    else pairs += min(cnt[lo], cnt[hi]);
                    lo++; hi--;
                }
            }
            best = max(best, singles + pairs);
        }
        return (int)best;
    }
};
