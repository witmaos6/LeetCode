class Solution {
public:
    int missingMultiple(vector<int>& nums, int k)
    {
        unordered_set<int> Table(nums.begin(), nums.end());

        int Last = 0;
        for(int i = 1; i * k <= 100; i++)
        {
            if(!Table.count(i * k))
            {
                return i * k;
            }
            Last = i;
        }

        return (Last + 1) * k;
    }
};