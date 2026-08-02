// Link: https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m)  SC: O(n + m)
// Approach: We can use Lucas's Theorem to check if the final two digits after all operations are the same. We can check the final two digits modulo 2 and modulo 5. If both modulo checks pass, then the final two digits are equal. We can precompute the values of C(n, k) % 5 for n, k < 5 and use them to calculate C(n, k) % 5 for larger n and k using Lucas's Theorem.
class Solution
{
private:
    // Precomputed C(n, k) % 5 for n, k < 5
    int pascal_mod_5[5][5] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 2, 1, 0, 0},
        {1, 3, 3, 1, 0},
        {1, 4, 1, 4, 1}};

    /**
     * @brief Calculates C(n_val, k_val) % 5 using Lucas's Theorem.
     */
    int get_lucas_mod5(int n_val, int k_val)
    {
        if (k_val < 0 || k_val > n_val)
        {
            return 0;
        }

        long long res = 1;

        // Process digits in base 5
        while (n_val > 0 || k_val > 0)
        {
            int n_digit = n_val % 5;
            int k_digit = k_val % 5;

            // C(n, k) % p = PROD( C(n_i, k_i) % p )
            res = (res * pascal_mod_5[n_digit][k_digit]) % 5;

            if (res == 0)
            {
                // If any C(n_i, k_i) is 0 (e.g., k_i > n_i), the whole product is 0.
                break;
            }

            n_val /= 5;
            k_val /= 5;
        }

        return (int)res;
    }

public:
    /**
     * @brief Checks if the final two digits after all operations are the same.
     */
    bool hasSameDigits(string s)
    {
        int n = s.length();
        if (n == 2)
        {
            return s[0] == s[1];
        }

        // Convert string to a vector of integers
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
        {
            nums[i] = s[i] - '0';
        }

        // k = number of operations = n - 2
        int k = n - 2;
        // m = n - 1 (used for mod 2 check)
        int m = n - 1;

        // 1. Check Modulo 2
        // We check if (SUM(C(m, i) * d[i] for i=0..m)) % 2 == 0
        int sum_mod2 = 0;
        for (int i = 0; i < n; ++i)
        { // i from 0 to m (which is n-1)
            // C(m, i) % 2 == 1 iff (m & i) == i (Lucas's Theorem for p=2)
            if ((m & i) == i)
            {
                sum_mod2 = (sum_mod2 + nums[i]) % 2;
            }
        }

        if (sum_mod2 != 0)
        {
            // D0 % 2 != D1 % 2, so they can't be equal
            return false;
        }

        // 2. Check Modulo 5
        // We check if D0 % 5 == D1 % 5
        // D0 = (SUM(C(k, i) * d[i] for i=0..k)) % 5
        // D1 = (SUM(C(k, i) * d[i+1] for i=0..k)) % 5

        int d0_mod5 = 0;
        int d1_mod5 = 0;

        for (int i = 0; i <= k; ++i)
        {
            // Get C(k, i) % 5 using Lucas's Theorem
            int coeff_mod5 = get_lucas_mod5(k, i);

            if (coeff_mod5 != 0)
            {
                // Use long long for intermediate multiplication to avoid overflow
                d0_mod5 = (d0_mod5 + (long long)coeff_mod5 * nums[i]) % 5;
                d1_mod5 = (d1_mod5 + (long long)coeff_mod5 * nums[i + 1]) % 5;
            }
        }

        if (d0_mod5 != d1_mod5)
        {
            // D0 % 5 != D1 % 5, so they can't be equal
            return false;
        }

        // 3. Final Result
        // If both mod 2 and mod 5 checks pass, then D0 % 10 == D1 % 10
        // Since D0 and D1 are digits (0-9), this implies D0 == D1.
        return true;
    }
};