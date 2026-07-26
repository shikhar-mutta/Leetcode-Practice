// Link: https://leetcode.com/problems/shortest-uncommon-substring-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * m^3) brute force, SC: O(m) per candidate substring
// Approach: For each string, try substring lengths from shortest to longest;
// for each length, generate every substring and keep it only if it doesn't
// appear in any other string. Among that length's valid candidates, pick
// the lexicographically smallest; stop at the first length with any match.
class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        vector<string> ans(n, "");

        for (int i = 0; i < n; i++) {
            int m = arr[i].size();

            // Try substring lengths from shortest to longest
            for (int len = 1; len <= m && ans[i] == ""; len++) {

                string best = "";

                for (int start = 0; start + len <= m; start++) {

                    string sub = arr[i].substr(start, len);

                    bool found = false;

                    // Check if this substring exists in any other string
                    for (int j = 0; j < n; j++) {
                        if (j == i)
                            continue; // don't check myself

                        if (arr[j].find(sub) !=
                            string::npos) { // substring exists in other string,
                                            // so break and it is not part of
                                            // result
                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        if (best == "" ||
                            sub < best) // here we are comparing strings for
                                        // smallest lexicographical order
                            best = sub;
                    }
                }

                if (best != "")
                    ans[i] = best;
            }
        }

        return ans;
    }
};
