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
                customers[i] = 0;
            }
        }
        
        int Memo = accumulate(customers.begin(), customers.begin() + minutes, 0);
        int Result = Total + Memo;
        
        for(int i = minutes; i < N; i++)
        {
            Memo -= customers[i - minutes];
            Memo += customers[i];
            
            Result = max(Result, Total + Memo);
        }
        return Result;
    }
};