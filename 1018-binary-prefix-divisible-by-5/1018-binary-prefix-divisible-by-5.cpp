class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) 
    {
        int Curr = 0;
        vector<bool> Result;
        Result.reserve(nums.size());
        for(int& Num : nums)
        {
            Curr += Num;
            Curr <<= 1;
            Curr %= 5;

            Result.push_back((Curr % 5 == 0));
        }
        return Result;
    }
};