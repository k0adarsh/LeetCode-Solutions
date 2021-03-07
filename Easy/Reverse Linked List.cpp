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
    ListNode *resHead = NULL;

    ListNode* helperFunc(ListNode *node){

        if(node == NULL)
            return NULL;
        if(node->next == NULL){
            resHead = node;
            return node;
        }
        ListNode* front = helperFunc(node->next);
        front->next = node;
        node->next = NULL;
        return node;
    }
    ListNode* reverseList(ListNode* head) {

      ListNode *ptr = helperFunc(head);
      return resHead;

    }
};
