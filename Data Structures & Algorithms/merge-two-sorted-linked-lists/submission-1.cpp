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

// brute force using an array 
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         vector<int> arr;
//         ListNode* temp = list1;
//         while(temp != nullptr){
//             arr.push_back(temp->val);
//             temp = temp->next;
//         }

//         temp = list2;
//         while(temp != nullptr){
//             arr.push_back(temp->val);
//             temp = temp->next;
//         }

//         sort(arr.begin(), arr.end());

//         ListNode* dummy = new ListNode(-1);
//         ListNode* curr = dummy;

//         for (int x : arr) {
//             curr->next = new ListNode(x);
//             curr = curr->next;
//         }

//         return dummy->next;

//     }
// };

// Optimal Solution
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        ListNode* t1 = list1;
        ListNode* t2 = list2;

        while(t1 != nullptr && t2 != nullptr){
            if(t1 -> val <= t2 -> val){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }

        if(t1 != nullptr){
            temp->next = t1;
        }
        else{
            temp->next = t2;
        }
        return dummy->next;
    }
};
