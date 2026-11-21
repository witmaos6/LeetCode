class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s)
    {
        const int N = parent.size();
        vector<vector<int>> Children(N);

        for(int X = 1; X < N; X++)
        {
            Children[parent[X]].push_back(X);
        }
        vector<int> Size(N, 1);
        vector<int> Above(N);

        array<int, 26> Last;
        Last.fill(-1);
        vector<int> Stack{0};

        while(!Stack.empty())
        {
            int X = Stack.back();
            Stack.pop_back();

            if(X >= 0)
            {
                int C = s[X] - 'a';
                Above[X] = Last[C];
                Last[C] = X;
                Stack.push_back(~X);
                Stack.insert(Stack.end(), Children[X].begin(), Children[X].end());
            }
            else
            {
                X = ~X;
                Last[s[X] - 'a'] = Above[X];
                if(X)
                {
                    int Index = Above[X] >= 0 ? Above[X] : parent[X];
                    Size[Index] += Size[X];
                }
            }
        }
        return Size;
    }
};