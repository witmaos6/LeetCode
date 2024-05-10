class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k)
    {
        const int N = static_cast<int>(arr.size());
        double Left = 0, Right = 1;
        vector<int> Result;

        while (Left <= Right)
        {
            double Mid = Left + (Right - Left) / 2;
            int j = 1, Total = 0, Num = 0, Den = 0;
            double MaxFrac = 0;
            for (int i = 0; i < N; i++)
            {
                while (j < N && arr[i] >= arr[j] * Mid)
                {
                    j++;
                }
                
                Total += N - j;

                if (j < N && MaxFrac < arr[i] * 1.0 / arr[j])
                {
                    MaxFrac = arr[i];
                    MaxFrac /= arr[j];
                    Num = i;
                    Den = j;
                }
            }

            if (Total == k)
            {
                Result = {arr[Num], arr[Den]};
                break;
            }

            if (Total > k)
            {
                Right = Mid;
            }
            else
            {
                Left = Mid;
            }
        }

        return Result;
    }
};