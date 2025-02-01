class Solution {
public:
    bool isArraySpecial(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());

        for(int i = 0; i < N - 1; i++)
        {
            if((nums[i] & 1) == (nums[i + 1] & 1))
            {
                return false;
            }
        }
        return true;
    }
};