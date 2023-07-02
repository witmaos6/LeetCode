class Solution {
    vector<int> Buildings;
    int NrOfReq = 0;
    int Result = 0;
public:
    int maximumRequests(int n, vector<vector<int>>& requests)
    {
        Buildings.resize(n);
        NrOfReq = static_cast<int>(requests.size());
        
        BackTracking(requests, 0, n, 0);
        return Result;
    }
    
private:
    void BackTracking(vector<vector<int>>& Requests, int Index, int N, int Count)
    {
        if(Index == NrOfReq)
        {
            for(int i = 0 ; i < N; i++)
            {
                if(Buildings[i] != 0)
                {
                    return;
                }
            }
            Result = max(Result, Count);
            return;
        }
        
        int From = Requests[Index][0];
        int To = Requests[Index][1];
        
        Buildings[From]--;
        Buildings[To]++;
        BackTracking(Requests, Index + 1, N, Count + 1);
        
        Buildings[From]++;
        Buildings[To]--;
        BackTracking(Requests, Index + 1, N , Count);
    }
};