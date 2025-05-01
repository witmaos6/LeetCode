class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength)
    {
        int Left = 0;
        int Right = min(tasks.size(), workers.size());

        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        while(Left < Right)
        {
            int Mid = (Left + Right + 1) / 2;
            int UsedPills = 0;

            multiset<int> WorkersFree(workers.end() - Mid, workers.end());

            bool CanAssign = true;
            for(int i = Mid - 1; i >= 0; i--)
            {
                auto It = prev(WorkersFree.end());

                if(*It < tasks[i])
                {
                    It = WorkersFree.lower_bound(tasks[i] - strength);
                    if(It == WorkersFree.end())
                    {
                        CanAssign = false;
                        break;
                    }
                    ++UsedPills;
                    if(UsedPills > pills)
                    {
                        CanAssign = false;
                        break;
                    }
                }
                WorkersFree.erase(It);
            }
            if(CanAssign)
            {
                Left = Mid;
            }
            else
            {
                Right = Mid - 1;
            }
        }
        return Left;
    }
};