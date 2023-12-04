class Solution {
public:
    string largestGoodInteger(string num)
    {
        const int N = static_cast<int>(num.size());
        int MaxGoodNum = -1;
        string GoodStr;
        
        for(int i = 0; i < N - 2; i++)
        {
            if(num[i] == num[i + 1] && num[i + 1] == num[i + 2])
            {
                string CurrStr = num.substr(i, 3);
                int CurrNum = stoi(CurrStr);
                
                if(MaxGoodNum < CurrNum)
                {
                    MaxGoodNum = CurrNum;
                    GoodStr = CurrStr;
                }
            }
        }
        return GoodStr;
    }
};