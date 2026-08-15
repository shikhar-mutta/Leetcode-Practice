// Link: https://leetcode.com/problems/find-the-peaks/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> res;
        for (int i = 1; i + 1 < (int)mountain.size(); i++)
            if (mountain[i] > mountain[i-1] && mountain[i] > mountain[i+1]) res.push_back(i);
        return res;
    }
};
