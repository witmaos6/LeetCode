class Solution {
    const int Mod = 1e9 + 7;
public:
    int numFactoredBinaryTrees(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
        unordered_set<int> Table(arr.begin(), arr.end());
        unordered_map<int ,int> Memo;
        for(int Num : arr)
        {
            Memo[Num] = 1;
        }
        
        for(int Num1 : arr)
        {
            for(int Num2 : arr)
            {
                if(Num2 > sqrt(Num1))
                {
                    break;
                }
                
                int Child = Num1 / Num2;
                if(Num1 % Num2 == 0 && Table.find(Child) != Table.end())
                {
                    long long Temp = static_cast<long long>(Memo[Num2]);
                    Temp *= Memo[Child];
                    
                    if(Child == Num2)
                    {
                        Memo[Num1] = (Memo[Num1] + Temp) % Mod;
                    }
                    else
                    {
                        Memo[Num1] = (Memo[Num1] + Temp * 2) % Mod;
                    }
                }
            }
        }
        
        int Result = 0;
        for(auto& [Num, Value] : Memo)
        {
            Result = (Result + Value) % Mod;
        }
        return Result;
    }
};