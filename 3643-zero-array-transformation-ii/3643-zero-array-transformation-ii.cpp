class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries)
    {
        if(all_of(nums.begin(), nums.end(), [](int X) {
            return X == 0;
        }))
        {
            return 0;
        }
        const int N = static_cast<int>(nums.size());
        const int M = static_cast<int>(queries.size());
        int Result = -1;
        int L = 0;
        int R = M - 1;

        while(L <= R)
        {
            int Mid =  (L + R) / 2;
            vector<int> Pref(N + 1);

            for(int i = 0; i <= Mid; i++)
            {
                Pref[queries[i][0]] += queries[i][2];
                Pref[queries[i][1] + 1] -= queries[i][2];
            }

            for(int i = 1; i < N; i++)
            {
                Pref[i] += Pref[i - 1];
            }

            if(CanZero(nums, Pref))
            {
                Result = Mid + 1;
                R = Mid - 1;
            }
            else
            {
                L = Mid + 1;
            }
        }
        return Result;
    }

private:
    bool CanZero(const vector<int>& Arr, const vector<int>& Pref)
    {
        const int N = static_cast<int>(Arr.size());
        for(int i = 0; i < N; i++)
        {
            if(Arr[i] > Pref[i])
            {
                return false;
            }
        }
        return true;
    }
};