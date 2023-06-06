class Solution {
    typedef pair<int, int> Difference;
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        
        vector<Difference> Diff;
        
        for(int i = 0; i < N - 1; i++)
        {
            int Temp = nums[i + 1] - nums[i];
            
            if(Diff.empty() || (Diff.back().first != Temp))
            {
                Diff.push_back({Temp, 1});
            }
            else if(Diff.back().first == Temp)
            {
                Diff.back().second++;
            }
        }
        
        int Count = 0;
        
        for(Difference& Value : Diff)
        {
            if(Value.second >= 2)
            {
                for(int i = 1; i < Value.second; i++)
                {
                    Count += Value.second - i;
                }
            }
        }
        
        return Count;
    }
};