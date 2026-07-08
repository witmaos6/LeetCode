class SegmentTree
{
    struct Node
    {
        long long X;
        long long Sum;
        int Length;

        Node(long long _X = 0, long long _Sum = 0, int _Length = 0)
            : X(_X), Sum(_Sum), Length(_Length) {}
    };

    string Data;
    int N;
    vector<Node> Tree;
    vector<long long> Pow;
    const long long Mod = 1e9 + 7;

public:
    SegmentTree(const string& S)
    {
        Data = S;
        N = S.size();
        Tree.resize(N * 4);
        Pow.resize(N + 1);

        Pow[0] = 1;
        for(int i = 0; i < N; i++)
        {
            Pow[i + 1] = (Pow[i] * 10) % Mod;
        }

        Build(1, 0, N - 1);
    }

private:
    void Build(int Index, int Left, int Right)
    {
        if(Left == Right)
        {
            long long Digit = Data[Left] - '0';
            if(Digit == 0)
            {
                Tree[Index] = Node();
            }
            else
            {
                Tree[Index] = Node(Digit, Digit, 1);
            }
            return;
        }

        int Mid = (Left + Right) / 2;
        Build(2 * Index, Left, Mid);
        Build(2 * Index + 1, Mid + 1, Right);
        Tree[Index] = Merge(Tree[2 * Index], Tree[2 * Index + 1]);
    }

    Node Merge(const Node& Left, const Node& Right)
    {
        long long NewX = (Left.X * Pow[Right.Length] % Mod + Right.X) % Mod;
        long long NewSum = (Left.Sum + Right.Sum) % Mod;
        int NewLength = Left.Length + Right.Length;
        return Node(NewX, NewSum, NewLength);
    }

public:
    int Query(int Begin, int End)
    {
        Node CurrNode = Query(1, 0, N - 1, Begin, End);
        return (int)((CurrNode.X * CurrNode.Sum) % Mod);
    }
private:
    Node Query(int Index, int Left, int Right, int QL, int QR)
    {
        if(Left > QR || Right < QL)
            return Node();
        if(QL <= Left && Right <= QR)
            return Tree[Index];
        
        int Mid = (Left + Right) / 2;
        Node LeftNode = Query(2 * Index, Left, Mid, QL, QR);
        Node RightNode = Query(2 * Index + 1, Mid + 1, Right, QL, QR);
        return Merge(LeftNode, RightNode);
    }
};

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries)
    {
        SegmentTree STree(s);
        vector<int> Result;
        Result.reserve(queries.size());

        for(const vector<int>& Q : queries)
        {
            Result.push_back(STree.Query(Q[0], Q[1]));
        }
        return Result;
    }
};