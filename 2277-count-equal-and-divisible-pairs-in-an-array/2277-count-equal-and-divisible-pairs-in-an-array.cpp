class Solution {
public:
    int countPairs(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        vector<vector<int>> Table(101);
        int Count = 0;
        for(int i = 0; i < N; i++)
        {
            for(const int& Index : Table[nums[i]]) 
            {
                if((Index * i) % k == 0)
                {
                    Count++;
                }
            }
            Table[nums[i]].push_back(i);
        }

        return Count;
    }
};