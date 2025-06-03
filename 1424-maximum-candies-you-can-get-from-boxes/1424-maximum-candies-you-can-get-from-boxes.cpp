class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes)
    {
        const int N = static_cast<int>(status.size());
        int Result = 0;
        for(int& Init : initialBoxes)
        {
            status[Init] |= 2;
            if(status[Init] == 3)
            {
                Result += DFS(Init, status, candies, keys, containedBoxes);
            }
        }
        return Result;
    }
private:
    int DFS(int i, vector<int>& Status, vector<int>& Candies,
            vector<vector<int>>& Keys, vector<vector<int>>& ContainedBoxes)
    {
        int Result = Candies[i];
        Status[i] = 0;

        for(int& K : Keys[i])
        {
            Status[K] |= 1;
            if(Status[K] == 3)
            {
                Result += DFS(K, Status, Candies, Keys, ContainedBoxes);
            }
        }
        for(int& Box : ContainedBoxes[i])
        {
            Status[Box] |= 2;
            if(Status[Box] == 3)
            {
                Result += DFS(Box, Status, Candies, Keys, ContainedBoxes);
            }
        }
        return Result;
    }
};