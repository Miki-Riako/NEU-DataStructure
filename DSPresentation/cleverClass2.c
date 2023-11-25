#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct node
{                       // 结点
    int data;           // 结点数据
    struct node *left;  // 左子树
    struct node *right; // 右子树
} node;

typedef struct Graph
{                // 图
    int *vertex; // 图的顶点
    int **edge;  // 图的边
    int v, e;    // 顶点数和边数
} Graph;

int findMinIndex(int *final, int *dist, int size)
{ // 找到数组中具有最小值的元素索引
    int minIndex = 1;
    for (int i = 2; i < size; i++)
    {
        if (dist[i] < dist[minIndex] && final[i] != 1 && dist[i] != -1)
            minIndex = i;
    }
    return minIndex;
}

int findMaxIndex(int *dist, int size)
{ // 找到数组中具有最大值的元素索引
    int maxIndex = 1;
    for (int i = 2; i < size; i++)
    {
        if (dist[i] > dist[maxIndex])
            maxIndex = i;
    }
    return maxIndex;
}

node *LCA(node *root, node *x, node *y)
{ // 寻找最近共同祖先(LCA)
    if (root == NULL || root == x || root == y)
        return root; // 根结点为空或者根结点就是其中一个结点，直接返回根结点
    // 在左右子树中寻找x和y的最近共同祖先
    node *left = LCA(root->left, x, y);
    node *right = LCA(root->right, x, y);
    if (left != NULL && right != NULL)
        return root;
    // 左子树和右子树都非空，说明x和y分别在根结点的两侧，根结点就是LCA
    // 左子树或右子树只有一个找到了非空的结果，说明x和y都在同一侧，返回那个非空的结果
    return (left != NULL) ? left : right;
}

void Dijkstra(Graph *graph)
{                        // Dijkstra算法
    int final[graph->v]; // 是否找到路径
    int dist[graph->v];  // 最短路径长度
    int path[graph->v];  // 前驱
    final[0] = 1;
    dist[0] = 0;
    path[0] = -1;
    for (int i = 1; i < graph->v; i++)
    { // 初始化final、dist、edge
        // 对于final，除了0到0已经找到路径是1以外，其他都是0
        // 对于dist，寻找0到i的路径长度并存入
        // 对于edge，寻找path的前驱到0的路径长度
        final[i] = 0;
        if (graph->edge[0][i] != -1)
            dist[i] = graph->edge[0][i];
        else
            dist[i] = MAX;
        if (graph->edge[0][i] != -1)
            path[i] = 0;
        else
            path[i] = -1;
    }
    int i;
    for (i = 1; i < graph->v; i++)
    { // 标记未确定最短路径的节点为已找到路径并更新路径
        int index = findMinIndex(final, dist, graph->v);
        final[index] = 1;
        for (int j = 0; j < graph->v; j++)
        { // 更新路径长度dist和path
            if (graph->edge[index][j] != -1 && index != j && graph->edge[index][j] + dist[index] < dist[j])
            { // 判断路径长度是否小于已有路径
                dist[j] = dist[index] + graph->edge[index][j];
                path[i] = index;
            }
        }
    }
    int max = findMaxIndex(dist, graph->v); // 所有最短路径的最大值
    int printPath[graph->v];                // 把最大值索引存入数组
    printPath[0] = max;
    printf("length: %d\n", dist[max]);
    int j;
    for (j = 1; path[max] != -1; j++)
    { // 查找最小路径并存入printPath
        printPath[j] = path[max];
        max = path[max];
    }
    // 打印路径
    for (int i = j - 1; i > -1; i--)
        printf("%d ", printPath[i]);
    printf("\n");
}

void BuildGraph(Graph *graph)
{
    scanf("%d", &graph->v);
    graph->vertex = (int *)malloc(graph->v * sizeof(int));
    graph->edge = (int **)malloc(graph->v * sizeof(int *));
    for (int i = 0; i < graph->v; i++)
        graph->edge[i] = (int *)malloc(graph->v * sizeof(int));
    for (int i = 0; i < graph->v; i++)
        scanf("%d", &graph->vertex[i]);
    graph->e = 0;
    for (int i = 0; i < graph->v; i++)
    {
        for (int j = 0; j < graph->v; j++)
        {
            scanf("%d", &graph->edge[i][j]);
            if (graph->edge[i][j] != 0)
                graph->e++;
        }
    }
}

void cleanUp(Graph *graph)
{
    for (int i = 0; i < graph->v; i++)
        free(graph->edge[i]);
    free(graph->edge);
    free(graph->vertex);
}

int main(void)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    BuildGraph(graph);
    Dijkstra(graph);
    cleanUp(graph);
    free(graph);
    return 0;
}
