// Link: https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3) (n <= 10 per constraints, so the two nested substring loops
//     plus per-candidate stoi/substr work is cheap)
// SC: O(n) per candidate string built
// Approach: brute force every way to wrap parentheses around the '+':
// choose where they open (j, anywhere before '+') and close (k, anywhere
// after '+'). The value is left-prefix * (left-of-plus-inside-parens +
// right-of-plus-inside-parens) * right-suffix, where an empty
// prefix/suffix contributes a multiplicative identity of 1. Track the
// minimum product seen and its corresponding parenthesized string.
class Solution {
public:
    string minimizeResult(string expression) {
        int n = expression.size();
        int i = expression.find('+');
        int min_val = INT_MAX;
        string best = "";
        for(int j=0;j<i;j++){
            for(int k=i+1;k<n;k++){
                int l = j==0?1:stoi(expression.substr(0,j));
                int mid = stoi(expression.substr(j,i-j)) + stoi(expression.substr(i+1,k-i));
                int r = k==n-1?1:(stoi(expression.substr(k+1)));
                int poss = l*mid*r;
                if(poss<min_val){
                    min_val = poss;
                    best = expression.substr(0, j) + "(" +
                                expression.substr(j, i - j) + "+" +
                                expression.substr(i + 1, k - i) + ")" +
                                expression.substr(k + 1);
                }
            }
        }
        return best;
    }
};
