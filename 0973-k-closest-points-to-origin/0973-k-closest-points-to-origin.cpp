struct Point
{
    int Row;
    int Col;
    int Distance;
    Point(){}
    Point(int row, int col, int dis) : Row(row), Col(col), Distance(dis) {}
};

class Solution 
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        auto Compare = [](Point P1, Point P2)
        {
            return P1.Distance < P2.Distance;
        };
        
        priority_queue<Point, vector<Point>, bool(*)(Point P1, Point P2)> MaxHeap(Compare);
        
        for(vector<int>& P : points)
        {
            int Row = P[0];
            int Col = P[1];
            int Distance = GetDistanceFromCloset(Row, Col);
               
            MaxHeap.push(Point(Row, Col, Distance));
            if(MaxHeap.size() > k)
            {
                MaxHeap.pop();
            }
        }
            
        vector<vector<int>> Result(k);
        for(int i = 0; i < k; i++)
        {
            Result[i] = {MaxHeap.top().Row, MaxHeap.top().Col};
            MaxHeap.pop();
        }
        
        return Result;
    }
    
private:
    inline int GetDistanceFromCloset(int Row, int Col)
    {
        return (Row * Row) + (Col * Col);
    }
};