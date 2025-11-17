class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        int BeginIndex = 0;
        for(int i = 0; i < N; i++)
        {
            if(nums[i] == 1)
            {
                BeginIndex = i;
                break;
            }
        }

        int Count = 0;
        for(int i = BeginIndex + 1; i < N; i++)
        {
            if(nums[i] == 0)
            {
                Count++;
            }
            else if(nums[i] == 1)
            {
                if(Count < k)
                {
                    return false;
                }
                Count = 0;
            }
        }

        return true;
    }
};