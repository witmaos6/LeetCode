class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr)
    {
        const int N = static_cast<int>(arr.size());

        vector<pair<int, int>> IndicesArr(N);
        for(int i = 0; i < N; i++)
        {
            IndicesArr[i] = {arr[i], i};
        }
        sort(IndicesArr.begin(), IndicesArr.end());

        vector<int> Result(N);
        int Rank = 0;
        int Prev = INT_MIN;
        for(int i = 0; i < N; i++)
        {
            if(Prev != IndicesArr[i].first)
            {
                Rank++;
            }
            Result[IndicesArr[i].second] = Rank;
            Prev = IndicesArr[i].first;
        }
        return Result;
    }
};