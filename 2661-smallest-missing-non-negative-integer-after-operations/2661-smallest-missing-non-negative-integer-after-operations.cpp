class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value)
    {
        const int N = static_cast<int>(nums.size());
        int Result = 0;
        vector<int> Remains(value);

        for(int i = 0; i < N; i++)
        {
            int Index = ((nums[i] % value) + value) % value;
            Remains[Index]++;
        }
        while(Remains[Result % value]--)
            Result++;
        
        return Result;
    }
};