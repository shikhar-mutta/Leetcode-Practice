// Link: https://leetcode.com/problems/abbreviating-the-product-of-a-range/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: The product of a range of numbers can be very large, so we need to find a way to represent it in a more compact form. We can do this by counting the number of trailing zeros in the product, which is determined by the number of factors of 2 and 5 in the range. We can also compute the last five digits of the product by stripping away the factors of 2 and 5 and taking the product modulo 100000. Finally, we can compute the first five digits of the product using logarithms to avoid overflow. The final result is then formatted as "prefix...suffix eC", where C is the number of trailing zeros.
class Solution
{
public:
    string abbreviateProduct(int left, int right)
    {
        long long cnt2 = 0, cnt5 = 0;
        long long suffixMod = stripped(left, right, 100000LL, cnt2, cnt5);
        long long C = min(cnt2, cnt5);

        long long leftoverBase = (cnt2 > cnt5) ? 2 : 5;
        long long leftoverExp = llabs(cnt2 - cnt5);
        suffixMod = (suffixMod * modpow(leftoverBase, leftoverExp, 100000LL)) %
                    100000LL;

        long double sumLn =
            lgammal((long double)right + 1.0L) - lgammal((long double)left);
        long double sumLog = sumLn / logl(10.0L);
        long long fullDigits = (long long)floorl(sumLog) + 1;
        long long d = fullDigits - C;

        if (d <= 10)
        {
            long long ec2, ec5;
            long long exactStripped = stripped(left, right, 0LL, ec2, ec5);
            long long lb = (ec2 > ec5) ? 2 : 5;
            long long le = llabs(ec2 - ec5);
            long long exactVal = exactStripped * ipow(lb, le);
            return to_string(exactVal) + "e" + to_string(C);
        }

        long double frac = sumLog - floorl(sumLog);
        long double val = powl(10.0L, frac + 4.0L);
        long long prefixNum = (long long)(val + 1e-9L);
        if (prefixNum >= 100000)
            prefixNum /= 10;

        string sufStr = to_string(suffixMod);
        while (sufStr.size() < 5)
            sufStr = "0" + sufStr;

        return to_string(prefixNum) + "..." + sufStr + "e" + to_string(C);
    }

private:
    long long stripped(int left, int right, long long mod, long long &cnt2,
                       long long &cnt5)
    {
        cnt2 = cnt5 = 0;
        long long result = (mod == 0) ? 1 : 1 % mod;
        for (int i = left; i <= right; ++i)
        {
            int x = i;
            while (x % 2 == 0)
            {
                x /= 2;
                ++cnt2;
            }
            while (x % 5 == 0)
            {
                x /= 5;
                ++cnt5;
            }
            if (mod == 0)
                result *= x;
            else
                result = (result * x) % mod;
        }
        return result;
    }

    long long modpow(long long base, long long exp, long long mod)
    {
        long long result = 1 % mod;
        base %= mod;
        while (exp > 0)
        {
            if (exp & 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }

    long long ipow(long long base, long long exp)
    {
        long long result = 1;
        while (exp > 0)
        {
            if (exp & 1)
                result *= base;
            base *= base;
            exp >>= 1;
        }
        return result;
    }
};
