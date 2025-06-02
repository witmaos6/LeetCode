class Solution {
public:
    int candy(vector<int>& ratings)
    {
        int N = static_cast<int>(ratings.size());
        
        if (N == 1)
        {
            return 1;
        }
        
        vector<int> AllocateCandy(N, 1);
        
        for (int i = 1; i < N; i++)
        {
            if(ratings[i] > ratings[i - 1])
            {
                AllocateCandy[i] = AllocateCandy[i - 1] + 1;
            }
        }
        
        for(int i = N - 2; i >= 0; i--)
        {
            if(ratings[i] > ratings[i + 1])
            {
                AllocateCandy[i] = max(AllocateCandy[i], AllocateCandy[i + 1] + 1);
            }
        }
        
        int Result = 0;
        for(int Candy : AllocateCandy)
        {
            Result += Candy;
        }
        return Result;
    }
};