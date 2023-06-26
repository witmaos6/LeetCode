class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates)
    {
        const int N = static_cast<int>(costs.size());

        priority_queue<int, vector<int>, greater<int>> LeftSide;
        priority_queue<int, vector<int>, greater<int>> RightSide;
        
        long long Result = 0;
        int LeftPoint = 0;
        int RightPoint = N - 1;
        
        while(k > 0)
        {
            k--;
            while(LeftSide.size() < candidates && LeftPoint <= RightPoint)
            {
                LeftSide.push(costs[LeftPoint]);
                LeftPoint++;
            }
            while(RightSide.size() < candidates && LeftPoint <= RightPoint)
            {
                RightSide.push(costs[RightPoint]);
                RightPoint--;
            }
            
            if(LeftSide.empty())
            {
                Result += RightSide.top();
                RightSide.pop();
                continue;
            }
            else if(RightSide.empty())
            {
                Result += LeftSide.top();
                LeftSide.pop();
                continue;
            }
            
            if(LeftSide.top() <= RightSide.top())
            {
                Result += LeftSide.top();
                LeftSide.pop();
            }
            else
            {
                Result += RightSide.top();
                RightSide.pop();
            }
        }
        
        return Result;
    }
};