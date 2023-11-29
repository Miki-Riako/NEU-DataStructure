#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAXSIZE 128

typedef struct node           // Node
{                             // The multifork tree node which stores a string
    char *name;               // Domain name
    struct node *parent;      // Parent node
    struct node *firstChild;  // First child node
    struct node *nextSibling; // Next sibling node
} node;

node *leaf[MAXSIZE];
int leafCounter;
bool domainFlag;

void continueProgram(bool *flag)
{ // Check whether to continue the program
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    printf("\nPress Enter to continue, press any other key to leave . . .\n");
    char leave = _getch();
    if (leave == 13)
        *flag = true;
    else
        *flag = false;
}

node *newNode(char *name)
{ // Create a new node
    node *root = (node *)malloc(sizeof(node));
    root->name = name;
    root->parent = NULL;
    root->firstChild = NULL;
    root->nextSibling = NULL;
    return root;
}

void insertNode(node *parent, node *child)
{ // Insert a node into the tree
    if (parent == NULL || child == NULL)
        return;
    if (parent->firstChild == NULL)
    {
        child->parent = parent;
        parent->firstChild = child;
    }
    else
    { // If the parent node has children, find the last sibling node and insert it
        node *sibling = parent->firstChild;
        while (sibling->nextSibling != NULL)
            sibling = sibling->nextSibling;
        child->parent = parent;
        sibling->nextSibling = child;
    }
}

void refresh(void)
{
    leafCounter = 0;
    for (int i = 0; i < MAXSIZE; i++)
        leaf[i] = NULL;
}

void storePath(node *target)
{ // Store the domain name
    if (target->firstChild == NULL)
        leaf[leafCounter++] = target;
    else
    {
        for (node *child = target->firstChild; child != NULL; child = child->nextSibling)
            storePath(child);
    }
}

void printPath(node *target)
{
    refresh();
    storePath(target);
    for (int i = 0; i < leafCounter; i++)
    {
        node *ptr = leaf[i];
        while (true)
        {
            if (strcmp(ptr->parent->name, "root") == 0)
            {
                printf("%s\n", ptr->name);
                break;
            }
            else
            {
                printf("%s.", ptr->name);
                ptr = ptr->parent;
            }
        }
    }
}

void DFS(node *domain, char *target)
{ // Depth-First-Search
    if (domain == NULL)
        return;
    if (strcmp(domain->name, target) == 0)
    {
        printPath(domain);
        domainFlag = true;
    }
    for (node *child = domain->firstChild; child != NULL; child = child->nextSibling)
        DFS(child, target);
}

void BFS(node *domain, char *target)
{ // Breadth-First-Search
    if (domain == NULL)
        return;
    node *queue[MAXSIZE];
    int front = 0;
    int rear = 0;
    queue[rear++] = domain;
    while (front < rear)
    {
        node *cur = queue[front++];
        if (strcmp(cur->name, target) == 0)
        {
            printPath(cur);
            domainFlag = true;
        }
        if (cur->firstChild != NULL)
        {
            for (node *ptr = cur->firstChild; ptr != NULL; ptr = ptr->nextSibling)
                queue[rear++] = ptr;
        }
    }
}

node *dataBase(void)
{
    node *root = newNode("root");
    node *site = newNode("site");
    node *cn = newNode("cn");
    node *jp = newNode("jp");
    insertNode(root, site);
    insertNode(root, cn);
    insertNode(root, jp);
    node *cirno = newNode("cirno");
    node *edu = newNode("edu");
    node *com = newNode("com");
    node *ac = newNode("ac");
    insertNode(site, cirno);
    insertNode(cn, edu);
    insertNode(jp, ac);
    insertNode(cn, com);
    node *book = newNode("book");
    node *neu = newNode("neu");
    node *tsinghua = newNode("tsinghua");
    node *pku = newNode("pku");
    node *uTokyo = newNode("u-tokyo");
    node *apple = newNode("apple");
    insertNode(cirno, book);
    insertNode(edu, neu);
    insertNode(edu, tsinghua);
    insertNode(edu, pku);
    insertNode(ac, uTokyo);
    insertNode(com, apple);
    node *new = newNode("new");
    node *mail1 = newNode("mail");
    node *mail2 = newNode("mail");
    node *mail3 = newNode("mail");
    node *www1 = newNode("www");
    node *www2 = newNode("www");
    node *www3 = newNode("www");
    node *www4 = newNode("www");
    node *www5 = newNode("www");
    node *mathe = newNode("mathe");
    insertNode(book, new);
    insertNode(neu, mail1);
    insertNode(tsinghua, mail2);
    insertNode(pku, mail3);
    insertNode(neu, www1);
    insertNode(tsinghua, www2);
    insertNode(pku, www3);
    insertNode(apple, www4);
    insertNode(uTokyo, www5);
    insertNode(neu, mathe);

    // node *org = newNode("org");
    // insertNode(root, org);
    // node *baidu = newNode("baidu");
    // node *qq = newNode("qq");
    // node *gnu = newNode("gnu");
    // node *linux = newNode("linux");
    // insertNode(cn, baidu);
    // insertNode(cn, qq);
    // insertNode(org, gnu);
    // insertNode(org, linux);
    // node *google = newNode("google");
    // node *facebook = newNode("facebook");
    // node *amazon = newNode("amazon");
    // node *thu = newNode("thu");
    // insertNode(com, google);
    // insertNode(com, facebook);
    // insertNode(com, amazon);
    // insertNode(edu, thu);
    // node *www6 = newNode("www");
    // node *www7 = newNode("www");
    // node *www8 = newNode("www");
    // node *www9 = newNode("www");
    // node *www10 = newNode("www");
    // node *www11 = newNode("www");
    // node *www12 = newNode("www");
    // insertNode(baidu, www6);
    // insertNode(qq, www7);
    // insertNode(google, www8);
    // insertNode(facebook, www9);
    // insertNode(amazon, www10);
    // insertNode(pku, www11);
    // insertNode(gnu, www12);
    return root;
}
