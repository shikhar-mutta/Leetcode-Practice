// Link: https://leetcode.com/problems/find-the-sequence-of-strings-appeared-on-the-screen/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) (string copies), SC: O(n^2) total output size
// Approach: Build up the string one position at a time. At each new
// position, start from 'a' and record every intermediate string as its last
// character increments up to target's character at that position, then
// lock that position in and move to the next.
class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;

        string prev = "";

        for (int i = 0; i < target.size(); i++) {

            string temp = prev + "a";

            while (temp[i] < target[i]) {
                ans.push_back(temp);
                temp[i]++;
            }

            ans.push_back(temp);

            prev = temp;
        }

        return ans;
    }
};
