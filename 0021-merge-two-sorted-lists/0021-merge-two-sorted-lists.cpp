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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode* left = list1;
        ListNode* right = list2;
        ListNode* newHead =
            (left->val <= right->val) ? left : right;

        if (left->val <= right->val)
            left = left->next;
        else
            right = right->next;

        ListNode* mover = newHead;
        while (left && right) {
            if (left->val <= right->val) {
                mover->next = left;
                left = left->next;
            } else {
                mover->next = right;
                right = right->next;
            }
            mover = mover->next;
        }

        if (left)
            mover->next = left;

        if (right)
            mover->next = right;

        return newHead;
    }
};