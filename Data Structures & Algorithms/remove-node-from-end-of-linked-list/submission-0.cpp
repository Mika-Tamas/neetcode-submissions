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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 1;
        ListNode* begin = head;
        while (head->next) {
            length++;
            head = head->next;
        }
        head = begin;
        int ind = length - n;
        if (ind == 0) return head->next;
        for (int i = 0; i < ind - 1; ++i) {
            head = head->next;
        }

        head->next = head->next->next;

        return begin;
    }
};
