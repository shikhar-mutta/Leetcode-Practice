// Link: https://leetcode.com/problems/design-bitset/description/

#include <bits/stdc++.h>
using namespace std;

class Bitset {
    vector<bool> arr;
    int n;
    bool flipAll = false;
    int cnt = 0;
public:
    Bitset(int size) {
        n = size;
        arr.assign(size, false);
    }

    void fix(int idx) {
        bool raw = true ^ flipAll;
        if (arr[idx] != raw) {
            cnt++;
            arr[idx] = raw;
        }
    }

    void unfix(int idx) {
        bool raw = false ^ flipAll;
        if (arr[idx] != raw) {
            cnt--;
            arr[idx] = raw;
        }
    }

    void flip() {
        flipAll = !flipAll;
        cnt = n - cnt;
    }

    bool all() {
        return cnt == n;
    }

    bool one() {
        return cnt > 0;
    }

    int count() {
        return cnt;
    }

    string toString() {
        string res(n, '0');
        for (int i = 0; i < n; i++) if (arr[i] ^ flipAll) res[i] = '1';
        return res;
    }
};
