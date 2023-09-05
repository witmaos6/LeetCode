/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        if(head == nullptr)
        {
            return nullptr;
        }
        
        unordered_map<Node*, Node*> OriginToCopy;
        
        Node* Origin = head;
        while(Origin)
        {
            OriginToCopy[Origin] = new Node(Origin->val);
            Origin = Origin->next;
        }
        
        Origin = head;
        while(Origin)
        {
            OriginToCopy[Origin]->next = OriginToCopy[Origin->next];
            OriginToCopy[Origin]->random = OriginToCopy[Origin->random];
            Origin = Origin->next;
        }
        
        return OriginToCopy[head];
    }
};