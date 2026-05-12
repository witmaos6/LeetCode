class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks)
    {
        sort(tasks.begin(), tasks.end(), [&](vector<int>& A, vector<int>& B){
            return A[1] - A[0] > B[1] - B[0];
        });

        int Start = tasks[0][1];
        int Bal = tasks[0][1] - tasks[0][0];
        int Loan = 0;

        const int N = tasks.size();
        for(int i = 1; i < N; i++)
        {
            int Cost = tasks[i][0];
            int Thresh = tasks[i][1];

            if(Bal < Thresh)
            {
                Loan += Thresh - Bal;
                Bal = Thresh;
            }

            Bal -= Cost;
        }
        return Start + Loan;
    }
};