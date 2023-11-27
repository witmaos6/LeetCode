class Solution {
    vector<vector<int>> Dir = {{4,6},{6,8},{7,9},{4,8},{3,9,0},{},{0,1,7},{2,6},{1,3},{2,4}};
    const int Mod = 1e9 + 7;
public:
    int knightDialer(int n)
    {
        array<long long, 10> Memo;
        fill(Memo.begin(), Memo.end(), 1);
        array<long long, 10> Temp;
        
        for(int i = 0; i < n - 1; i++)
        {
            fill(Temp.begin(), Temp.end(), 0);
            
            for(int j = 0; j < 10; j++)
            {
                for(int Next : Dir[j])
                {
                    Temp[Next] += Memo[j] % Mod;
                }
            }
            
            Memo = Temp;
        }
        
        long long Result = 0;
        for(long long Num : Memo)
        {
            Result = (Result + Num) % Mod;
        }
    
        return static_cast<int>(Result);
    }
};

