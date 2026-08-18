class Solution {
public:
    int largestInteger(vector<int>& nums, int k)
    {
        const int N = nums.size();
        unordered_map<int, int> Table;
        for(int& Num : nums)
        {
            Table[Num]++;
        }

        if(k == N)
        {
            return *max_element(nums.begin(), nums.end());
        }

        if(k == 1)
        {
            int MaxValue = -1;

            for(int& Num : nums)
            {
                if(Table[Num] == 1 && Num > MaxValue)
                {
                    MaxValue = Num;
                }
            }
            return MaxValue;
        }

        if(nums.front() == nums.back())
            return -1;
        
        if(Table[nums.front()] == 1 && Table[nums.back()] == 1)
        {
            return max(nums.front(), nums.back());
        }
        if(Table[nums.front()] == 1 && Table[nums.back()] > 1)
        {
            return nums.front();
        }
        if(Table[nums.back()] == 1 && Table[nums.front()] > 1)
        {
            return nums.back();
        }
        return -1;
    }
};