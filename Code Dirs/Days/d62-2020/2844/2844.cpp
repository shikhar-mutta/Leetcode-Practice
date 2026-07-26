// Link: https://leetcode.com/problems/minimum-operations-to-make-a-special-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: a number (with leading zeros allowed after deletion) is divisible
// by 25 iff its last two digits are 00, 25, 50, or 75. Deleting characters
// keeps relative order, so scan from the right twice: once to find the
// cheapest way to end in "0" then another "0" or "5" before it (covers 00 and
// 50), once to find the cheapest way to end in "5" then a "2" or "7" before
// it (covers 25 and 75). Each pass counts how many characters must be
// deleted (everything not part of the chosen 2-digit ending); take the min
// of the two, with n==1 handled directly (a lone "0" is already special).
class Solution {
public:
    int minimumOperations(string num) {
        if(num.size() == 1 && num[0] == '0') return 0;
        if(num.size() ==1) return 1;

        // acha
        // divisible by 25
        // k
        // last two digits should be
        // 25 , 50 , 00, 75
        // bas
        // to min deleton for that
        // cool
        // ok
        // keep 5 last
        // keep 0 last
        // take min
        // ok
        string copy = num;
        int keep0 = 0 ;
        int keep5 = 0;
        bool found = false;
        bool foundnext1 = false;
        for(int i = num.size() - 1 ; i>=0 ; i--){
            if(!found && num[i] == '0'){
                found = 1;
            } else if(num[i] == '0' || num[i] == '5'){
                if(found){
                    foundnext1 = true;
                    break;
                } else {
                    keep0++;
                }
            } else {
                keep0++;
            }
        }
        // if(!foundnext) keep0 = num.size();
         found = false;
        bool foundnext2 = false;
        for(int i = num.size() - 1 ; i>=0 ; i--){
            if(!found && num[i] == '5'){
                            found = 1;
                        } else if(num[i] == '2' || num[i] == '7'){
                            if(found){
                                foundnext2 = true;
                                break;
                            } else {
                                keep5++;
                            }
                        } else {
                            keep5++;
                        }
        }
        if(!foundnext2) keep5 = num.size();
        return min(keep0 , keep5);


    }

};
