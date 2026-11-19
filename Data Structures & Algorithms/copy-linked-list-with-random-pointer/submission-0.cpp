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
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> original_to_copy;
        original_to_copy[nullptr] = nullptr;

        Node* original_head = head;

        while(head) {
            original_to_copy[head] = new Node(head->val);
            
            head = head->next;
        }

        head = original_head;

        while(head) {
            original_to_copy[head]->random = 
            original_to_copy[head->random];

            original_to_copy[head]->next = 
            original_to_copy[head->next];
            head = head->next;
        }

        return (original_to_copy[original_head]);
    }
};
