// Link: https://leetcode.com/problems/shortest-string-that-contains-three-strings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((|a|+|b|+|c|)^2) across all merges
// SC: O(|a|+|b|+|c|) per merged result
// Approach: try all 6 orderings of merging the three strings pairwise (merge
// first two, then merge that result with the third). calc(a,b) finds the best
// overlap of a prefix of b matching a suffix of a (or a fully containing b, or
// b fully containing a) to produce the shortest superstring of the two.
// Among the 6 final results, pick the shortest, tie-broken lexicographically.
class Solution {
private:
    string calc(const string& a, const string& b) {
        const int sa = a.size();
        const int sb = b.size();

        for (int i = 0; i < sa; i++) {
            int k = i;
            int j = 0;

            for (; j < sb; j++) {
                if (a[k] == b[j]) {
                    k++;
                } else {
                    break;
                }
            }

            if (j == sb) {
                return a;
            }
            if (k == sa) {
                return a + b.substr(j);
            }
        }

        return a + b;
    }

public:
    string minimumString(string a, string b, string c) {
        array<string, 6> v;

        v[0] = calc(calc(a, b), c);
        v[1] = calc(calc(a, c), b);
        v[2] = calc(calc(b, a), c);
        v[3] = calc(calc(b, c), a);
        v[4] = calc(calc(c, a), b);
        v[5] = calc(calc(c, b), a);

        return *min_element(v.begin(), v.end(),
                            [](const string& s, const string& t) {
                                if (s.size() == t.size()) {
                                    return s < t;
                                }
                                return s.size() < t.size();
                            });
    }
};
