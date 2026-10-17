class Solution {
    using Tuple = tuple<int, int, int>;
public:
    int minSwaps(vector<int>& nums)
    {
        const int N = nums.size();

        vector<Tuple> Tuples(N);
        for(int i = 0; i < N; i++)
        {
            int DigitSum = 0;
            int Num = nums[i];
            while(Num > 0)
            {
                DigitSum += Num % 10;
                Num /= 10;
            }
            Tuples[i] = {DigitSum, nums[i], i};
        }

        sort(Tuples.begin(), Tuples.end());

        vector<bool> Visited(N, false);
        int Count = 0;
        for(int i = 0; i < N; i++)
        {
            if(Visited[i] || get<2>(Tuples[i]) == i)
                continue;
            
            int j = i;
            int Len = 0;

            while(!Visited[j])
            {
                Visited[j] = true;
                j = get<2>(Tuples[j]);
                Len++;
            }
            Count += Len - 1;
        }
        
        return Count;
    }
};