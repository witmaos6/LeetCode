class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers)
    {
        int CurrTime = customers[0][0];
        long long CurrWaitingSum = 0;
        for(const vector<int>& Customer : customers)
        {
            if(CurrTime < Customer[0])
            {
                CurrTime = Customer[0];
            }
            CurrTime += Customer[1];
            CurrWaitingSum += (CurrTime - Customer[0]);
        }
        
        double AverageWaiting = static_cast<double>(CurrWaitingSum) / static_cast<double>(customers.size());
        return AverageWaiting;
    }
};