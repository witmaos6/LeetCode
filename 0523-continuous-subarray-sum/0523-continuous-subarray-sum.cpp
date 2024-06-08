class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        
        unordered_map<int, int> Remains;
        Remains[0] = -1;
        int PrefixSum = 0;
        
        for(int i = 0; i < N; i++)
        {
            PrefixSum += nums[i];
            
            int Remain = PrefixSum % k;
            
            if(Remains.find(Remain) != Remains.end())
            {
                if(i - Remains[Remain] > 1)
                {
                    return true;
                }
            }
            else
            {
                Remains[Remain] = i;
            }
        }
        
        return false;
    }
};