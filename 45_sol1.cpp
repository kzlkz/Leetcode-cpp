class Solution
{
  public:
    int jump(vector<int> &nums)
    {
        auto &a = nums;
        int n = a.size();
        if (n < 2)
        {
            return 0;
        }

        int pos, new_pos;
        int cnt;
        int i;

        i = pos = 0;
        cnt = 0;

        while (true)
        {
            new_pos = pos;
            while (i <= pos)
            {
                new_pos = max(new_pos, i + a[i]);
                i++;
            }
            cnt++;
            pos = new_pos;
            if (pos >= n - 1)
            {
                break;
            }
        }
        return cnt;
    }
};