#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;          // 数据
    struct node *next; // 后继结点
} node, *LinkList;

typedef struct SqeList
{
    int array[64];
    int length;
} SeqList;

// Q1
/*
假设带头结点的单链表L，表中元素按递增有序排列
设计一个高效算法删除表中所有值相同的多余结点，使得表中元素的值各不相同。
1.写出算法的基本思想。
2.设计算法 void DelEqu（LinkList L）。
*/


/*算法的基本思想：
从头结点开始，依次遍历单链表
对于每个结点，判断其后继结点的值是否与当前结点的值相同
如果相同，则删除后继结点，否则继续遍历。
这样，可以保证每个元素的值只出现一次。
*/

void delEqu(LinkList L)
{ // 构造无重复数据的单链表
    if (L->next == NULL)
    { // 判断链表长度是否为1
        return;
    }
    LinkList ptr, ptrTemp;
    ptr = L->next;
    while (ptr != NULL)
    { // 遍历单链表
        ptrTemp = ptr->next;
        if (ptrTemp != NULL && ptrTemp->data == ptr->data)
        { // 判断值是否相同，删除相同的多余结点
            ptr->next = ptrTemp->next;
            free(ptrTemp);
        }
        else ptr = ptr->next;
    }
}

// Q2
/*
已知L是一个带头结点的单链表，请设计一个高效的算法求L中间位置的元素。
1.写出算法的基本思想。
2.设计算法 

*/

/*算法的基本思想：
使用两个指针ptrOne和ptrTwo，初始时都指向链表的头结点
然后ptrOne每次向后移动一个结点，ptrTwo每次向后移动两个结点
当ptrTwo到达链表尾部时，ptrOne就指向了链表的中间位置。
这个算法的时间复杂度是O(n)，其中n是链表的长度。
*/

int getMidElem(LinkList L)
{ // 求单链表的中间位置的元素
    if(L == NULL || L->next == NULL)
    { //判断链表是否为空
        return -1;
    }
    node *ptrOne = L, *ptrTwo = L;
    while(ptrTwo != NULL && ptrTwo->next != NULL)
    { //循环遍历链表
        ptrOne = ptrOne->next;
        ptrTwo = ptrTwo->next->next;
    }
    return ptrOne->data;
}

// Q3
/*
已知顺序表A，表中元素递增排列，设计高效算法删除表中所有值在[x，y]范围内的元素。要求
1.写出算法的基本思想
2.写出算法实现并分析算法的时间复杂度
*/

/*算法的基本思想：
基本思想是双指针法。
使用两个指针，rider用来遍历顺序表，newLen用来记录删除区间后的新长度。
将两个指针都初始化为0后，从左到右扫描顺序表，对于每个元素，判断它是否在区间内。
如果不在区间内，就将它复制到newLen位置，并将newLen加一。
如果在区间内，就跳过它，不做任何操作。
最后，将顺序表的长度更新为newLen。
*/

void deleteRange(SeqList *A, int x, int y)
{ // 有序顺序表的区间删除
    int rider = 0;
    int newLen = 0;
    for (rider = 0; rider < A->length; rider++)
    { // 循环遍历顺序表
        if (x <= A->array[rider] && A->array[rider] <= y)
        { // 判断是否在区间内
            continue;
        }
        A->array[newLen] = A->array[rider];
        newLen++;
    }
    A->length = newLen;
}

/*
时间复杂度是O(n)，其中n是顺序表的长度。
这是因为算法需要遍历顺序表的每个元素，判断是否在区间内，然后将不在区间内的元素移动到新的位置。
遍历和移动的操作都是常数时间，所以总的时间复杂度是O(n)。
*/
