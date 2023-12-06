class Solution {
public:
    int totalMoney(int n)
    {
        int MondayPutMoney = 1;
        int SaveMoney = 0;
        
        while(n > 0)
        {
            int EndMoney = (n >= 7) ? MondayPutMoney + 6 : n - 1 + MondayPutMoney;
            int Week = (n >= 7) ? 7 : n;
            
            SaveMoney += (MondayPutMoney + EndMoney) * Week / 2;
            
            MondayPutMoney++;
            n -= 7;
        }
        return SaveMoney;
    }
};