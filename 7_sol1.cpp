#include <climits>
#include <cstdint>

class Solution
{
  public:
    int reverse(int x)
    {
        const int base = 10;

        if (x == INT_MIN)
        {
            return 0;
        }

        if (x < 0)
        {
            return -reverse(-x);
        }

        int64_t res = 0;
        while (x > 0)
        {
            res = res * base + x % base;
            if (res > INT_MAX)
            {
                return 0;
            }
            x /= base;
        }

        return res;
    }
};