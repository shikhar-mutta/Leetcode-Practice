// Link: https://leetcode.com/problems/largest-palindromic-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) (fixed 10-digit frequency scan)
// SC: O(1)
// Approach: count digit frequencies. The left half is built by taking
// floor(count/2) copies of each digit, from 9 down to 1 (skipping leading
// zeros - only built at all if some nonzero digit has a pair, otherwise
// the whole number must just be "0"), placing higher digits first for
// maximum value. Any leftover single digit (highest remaining count) goes
// in the middle. The full palindrome is left + middle + reverse(left).
class Solution {
public:
    string largestPalindromic(string num) {
        array<int, 10> digits = {0}; //Occurence of each digit, low-effort "hashmap"
        for( char c : num){
            digits[c - '0']++; //Adds 1 to the corresponing digit
        }
        string left = ""; //Left half

        //Check if there are only zeros

        bool non_zero = false;
        for(int i = 9; i >= 1; i--){
            if(digits[i] >= 2) //More/equal than two non-zero numbers for palidrome
            non_zero = true;
        }

        if(non_zero){
            for(int i = 9; i >= 0; i--){
                left.append(digits[i] / 2, char(i + '0')); //Add as char in the right amount
                digits[i] = digits[i] % 2; //Update left digits
            }
        }

        string middle = "";
        for(int i = 9; i >= 0; i--){
            if(digits[i] > 0){ //There is a char
                middle += char(i + '0');
                break;
            }
        }

        string result = left + middle + string(left.rbegin(), left.rend());
        return result;

    }
};
