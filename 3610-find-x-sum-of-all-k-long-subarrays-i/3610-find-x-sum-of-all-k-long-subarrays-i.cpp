class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x)
    {
        const int N = static_cast<int>(nums.size());
        vector<int> Result;
        Result.reserve(N - k + 1);

        for(int i = 0; i <= N - k; i++)
        {
            vector<int> Sub(nums.begin() + i, nums.begin() + i + k);
            unordered_map<int, int> Freq;

            for(int& Num : Sub)
            {
                Freq[Num]++;
            }

            vector<pair<int, int>> FreqArr(Freq.begin(), Freq.end());
            sort(FreqArr.begin(), FreqArr.end(), [](auto& A, auto& B){
                if(A.second == B.second)
                    return A.first > B.first;
                return A.second > B.second;
            });

            unordered_set<int> Top;
            for(int j = 0; j < FreqArr.size() && j < x; j++)
            {
                Top.insert(FreqArr[j].first);
            }

            int Sum = 0;
            for(int& Num : Sub)
            {
                if(Top.count(Num))
                {
                    Sum += Num;
                }
            }
            Result.push_back(Sum);
        }
        return Result;
    }
};