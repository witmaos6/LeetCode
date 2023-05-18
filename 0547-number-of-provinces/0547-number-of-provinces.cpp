class Solution
{
    vector<int> UnionFind;
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        const int N = static_cast<int>(isConnected.size());
        UnionFind.resize(N + 1);
        
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(isConnected[i][j])
                {
                    Union(i + 1, j + 1);
                }
            }
        }
        
        int Count = 0;
        for(int i = 1; i <= N; i++)
        {
            if(UnionFind[i] == 0)
            {
                Count++;
            }
        }
        
        return Count;
    }
    
private:
    void Union(int A, int B)
    {
        A = Find(A);
        B = Find(B);
        
        if(A != B)
        {
            UnionFind[A] = B;
        }
    }
    
    int Find(int Index)
    {
        if(UnionFind[Index] == 0)
        {
            return Index;
        }
        
        UnionFind[Index] = Find(UnionFind[Index]);
        return UnionFind[Index];
    }
};