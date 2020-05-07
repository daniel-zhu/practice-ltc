/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* createNewListNode(void)
{
    struct ListNode *p = malloc(sizeof(struct ListNode));
    if (NULL == p) {
        return NULL;
    }
    p->val = 0;
    p->next = NULL;

    return p;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int value = 0;
    struct ListNode *head = NULL;
    struct ListNode *cur = NULL;
    struct ListNode* l1_ptr = l1;
    struct ListNode* l2_ptr = l2;

    if (NULL == l1_ptr || NULL == l2_ptr) {
        return NULL;
    }

    cur = createNewListNode();
    if (NULL == cur) {
        return NULL;
    }
    head = cur;

    while (1) {
        if (l1_ptr != NULL) {
            cur->val += l1_ptr->val;
        }
        if (l2_ptr != NULL) {
            cur->val += l2_ptr->val;
        }
        cur->val += value;
        if (cur->val >= 10) {
            cur->val -= 10;
            value = 1;
        }
        else {
            value = 0;
        }
        
        if (l1_ptr != NULL) {
            l1_ptr = l1_ptr->next;
        }
        if (l2_ptr != NULL) {
            l2_ptr = l2_ptr->next;
        }

        if ((NULL == l1_ptr) && (NULL == l2_ptr)) {
            if (value != 0) {
                cur->next = createNewListNode();
                if (cur->next != NULL) {
                    cur = cur->next;
                    cur->val = value;
                    cur->next = NULL;
                }
            }
            break;
        }

        cur->next = createNewListNode();
        if (NULL == cur->next) {
            break;
        }
        cur = cur->next;
    }

    return head;
}
