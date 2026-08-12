class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k)
    {
        const int N = nums.size();
        unordered_map<int, int> Table;
        int MaxGood = 0;
        int Left = 0;

        for(int i = 0; i < N; i++)
        {
            Table[nums[i]]++;

            while(Table[nums[Left]] > k)
            {
                Table[nums[Left]]--;
                Left++;
            }

            MaxGood = max(MaxGood, i - Left + 1);
        }
        return MaxGood;
    }
};