#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();
        if (n == 0)
        {
            return "";
        }

        string res = strs[0];
        int i, j;
        int len, resLen;
        for (i = 1; i < n; i++)
        {
            len = strs[i].size();
            resLen = res.size();

            for (j = 0; j < len && j < resLen; j++)
            {
                if (strs[i][j] != res[j])
                {
                    res.resize(j);
                    break;
                }
            }
            if (j == len)
            {
                res.resize(j);
            }
        }
        return res;
    }
};