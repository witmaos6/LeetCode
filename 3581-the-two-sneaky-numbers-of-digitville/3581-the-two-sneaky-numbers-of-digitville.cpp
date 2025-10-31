class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums)
    {
        vector<int> Table(nums.size());
        vector<int> Result;

        for(int& Num : nums)
        {
            Table[Num]++;
            if(Table[Num] == 2)
            {
                Result.push_back(Num);
            }
        }
        return Result;
    }
};