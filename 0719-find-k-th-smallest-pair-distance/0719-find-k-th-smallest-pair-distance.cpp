class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        const int Pairs = (N * (N - 1)) / 2;
        vector<int> Distances(Pairs);
        int Index = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = i + 1; j < N; j++)
            {
                Distances[Index] = abs(nums[i] - nums[j]);
                Index++;
            }
        }
        
        nth_element(Distances.begin(), Distances.begin() + (k - 1), Distances.end());
        return Distances[k - 1];
    }
};