class Solution {
    typedef pair<int, int> Point;
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k)
    {
        priority_queue<Point, vector<Point>> MaxHeap;
        
        int Result = INT_MIN;
        
        for(vector<int>& point : points)
        {
            while(!MaxHeap.empty() && point[0] - MaxHeap.top().second > k)
            {
                MaxHeap.pop();
            }
            
            if(!MaxHeap.empty())
            {
                int CurrSum = point[0] + point[1] + MaxHeap.top().first;
                Result = max(Result, CurrSum);
            }
            
            MaxHeap.push({point[1] - point[0], point[0]});
        }
        
        return Result;
    }
};