class Solution
{
  public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        const int base = 10;
        int x1 = x;
        int r = 0;
        while (x1 > 0)
        {
            r = r * base + x1 % base;
            x1 /= R;
        }

        return r == x;
    }
};