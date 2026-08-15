// Link: https://leetcode.com/problems/permutations-iv/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> permute(int n, long long k) {
        const long long LIM = (long long)1e15 + 1;
        vector<long long> fact(55, 1);
        for (int i = 1; i < 55; i++) {
            if (fact[i - 1] >= LIM / i)
                fact[i] = LIM;
            else
                fact[i] = fact[i - 1] * i;
        }
        auto ways = [&](int odd, int even) -> long long {
            if (abs(odd - even) > 1) return 0;
            if (fact[odd] >= LIM || fact[even] >= LIM) return LIM;
            __int128 val = (__int128)fact[odd] * fact[even];
            if (val > LIM) return LIM;
            return (long long)val;
        };
        vector<int> rem;
        for (int i = 1; i <= n; i++) rem.push_back(i);
        vector<int> ans;
        int lastParity = -1;
        for (int pos = 0; pos < n; pos++) {
            bool found = false;
            for (int i = 0; i < (int)rem.size(); i++) {
                int x = rem[i];
                int p = x & 1;
                if (lastParity != -1 && p == lastParity) continue;
                int odd = 0, even = 0;
                for (int j = 0; j < (int)rem.size(); j++) {
                    if (j == i) continue;
                    if (rem[j] & 1) odd++;
                    else even++;
                }
                long long cnt;
                if (odd + even == 0) {
                    cnt = 1;
                } else {
                    int need = p ^ 1;
                    if (need) {
                        if (odd != even && odd != even + 1)
                            cnt = 0;
                        else
                            cnt = ways(odd, even);
                    } else {
                        if (even != odd && even != odd + 1)
                            cnt = 0;
                        else
                            cnt = ways(odd, even);
                    }
                }
                if (k > cnt) {
                    k -= cnt;
                } else {
                    ans.push_back(x);
                    rem.erase(rem.begin() + i);
                    lastParity = p;
                    found = true;
                    break;
                }
            }
            if (!found) return {};
        }

        return ans;
    }
};
