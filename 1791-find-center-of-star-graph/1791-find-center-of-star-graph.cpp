class Solution {
public:
    int findCenter(vector<vector<int>>& edges)
    {
        int U1 = edges[0][0];
        int V1 = edges[0][1];
        int U2 = edges[1][0];
        int V2 = edges[1][1];
        
        if(U1 == U2 || U1 == V2)
        {
            return U1;
        }
        return V1;
    }
};