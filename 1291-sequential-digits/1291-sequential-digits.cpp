class Solution {
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> Result;
        
        for(int i = 1; i <= 9; i++)
        {
            int Num = i;
            int NextDigit = i + 1;
            
            while(Num <= high && NextDigit <= 9)
            {
                Num = Num * 10 + NextDigit;
                
                if(low <= Num && Num <= high)
                {
                    Result.push_back(Num);
                }
                
                NextDigit++;
            }
        }
        sort(Result.begin(), Result.end());
        
        return Result;
    }    
};