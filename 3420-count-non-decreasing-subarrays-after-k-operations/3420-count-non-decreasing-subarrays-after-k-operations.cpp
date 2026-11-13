class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k)
    {
        deque<int> Starts;
        long long Result = 0;
        long long Water = 0;
        const int N = nums.size();
        int R = N - 1;

        for(int L = N - 1; L >= 0; L--)
        {
            int X = nums[L];
            while(!Starts.empty() && nums[Starts.front()] <= X)
            {
                int S = Starts.front();
                Starts.pop_front();
                int End = Starts.empty() ? R + 1 : Starts.front();
                Water += 1LL * (X - nums[S]) * (End - S);
            }
            Starts.push_front(L);

            while(Water > k)
            {
                Water -= nums[Starts.back()] - nums[R];
                if(Starts.back() == R)
                {
                    Starts.pop_back();
                }
                --R;
            }
            Result += R - L + 1;
        }
        return Result;
    }
};