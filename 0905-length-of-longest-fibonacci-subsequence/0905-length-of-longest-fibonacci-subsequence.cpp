class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr)
    {
        const int N = static_cast<int>(arr.size());
        unordered_set<int> Table(arr.begin(), arr.end());
        unordered_set<int> Sums;
        
        int MaxLength = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = i + 1; j < N; j++)
            {
                int Prev = arr[j];
                int Sum = arr[i] + Prev;
                int Length = 0;
                while(Table.count(Sum) == 1 && Sums.count(Sum) == 0)
                {
                    if(Length == 0)
                    {
                        Length = 3;
                    }
                    else
                    {
                        Length++;
                    }
                    int Temp = Sum;
                    Sum = Sum + Prev;
                    Prev = Temp;
                }
                MaxLength = max(MaxLength, Length);
            }
        }
        return MaxLength;
    }
};