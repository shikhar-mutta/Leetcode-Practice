// Link: https://leetcode.com/problems/longest-balanced-substring-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: the alphabet here is only {a,b,c}, so a balanced substring
// uses exactly 1, 2, or 3 distinct letters:
// - 1 letter: longest run of a single repeated character.
// - 2 letters (a,b): within maximal runs restricted to those two
//   letters, track running difference d = count(a)-count(b); the first
//   time a given d value repeats, the substring between those two
//   positions has equal counts of a and b (classic equal-subarray via
//   prefix-difference + first-occurrence hashmap).
// - 3 letters: track (count(a)-count(b), count(b)-count(c)) as a pair
//   key over the whole string; a repeated key means the substring
//   between occurrences has all three counts equal.
class Solution {
    int calc1(const string& s) {
        int n = s.size(), res = 0, i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && s[j] == s[i]) j++;
            res = max(res, j - i);
            i = j;
        }
        return res;
    }
    int calc2(const string& s, char a, char b) {
        int n = s.size(), res = 0, i = 0;
        while (i < n) {
            while (i < n && s[i] != a && s[i] != b) i++;
            unordered_map<int,int> pos;
            pos[0] = i - 1;
            int d = 0;
            while (i < n && (s[i] == a || s[i] == b)) {
                d += (s[i] == a) ? 1 : -1;
                auto it = pos.find(d);
                if (it != pos.end()) res = max(res, i - it->second);
                else pos[d] = i;
                i++;
            }
        }
        return res;
    }
    int calc3(const string& s) {
        map<pair<int,int>,int> pos;
        pos[{0,0}] = -1;
        int cntA = 0, cntB = 0, cntC = 0, res = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == 'a') cntA++;
            else if (s[i] == 'b') cntB++;
            else cntC++;
            pair<int,int> k = {cntA - cntB, cntB - cntC};
            auto it = pos.find(k);
            if (it != pos.end()) res = max(res, i - it->second);
            else pos[k] = i;
        }
        return res;
    }
public:
    int longestBalanced(string s) {
        int x = calc1(s);
        int y = max({calc2(s, 'a', 'b'), calc2(s, 'b', 'c'), calc2(s, 'a', 'c')});
        int z = calc3(s);
        return max({x, y, z});
    }
};
