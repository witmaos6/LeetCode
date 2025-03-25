class Solution {
    using Pair = pair<int, int>;
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles)
    {
        vector<Pair> Horizontals;
        Horizontals.reserve(rectangles.size());
        for(vector<int>& Horizon : rectangles)
        {
            Horizontals.push_back({Horizon[0], Horizon[2]});
        }
        if(PossibleTwoCut(Horizontals))
        {
            return true;
        }

        vector<Pair> Verticals;
        Verticals.reserve(rectangles.size());
        for(vector<int>& Vertical : rectangles)
        {
            Verticals.push_back({Vertical[1], Vertical[3]});
        }
        if(PossibleTwoCut(Verticals))
        {
            return true;
        }
        return false;
    }

private:
    bool PossibleTwoCut(vector<Pair>& Arr)
    {
        sort(Arr.begin(), Arr.end());
        bool Check = false;
        int EndPoint = Arr[0].second;

        for(const auto&[Begin, End] : Arr)
        {
            if(EndPoint <= Begin)
            {
                if(Check)
                    return true;
                
                Check = true;
                EndPoint = End;
            }
            else
            {
                EndPoint = max(EndPoint, End);
            }
        }
        return false;
    }
};