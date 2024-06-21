class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes)
    {
        const int N = static_cast<int>(customers.size());
        if(minutes == N)
        {
            return accumulate(customers.begin(), customers.end(), 0);
        }
        
        int Total = 0;
        for(int i = 0; i < N; i++)
        {
            if(grumpy[i] == 0)
            {
                Total += customers[i];
            }
        }
        
        int Memo = 0;
        for(int i = 0; i < minutes; i++)
        {
            if(grumpy[i] == 1)
            {
                Memo += customers[i];
            }
        }
        int Result = Total + Memo;
        
        for(int i = 0; i < N - minutes; i++)
        {
            if(grumpy[i] == 1)
            {
                Memo -= customers[i];
            }
            if(grumpy[i + minutes] == 1)
            {
                Memo += customers[i + minutes];
            }
            
            Result = max(Result, Total + Memo);
        }
        return Result;
    }
};