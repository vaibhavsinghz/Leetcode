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
        if(!list1) return list2;
        if(!list2) return list1;

        if(list1->val <= list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
    
    ListNode* findMid(ListNode* head){
        ListNode* slow = head, *fast = head, *temp;
        while(fast != NULL && fast -> next != NULL){
            temp = slow;
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        temp -> next = NULL;
        return slow;
    }
        
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head ->next == NULL) return head;
        ListNode* mid = findMid(head);
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(mid);
        return mergeTwoLists(l1, l2);
    }
};