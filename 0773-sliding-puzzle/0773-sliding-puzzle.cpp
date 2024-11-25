class Solution {
    using Info = pair<string, int>;
public:
    int slidingPuzzle(vector<vector<int>>& board)
    {
        const string Target = "123450";
        string Begin;
        for(vector<int>& Row : board)
        {
            for(int& Num : Row)
            {
                Begin += to_string(Num);
            }
        }
        
        if(Target == Begin)
            return 0;
        
        vector<vector<int>> Dir =
        {
            {1, 3},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4}
        };
        
        queue<Info> BFS;
        unordered_set<string> Visited;
        BFS.emplace(Begin, 0);
        Visited.insert(Begin);
        
        while(!BFS.empty())
        {
            auto[Board, MoveCount] = BFS.front();
            BFS.pop();
            
            if(Board == Target)
                return MoveCount;
            
            int Pos0 = Board.find('0');
            
            for(int& D : Dir[Pos0])
            {
                string NewBoard = Board;
                swap(NewBoard[Pos0], NewBoard[D]);
                
                if(Visited.find(NewBoard) == Visited.end())
                {
                    BFS.emplace(NewBoard, MoveCount + 1);
                    Visited.insert(NewBoard);
                }
            }
        }
        
        return -1;
    }
};

