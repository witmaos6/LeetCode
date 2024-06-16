class Solution {
public:
    int minPatches(vector<int>& nums, int n)
    {
        const int N = static_cast<int>(nums.size());
        long Missing = 1;
        int Patches = 0;
        int Index = 0;

        while (Missing <= n)
        {
            if (Index < N && nums[Index] <= Missing)
            {
                Missing += nums[Index];
                Index++;
            } 
            else
            {
                Missing += Missing;
                Patches++;
            }
        }

        return Patches;
    }
};