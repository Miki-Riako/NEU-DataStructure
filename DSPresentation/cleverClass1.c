#include <stdio.h>
#include <stdlib.h>

typedef struct node {  //结点
    int data;          //结点数据
    struct node *next; //后继结点
} node;

typedef struct List { //单链表
    node *head;       //头结点
    int len;          //链表长度
} LinkList;

void AmovB(LinkList *La, LinkList *Lb, int i, int len, int j)
{ // Q3: 将单链表A中自第i个元素起的共len个元素移到单链表B的第j个元素之前
    if (La->len < i || Lb->len < j)
    { // 错误情况
        return;
    }
    node *ptr = La->head;
    node *temp = Lb->head;
    for (int k = 0; k < i - 1; k++)
    { // 移动La中的指针至第i个元素位置
        ptr = ptr->next;
    }
    for (int k = 0; k < j - 2; k++)
    { // 移动Lb中的temp指针至第j元素之前即j-1个元素位置
        temp = temp->next;
    }
    node *tempNext = temp->next;
    temp->next = ptr;
    for (int k = 0; k < len - 1; k++)
    { // 移动ptr指针len-1步
        ptr = ptr->next;
    }
    ptr->next = tempNext;
}

void reverseList(LinkList *L, int k)
{ // Q4:将单链表中的前k个结点倒置，其余结点不变
    if (k <= 1 || k > L->len)
    { // 不倒置的情况
        return;
    }
    node *ptr = L->head;
    node *ptrNext = ptr->next;
    node *temp;
    for (int i = 1; i < k; i++)
    { // 交换k-1次得到倒置的链表
        temp = ptrNext->next;
        ptrNext->next = ptr;
        ptr = ptrNext;
        ptrNext = temp;
    }
    L->head->next = ptrNext;
    L->head = ptr;
}

// 例如：L=(1,3,2,4,5,9,8,6) ,当k=4时，单链表变成（4，2，3，1，5，9，8，6）
int main(void)
{
    LinkList L;
    node N[8];
    int arr[] = {1, 3, 2, 4, 5, 9, 8, 6};
    L.head = &N[0];
    L.len = sizeof(arr) / sizeof(int);
    for (int i = 0; i < L.len; i++)
    { // 将数组的元素依次插入到链表的头部
        N[i].data = arr[i];
        if (i == L.len - 1)
        {
            N[i].next = NULL;
        }
        else N[i].next = &N[i + 1];
    }
    printf("\nOld:\n");
    for (node *ptr = L.head; ptr != NULL; ptr = ptr->next)
    {
        printf("%d ", ptr->data);
    }
    reverseList(&L, 4);
    printf("\nNew:\n");
    for (node *ptr = L.head; ptr != NULL; ptr = ptr->next)
    {
        printf("%d ", ptr->data);
    }
}
