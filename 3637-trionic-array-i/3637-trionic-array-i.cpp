class Solution {
public:
    bool isTrionic(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        int P = -1;
        int V = N;

        for(int i = 0; i < N - 1; i++)
        {
            if(P == -1 && nums[i] >= nums[i + 1])
            {
                P = i;
            }

            if(V == N && nums[N - 1 - i] <= nums[N - 2 - i])
            {
                V = N - 1 - i;
            }

            if(P > -1 && V < N)
                break;
        }

        if(P < 1 || V > N - 2)
            return false;

        for(int i = P; i < V; i++)
        {
            if(nums[i] <= nums[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};