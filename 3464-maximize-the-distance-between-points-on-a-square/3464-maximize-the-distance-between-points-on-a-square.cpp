class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k)
    {
        vector<long long> Arr;
        for(vector<int>& Point : points)
        {
            Arr.push_back(Flatten(Point, side));
        }
        sort(Arr.begin(), Arr.end());

        const int N = Arr.size();
        long long Low = 0, High = side, Result = 0;
        while(Low <= High)
        {
            long long Mid = (Low + High) / 2;
            if(!NotValid(Mid, N, k, Arr, side))
            {
                Result = Mid;
                Low = Mid + 1;
            }
            else
            {
                High = Mid - 1;
            }
        }
        return (int)Result;
    }

private:
    long long Flatten(vector<int>& Point, int Side)
    {
        long long X = Point[0];
        long long Y = Point[1];

        if(Y == 0)
            return X;
        if(X == Side)
            return Side + Y;
        if(Y == Side)
            return 3LL * Side - X;
        return 4LL * Side - Y;
    }

    bool NotValid(long long D, const int N, const int K, const vector<long long>& Arr, const int Side)
    {
        for(int i = 0; i < N; i++)
        {
            int Ptr = i;
            int Count = 1;

            while(Count < K)
            {
                long long Target = Arr[Ptr] + D;
                int j = lower_bound(Arr.begin(), Arr.end(), Target) - Arr.begin();

                if(j == N)
                    break;

                Ptr = j;
                Count++;

                if(D + Arr[Ptr] > Arr[i] + 4LL * Side)
                {
                    Count = 0;
                    break;
                }
            }

            if(Count == K)
                return false;
        }
        return true;
    }
};