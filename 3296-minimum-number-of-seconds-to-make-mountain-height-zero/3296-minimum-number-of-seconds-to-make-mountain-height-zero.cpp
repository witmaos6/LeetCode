class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes)
    {
        const int N = static_cast<int>(workerTimes.size());
        long long Left = 1, Right = 1e16;
        while(Left < Right)
        {
            long long Mid = (Left + Right) >> 1;
            long long Tot = 0;

            for(int i = 0; i < N && Tot < mountainHeight; i++)
            {
                Tot += (long long)(sqrt((double)Mid / workerTimes[i] * 2 + 0.25) - 0.5);
            }

            if(Tot >= mountainHeight)
            {
                Right = Mid;
            }
            else
            {
                Left = Mid + 1;
            }
        }
        return Left;
    }
};