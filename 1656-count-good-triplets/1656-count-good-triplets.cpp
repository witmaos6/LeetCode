class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c)
    {
        const int N = static_cast<int>(arr.size());
        int Count = 0;
        for(int i = 0; i < N - 2; i++)
        {
            for(int j = i + 1; j < N - 1; j++)
            {
                for(int k = j + 1; k < N; k++)
                {
                    if(abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                    {
                        Count++;
                    }
                }
            }
        }

        return Count;
    }
};