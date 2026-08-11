class Solution {
public:
    int missingInteger(vector<int>& nums)
    {
        const int N = nums.size();
        unordered_set<int> Table(nums.begin(), nums.end());
        int Sum = nums[0];

        for(int i = 1; i < N; i++)
        {
            if(nums[i] == nums[i - 1] + 1)
                Sum += nums[i];
            else
                break;
        }

        while(Table.count(Sum))
        {
            Sum++;
        }
        return Sum;
    }
};