class Solution {
    using P = pair<int, int>;
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k)
    {
        const int N = static_cast<int>(arr.size());
        vector<pair<float, P>> Fractions;
        Fractions.reserve(N);
        for(int i = 0; i < N - 1; i++)
        {
            for(int j = i + 1; j < N; j++)
            {
                float Value = arr[i];
                Value /= arr[j];
                Fractions.push_back({Value, {arr[i], arr[j]}});
            }
        }
        
        sort(Fractions.begin(), Fractions.end());
        
        vector<int> Result(2);
        Result[0] = Fractions[k - 1].second.first;
        Result[1] = Fractions[k - 1].second.second;
        return Result;
    }
};