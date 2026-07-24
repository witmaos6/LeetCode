class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums)
    {
        const int MaxXOR = 2048;
        vector<bool> Pair(MaxXOR);
        vector<bool> Triplet(MaxXOR);

        const int N = nums.size();

        for(int i = 0; i < N; i++)
        {
            for(int j = i; j < N; j++)
            {
                Pair[nums[i] ^ nums[j]] = true;
            }
        }

        for(int x = 0; x < MaxXOR; x++)
        {
            if(!Pair[x])
                continue;
            
            for(int& Num : nums)
            {
                Triplet[x ^ Num] = true;
            }
        }

        int Count = 0;
        for(int i = 0; i < MaxXOR; i++)
        {
            if(Triplet[i])
                Count++;
        }
        return Count;
    }
};