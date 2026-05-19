class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int N = nums.size();
        int L = 0, R = N - 1;

        while(L < R)
        {
            int Mid = L + (R - L) / 2;

            if(nums[Mid] < nums[R])
            {
                R = Mid;
            }
            else if(nums[Mid] > nums[R])
            {
                L = Mid + 1;
            }
            else
            {
                R--;
            }
        }
        return nums[L];
    }
};