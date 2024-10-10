class Solution {
public:
    int maxWidthRamp(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        stack<int> Monotonic;
        
        for (int i = 0; i < N; ++i)
        {
            if (Monotonic.empty() || nums[Monotonic.top()] > nums[i])
            {
                Monotonic.push(i);
            }
        }
        
        int MaxWidth = 0;
        for (int i = N - 1; i >= 0; --i)
        {
            while (!Monotonic.empty() && nums[Monotonic.top()] <= nums[i])
            {
                MaxWidth = max(MaxWidth, i - Monotonic.top());
                Monotonic.pop();
            }
        }
        
        return MaxWidth;
    }
};