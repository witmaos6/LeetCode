class Solution {
    using Pair = pair<int, int>;
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit)
    {
        const int N = static_cast<int>(nums.size());

        vector<Pair> SortedPairs;
        for(int i = 0; i < N; i++)
        {
            SortedPairs.emplace_back(nums[i], i);
        }
        sort(SortedPairs.begin(), SortedPairs.end());

        vector<int> Result(N);
        int GroupBegin = 0;

        for(int i = 0; i < N; i++)
        {
            if(i == N - 1 || SortedPairs[i + 1].first - SortedPairs[i].first > limit)
            {
                vector<int> Indices;
                for(int j = GroupBegin; j <= i; j++)
                {
                    Indices.push_back(SortedPairs[j].second);
                }
                sort(Indices.begin(), Indices.end());

                int NrOfIndex = static_cast<int>(Indices.size());
                for(int j = 0; j < NrOfIndex; j++)
                {
                    Result[Indices[j]] = SortedPairs[GroupBegin + j].first;
                }

                GroupBegin = i + 1;
            }
        }

        return Result;
    }
};