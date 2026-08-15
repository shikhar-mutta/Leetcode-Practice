// Link: https://leetcode.com/problems/smallest-divisible-digit-product-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minAB;
    int maxA, maxB;

    array<int,4> digitContrib(int dig) {
        switch (dig) {
            case 1: return {0,0,0,0};
            case 2: return {1,0,0,0};
            case 3: return {0,1,0,0};
            case 4: return {2,0,0,0};
            case 5: return {0,0,1,0};
            case 6: return {1,1,0,0};
            case 7: return {0,0,0,1};
            case 8: return {3,0,0,0};
            case 9: return {0,2,0,0};
        }
        return {0,0,0,0};
    }

    array<int,4> applyDigit(array<int,4> req, int dig) {
        auto c = digitContrib(dig);
        for (int k = 0; k < 4; k++) req[k] = max(0, req[k] - c[k]);
        return req;
    }

    bool canComplete(array<int,4> req, long long positions) {
        int a = min(req[0], maxA), b = min(req[1], maxB);
        long long need = (long long)req[2] + req[3] + minAB[a][b];
        return need <= positions;
    }

    string freeConstruct(long long length, array<int,4> req) {
        string result;
        result.reserve(length);
        for (long long pos = 0; pos < length; pos++) {
            long long remaining = length - 1 - pos;
            for (int dig = 1; dig <= 9; dig++) {
                auto nreq = applyDigit(req, dig);
                if (canComplete(nreq, remaining)) {
                    result += ('0' + dig);
                    req = nreq;
                    break;
                }
            }
        }
        return result;
    }

    string smallestNumber(string num, long long t) {
        array<int,4> required = {0,0,0,0};
        int primes[4] = {2,3,5,7};
        for (int pi = 0; pi < 4; pi++) {
            while (t % primes[pi] == 0) { required[pi]++; t /= primes[pi]; }
        }
        if (t != 1) return "-1";

        maxA = required[0];
        maxB = required[1];
        minAB.assign(maxA + 1, vector<int>(maxB + 1, 0));
        vector<pair<int,int>> abOptions = {{1,0},{0,1},{2,0},{1,1},{3,0},{0,2}};
        for (int a = 0; a <= maxA; a++) {
            for (int b = 0; b <= maxB; b++) {
                if (a == 0 && b == 0) { minAB[a][b] = 0; continue; }
                int best = INT_MAX;
                for (auto& [da, db] : abOptions) {
                    int na = max(0, a - da), nb = max(0, b - db);
                    if (na == a && nb == b) continue; // no progress, skip to avoid self-reference
                    best = min(best, 1 + minAB[na][nb]);
                }
                minAB[a][b] = best;
            }
        }

        int L = num.size();
        vector<array<int,4>> prefixReq(L + 1);
        prefixReq[0] = required;
        int firstZeroPos = L;
        for (int i = 0; i < L; i++) {
            if (num[i] == '0') { firstZeroPos = i; break; }
            prefixReq[i+1] = applyDigit(prefixReq[i], num[i] - '0');
        }

        // check no-deviation case
        if (firstZeroPos == L) {
            bool satisfied = (prefixReq[L][0]==0 && prefixReq[L][1]==0 && prefixReq[L][2]==0 && prefixReq[L][3]==0);
            if (satisfied) return num;
        }

        int searchStart = min(L - 1, firstZeroPos);
        for (int i = searchStart; i >= 0; i--) {
            auto& req = prefixReq[i];
            int digStart = (num[i] - '0') + 1;
            for (int dig = digStart; dig <= 9; dig++) {
                auto nreq = applyDigit(req, dig);
                long long remaining = L - 1 - i;
                if (canComplete(nreq, remaining)) {
                    string prefix = num.substr(0, i);
                    string suffix = freeConstruct(remaining, nreq);
                    return prefix + (char)('0' + dig) + suffix;
                }
            }
        }

        // same length infeasible; try longer lengths
        for (long long newLen = L + 1; ; newLen++) {
            if (canComplete(required, newLen)) {
                return freeConstruct(newLen, required);
            }
        }
    }
};
