class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
    {
        int N = static_cast<int>(candies.size());
        vector<bool> Result(N);

        int Greatest = *max_element(candies.begin(), candies.end());

        for(int i = 0; i < N; i++)
        {
            if(candies[i] + extraCandies >= Greatest)
            {
                Result[i] = true;
            }
        }

        return Result;
    }
};