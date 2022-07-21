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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //reverse data
        int cnt = 1;
        ListNode* cur = head;
        while(cnt < left){
            cur = cur->next;
            cnt++;
        }
        vector<int>vals;
        ListNode* cur2 = cur;
        for(int i = left; i <= right; i++){
            // cout << cur2->val <<" ";
            vals.push_back(cur2->val);
            cur2 = cur2->next;
        }
        reverse(vals.begin(), vals.end());
        int k = 0;
        for(int i = left; i <= right; i++, cur = cur->next){
            // cout << cur->val <<" ";
            // cout << vals[k] <<" ";
            cur->val = vals[k++];
            // cout << cur->val <<" ";
        }
        return head;
    }
};