class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k)
    {
        const int N = nums.size();
        
        int Max = nums.front();
        multiset<int> Mins(nums.begin(), nums.end());
        int Min = *Mins.begin();
        if(Max - Min <= k)
            return 0;

        for(int i = 1; i < N; i++)
        {
            Max = max(Max, nums[i]);
            auto It = Mins.find(nums[i - 1]);
            if(It != Mins.end())
                Mins.erase(It);

            Min = *Mins.begin();

            if(Max - Min <= k)
            {
                return i;
            }
        }

        return -1;
    }
};