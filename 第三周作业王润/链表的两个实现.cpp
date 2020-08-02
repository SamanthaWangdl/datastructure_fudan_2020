//单链表的第i个元素两种实现
Struct* getpose(int p, Struct* head) {
    int i = -1;
    struct* q = head;
    while (i！ = p && !q) {
        i++;
        q = q->next;
    }
    if (i == p)return q;
    if (!q) return null;
}

struct* getpose(int p, struct* head) {
    if (!head || !head->next) return null;
    if (!p)return head->next;
    if (p < 0)return null;
    struct* t = getpose(p - 1, head->next);
    if (t)return t->next;
    else return null;
}