class Solution {
public:
    int minOperations(vector<int>& nums)
    {
        const int N = nums.size();
        int Asc = 1;
        int Dsc = 1;

        for(int i = 1; i < N; i++)
        {
            Asc += nums[i] == (nums[i - 1] + 1) % N;
            Dsc += nums[i - 1] == (nums[i] + 1) % N;
        }

        if(Asc == N)
        {
            return nums.front() ? min(N - nums.front(), nums.front() + 2) : 0;
        }
        if(Dsc == N)
        {
            return min(N - nums.back(), nums.back()) + 1;
        }
        return -1;
    }
};