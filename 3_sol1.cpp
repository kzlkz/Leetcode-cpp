#include <algorithm>
#include <vector>
using std::max;
using std::vector;

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        static const int DICT_SIZE = 256;
        int strLength = s.size();
        if (strLength < 2)
        {
            return strLength;
        }

        vector<int> c(DICT_SIZE, 0);
        int i, j;
        int res = 0;
        j = 0;
        for (i = 0; i < strLength; i++)
        {
            c[s[i]]++;
            if (c[s[i]] > 1)
            {
                while (c[s[i]] > 1)
                {
                    c[s[j++]]--;
                }
            }
            res = max(res, i - j + 1);
        }
        c.clear();
        return res;
    }
};