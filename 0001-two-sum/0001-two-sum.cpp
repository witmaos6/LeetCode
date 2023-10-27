class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        const int N = static_cast<int>(nums.size());
        unordered_map<int, int> Table;
        
        for(int i = 0; i < N; i++)
        {
            int TargetPair = target - nums[i];
            
            auto FindIt = Table.find(TargetPair);
            if(FindIt != Table.end())
            {
                return {i, FindIt->second};
            }
            
            Table[nums[i]] = i;
        }
        
        return {};
    }
};