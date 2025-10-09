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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        return mergeKListsH(lists, 0,lists.size()-1);
    }

    ListNode* mergeKListsH(vector<ListNode*>& lists, int start, int end) {
        if(start==end) return lists[start];
        if(start+1 == end) {
            return merger(lists[start],lists[end]);
        }

        int mid=start + (end-start)/2;
        ListNode* left=mergeKListsH(lists,start,mid);
        ListNode* right=mergeKListsH(lists, mid+1, end);

        return merger(left, right);
    }


    ListNode* merger(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        ListNode* cur=dummy;
        
        while(l1&&l2) {
            if(l1->val<l2->val) {
                cur->next=l1;
                l1=l1->next;
            }
            else {
                cur->next=l2;
                l2=l2->next;
            }

            cur=cur->next;
        }

        cur->next=l1?l1:l2;

        return dummy->next;
    }
};