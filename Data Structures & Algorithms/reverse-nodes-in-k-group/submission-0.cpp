/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    ListNode* fillStack(stack<ListNode*>& st, ListNode* curr, int k) {
        int i = 0;

        while (curr && i < k) {
            st.push(curr); i++;
            curr = curr->next;
        }

        return curr;
    }

    ListNode* reverse(stack<ListNode*>& st, ListNode* nextGroupHead, ListNode* prevTail) {
        while (!st.empty()) {
            prevTail->next = st.top();
            st.pop();
            prevTail = prevTail->next;
        }
        prevTail->next = nextGroupHead;
        return prevTail;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0,head);
        
        ListNode* curr = head;
        ListNode* prevTail = &dummy;
        while (true) {
            stack<ListNode*> st;
            ListNode* nextGroupHead = fillStack(st,curr,k);
            if (st.size() < k) break;
            prevTail = reverse(st,nextGroupHead,prevTail);

            curr = nextGroupHead;
        }
        
        return dummy.next;
    }
};
