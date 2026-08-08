// Link: https://leetcode.com/problems/super-palindromes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        long long lo = stoll(left), hi = stoll(right);
        long long limit = (long long)sqrt((double)hi) + 1;
        set<long long> seen;
        int count = 0;

        for (long long half = 1; half <= 100000; half++) {
            string h = to_string(half);
            for (int type = 0; type < 2; type++) {
                string full = h;
                string rev = h;
                if (type == 1) rev.pop_back();
                reverse(rev.begin(), rev.end());
                full += rev;
                long long p = stoll(full);
                if (p > limit || seen.count(p)) continue;
                seen.insert(p);
                long long sq = p * p;
                if (sq >= lo && sq <= hi && isPalindrome(to_string(sq))) count++;
            }
            if (half > limit) break;
        }
        return count;
    }

private:
    bool isPalindrome(const string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) if (s[i++] != s[j--]) return false;
        return true;
    }
};
