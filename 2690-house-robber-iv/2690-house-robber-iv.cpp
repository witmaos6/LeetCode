class Solution {
public:
    int minCapability(vector<int>& nums, int k)
    {
        int L = *min_element(nums.begin(), nums.end());
        int R = *max_element(nums.begin(), nums.end());

        while(L < R)
        {
            int Mid = L + (R - L) / 2;
            if(CanSteal(nums, k, Mid))
            {
                R = Mid;
            }
            else
            {
                L = Mid + 1;
            }
        }
        return L;
    }

private:
    bool CanSteal(const vector<int>& Nums, int K, int Capability)
    {
        int Count = 0;
        int i = 0;
        const int N = static_cast<int>(Nums.size());
        while(i < N)
        {
            if(Nums[i] <= Capability)
            {
                Count++;
                i += 2;
            }
            else
            {
                i++;
            }
        }
        return Count >= K;
    }
};