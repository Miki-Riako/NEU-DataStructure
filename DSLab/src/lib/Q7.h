#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAXSIZE 100

typedef struct BtreeNode
{
    double data;
    char operation;
    struct BtreeNode *lchild;
    struct BtreeNode *rchild;
} BtreeNode;

BtreeNode *afaToBtree(char *input, int s, int e)
{
    int local_r = 0, flag = 0, i;
    int m_m_p = 0, a_s_p = 0, x = 0, ratio;
    for (i = s; i < e; i++)
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
            x++;
    if (!x)
    {
        int y;
        y = input[e - 1] - '0';
        for (i = e - 2, ratio = 1; i >= s; i--)
        {
            ratio = 10 * ratio;
            y = y + ratio * (input[i] - '0');
        }
        BtreeNode *bn = (struct BtreeNode *)malloc(sizeof(struct BtreeNode));
        if (!bn)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            printf("Malloc failed!\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            exit(1);
        }
        bn->data = y;
        bn->operation = NULL;
        bn->lchild = NULL;
        bn->rchild = NULL;
        return bn;
    }
    for (i = s; i < e; i++)
    {
        if (input[i] == '(')
            flag++;
        else if (input[i] == ')')
            flag--;
        if (!flag)
        {
            if (input[i] == '*' || input[i] == '/')
                m_m_p = i;
            else if (input[i] == '+' || input[i] == '-')
                a_s_p = i;
        }
    }
    if ((m_m_p == 0) && (a_s_p == 0))
        afaToBtree(input, s + 1, e - 1);
    else
    {
        if (a_s_p > 0)
            local_r = a_s_p;
        else if (m_m_p > 0)
            local_r = m_m_p;
        BtreeNode *b = (struct BtreeNode *)malloc(sizeof(struct BtreeNode));
        b->operation = input[local_r];
        b->lchild = afaToBtree(input, s, local_r);
        b->rchild = afaToBtree(input, local_r + 1, e);
        return b;
    }
}

double cal(BtreeNode *root)
{
    switch (root->operation)
    {
    case '+':
    {
        return cal(root->lchild) + cal(root->rchild);
        break;
    }
    case '-':
    {
        return cal(root->lchild) - cal(root->rchild);
        break;
    }
    case '/':
    {
        return cal(root->lchild) / cal(root->rchild);
        break;
    }
    case '*':
    {
        return cal(root->lchild) * cal(root->rchild);
        break;
    }
    }
    return root->data;
}
