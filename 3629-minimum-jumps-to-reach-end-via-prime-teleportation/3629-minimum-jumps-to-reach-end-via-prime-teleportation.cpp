class Solution {
public:
    int minJumps(vector<int>& nums)
    {
        const int N = nums.size();
        const int Max = *max_element(nums.begin(), nums.end());

        vector<bool> Prime(Max + 1, true);
        Prime[0] = false;
        Prime[1] = false;
        for(long long i = 2; i <= Max; i++)
        {
            if(Prime[i])
            {
                for(long long j = i * i; j <= Max; j += i)
                {
                    Prime[j] = false;
                }
            }
        }

        vector<vector<int>> Pos(Max + 1);
        for(int i = 0; i < N; i++)
        {
            Pos[nums[i]].push_back(i);
        }

        queue<pair<int, int>> Q;
        Q.push({0, 0});

        vector<bool> Visited(N);
        Visited[0] = true;

        while(!Q.empty())
        {
            auto[Index, Jump] = Q.front();
            Q.pop();

            if(Index == N - 1)
                return Jump;
            
            if(Index > 0 && !Visited[Index - 1])
            {
                Q.push({Index - 1, Jump + 1});
                Visited[Index - 1] = true;
            }
            if(Index < N - 1 && !Visited[Index + 1])
            {
                Q.push({Index + 1, Jump + 1});
                Visited[Index + 1] = true;
            }

            if(Prime[nums[Index]])
            {
                int P = nums[Index];
                for(int M = P; M <= Max; M += P)
                {
                    for(int I : Pos[M])
                    {
                        if(!Visited[I])
                        {
                            Q.push({I, Jump + 1});
                            Visited[I] = true;
                        }
                    }
                    Pos[M].clear();
                }
                Prime[P] = false;
            }
        }
        return N - 1;
    }
};