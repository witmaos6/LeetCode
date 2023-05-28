class Solution {
    vector<vector<int>> Memo;
public:
    int minCost(int n, vector<int>& cuts)
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        Memo.resize(102, vector<int>(102));
        
        return DFS(cuts, 0, cuts.size() - 1);
    }
    
private:
    int DFS(vector<int>& Cuts, int Begin, int End)
    {
        if(End - Begin <= 1)
        {
            return 0;
        }
        
        if(Memo[Begin][End] > 0)
        {
            return Memo[Begin][End];
        }
        
        Memo[Begin][End] = INT_MAX;
        int CurrCut = Cuts[End] - Cuts[Begin];

        for(int i = Begin + 1; i < End; i++)
        {
            int Temp = CurrCut + DFS(Cuts, Begin, i) + DFS(Cuts, i, End);
            Memo[Begin][End] = min(Memo[Begin][End], Temp);
        }
        
        return Memo[Begin][End];
    }
};