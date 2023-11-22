class Solution {
    typedef pair<int, int> Point;
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums)
    {
        const int RowSize = static_cast<int>(nums.size());
        queue<Point> BFS;
        BFS.push({0, 0});
        vector<int> Result;
        
        while(!BFS.empty())
        {
            auto [Row, Col] = BFS.front();
            BFS.pop();
            
            Result.push_back(nums[Row][Col]);
            
            if(Col == 0 && Row < RowSize - 1)
            {
                BFS.push({Row + 1, Col});
            }
            if(Col + 1 < nums[Row].size())
            {
                BFS.push({Row, Col + 1});
            }
        }
        
        return Result;
    }
};