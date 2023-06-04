class Solution
{
    vector<int> UnionFind;
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        const int N = static_cast<int>(isConnected.size());
        
        UnionFind.resize(N + 1);
        for(int i = 1; i <= N; i++)
        {
            UnionFind[i] = i;
        }
        
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(i != j && isConnected[i][j] == 1)
                {
                    Union(i + 1, j + 1);
                }
            }
        }
        
        int Province = 0;
        for(int i = 1; i <= N; i++)
        {
            if(UnionFind[i] == i)
            {
                Province++;
            }
        }
        
        return Province;
    }
    
private:
    void Union(int City1, int City2)
    {
        City1 = GetConnectedNode(City1);
        City2 = GetConnectedNode(City2);
        
        int Root = min(City1, City2);
        int Sub = max(City1, City2);
        
        UnionFind[Sub] = Root;
    }
    
    int GetConnectedNode(int City)
    {
        if(UnionFind[City] != City)
        {
            return GetConnectedNode(UnionFind[City]);
        }
        return City;
    }
};