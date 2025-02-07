class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries)
    {
        unordered_map<int, int> BallToColor;
        unordered_map<int, int> ColorToNum;

        vector<int> Result;
        Result.reserve(queries.size());

        for(vector<int>& Query : queries)
        {
            int Ball = Query[0];
            int Color = Query[1];

            if(BallToColor.find(Ball) == BallToColor.end())
            {
                ColorToNum[Color]++;
            }
            else
            {
                ColorToNum[BallToColor[Ball]]--;
                if(ColorToNum[BallToColor[Ball]] == 0)
                {
                    ColorToNum.erase(BallToColor[Ball]);
                }
                ColorToNum[Color]++;
            }
            BallToColor[Ball] = Color;
            Result.push_back(ColorToNum.size());
        }

        return Result;
    }
};