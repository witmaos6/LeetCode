/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
    vector<bool> Visited;
    vector<Node*> Graph;
public:
    Node* cloneGraph(Node* node)
    {   
        if(!node)
        {
            return nullptr;
        }
        Visited.resize(101);
        Graph.resize(101);
        return CloneGraph(node);
    }
private:
    Node* CloneGraph(Node* node)
    {
        if(node->neighbors.empty())
        {
            return new Node(node->val);
        }
        
        if(Graph[node->val] == nullptr)
        {
            Node* NewNode = new Node(node->val);
            Graph[node->val] = NewNode;
            
            for(Node* neighbor : node->neighbors)
            {
                if(Graph[neighbor->val])
                {
                    NewNode->neighbors.push_back(Graph[neighbor->val]);
                }
                else
                {
                    Node* AdjNode = CloneGraph(neighbor);
                    NewNode->neighbors.push_back(AdjNode);
                }
            }
            return NewNode;
        }
        
        return new Node(0);
    }
};