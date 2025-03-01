class Solution {
public:
    vector<int> applyOperations(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        for(int i = 0; i < N - 1; i++)
        {
            if(nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        int i = 0;
        for(int Num : nums)
        {
            if(Num != 0)
            {
                nums[i] = Num;
                i++;
            }
        }

        while(i < N)
        {
            nums[i] = 0;
            i++;
        }
        return nums;
    }
};