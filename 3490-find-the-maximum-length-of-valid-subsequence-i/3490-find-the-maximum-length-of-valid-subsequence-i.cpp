class Solution {
public:
    int maximumLength(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        if(N == 2)
            return 2;

        bool Begin = nums[0] & 1;
        int Length[3] = {!Begin, Begin, 1};
        for(int i = 1; i < N; i++)
        {
            bool Curr = nums[i] & 1;
            Length[Curr&1]++;
            if(Curr != Begin)
            {
                Length[2]++;
                Begin = !Begin;
            }
        }
        return max({Length[0], Length[1], Length[2]});
    }
};