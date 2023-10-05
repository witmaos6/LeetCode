class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int N = static_cast<int>(nums.size());
        
        unordered_map<int, int> Table;
        for(int Num : nums)
        {
            Table[Num]++;
        }
        
        vector<int> Result;
        int Major = N / 3;
        for(const pair<int, int>& Num : Table)
        {
            if(Num.second > Major)
            {
                Result.push_back(Num.first);
            }
        }
        
        return Result;
    }
};