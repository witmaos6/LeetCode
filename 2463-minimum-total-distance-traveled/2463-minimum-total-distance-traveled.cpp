class Solution {
    using Pair = pair<int, long long>;
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory)
    {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        const int NrOfRobots = static_cast<int>(robot.size());
        const int NrOfFactories = static_cast<int>(factory.size());
        
        vector<vector<long long>> Memo(NrOfRobots + 1, vector<long long>(NrOfFactories + 1));
        
        for(int i = 0; i < NrOfRobots; ++i)
        {
            Memo[i][NrOfFactories] = LLONG_MAX;
        }
        
        for(int i = NrOfFactories - 1; i >= 0; --i)
        {
            long long Prefix = 0;
            
            deque<Pair> Deque;
            Deque.emplace_back(NrOfRobots, 0);
            
            for(int j = NrOfRobots - 1; j >= 0; --j)
            {
                Prefix += abs(robot[j] - factory[i][0]);
                
                while(!Deque.empty() && Deque.front().first > j + factory[i][1])
                {
                    Deque.pop_front();
                }
                
                while(!Deque.empty() && Deque.back().second >= Memo[j][i + 1] - Prefix)
                {
                    Deque.pop_back();
                }
                
                Deque.emplace_back(j, Memo[j][i + 1] - Prefix);
                Memo[j][i] = Deque.front().second + Prefix;
            }
        }
        
        return Memo.front().front();
    }
};