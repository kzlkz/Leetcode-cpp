//Binary-search
#include <iostream>
#include <algorithm>
#include <vector>
using std::min;
using std::vector;
using namespace std;

class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int len1 = nums1.size();
        int len2 = nums2.size();

        auto it1 = nums1.begin();
        auto it2 = nums2.begin();

        double res = 0;
        res += kthSmallest(it1, len1, it2, len2, len1 + len2 + 1 >> 1);
        res += kthSmallest(it1, len1, it2, len2, len1 + len2 + 2 >> 1);
        res /= 2.0;

        return res;
    }

  private:
    int kthSmallest(vector<int>::iterator it1, int len1,
                    vector<int>::iterator it2, int len2, int k)
    {
        if (len1 > len2)
            return kthSmallest(it2, len2, it1, len1, k);

        if (len1 == 0)
        {
            return it2[k - 1];
        }
        if (len2 == 0)
        {
            return it1[k - 1];
        }
        if (k == 1)
        {
            return min(it1[0], it2[0]);
        }

        int i = min(len1, k / 2);
        int j = min(len2, k / 2);
        if (it1[i - 1] > it2[j - 1])
        {
            return kthSmallest(it1, len1, it2 + j, len2 - j, k - j);
        }
        else
        {
            return kthSmallest(it1 + i, len1 - i, it2, len2, k - i);
        }
    }
};
