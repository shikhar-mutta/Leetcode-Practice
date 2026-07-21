// Link: https://leetcode.com/problems/integer-to-english-words/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) - where n is the number of digits in the input number
// SC: O(1) - constant space used for the string representations of numbers
//  Approach:
//   1. Create a helper function that converts numbers less than 1000 to words
//   2. Use the helper function to convert the input number to words by breaking it into chunks of 3 digits and appending the appropriate scale (thousand, million, billion)
//   3. Return the final string representation of the number in words
class Solution
{
public:
    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";
        return helper(num);
    }

private:
    const vector<string> belowTwenty = {
        "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
        "Seventeen", "Eighteen", "Nineteen"};

    const vector<string> tens = {
        "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string helper(int num)
    {
        string s;
        if (num < 20)
        {
            s = belowTwenty[num];
        }
        else if (num < 100)
        {
            s = tens[num / 10] + " " + belowTwenty[num % 10];
        }
        else if (num < 1000)
        {
            s = helper(num / 100) + " Hundred " + helper(num % 100);
        }
        else if (num < 1000000)
        {
            s = helper(num / 1000) + " Thousand " + helper(num % 1000);
        }
        else if (num < 1000000000)
        {
            s = helper(num / 1000000) + " Million " + helper(num % 1000000);
        }
        else
        {
            s = helper(num / 1000000000) + " Billion " + helper(num % 1000000000);
        }
        // Trim leading/trailing spaces
        size_t start = s.find_first_not_of(" ");
        size_t end = s.find_last_not_of(" ");
        return (start == string::npos) ? "" : s.substr(start, end - start + 1);
    }
};