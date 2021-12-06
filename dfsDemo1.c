#include <stdio.h>
#include <string.h>
#define V 6

/*
    INIT: edge[][]邻接矩阵，pre[], post[], tag全置0
    CALL: dfstag(i, n); pre/post: 开始、结束时间
*/

int edge[V][V], pre[V], post[V], tag;

void dfstag(int cur, int n)
{ // vertex: 0~n
    pre[cur] = ++tag;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (edge[cur][i])
        {
            printf("%d-->%d:", cur, i);
            if (0 == pre[i])
            {
                printf("Tree Edge!\n");
                dfstag(i, n);
            }
            else
            {
                if (0 == post[i])
                    printf("Back Edge!\n");
                else if (pre[i] > pre[cur])
                    printf("Forward Edge\n");
                else
                    printf("Cross Edge!\n");
            }
        }
    }
    post[cur] = ++tag;
}

void setval()
{
    memset(pre, 0, sizeof(int) * V);
    memset(post, 0, sizeof(int) * V);
    tag = 0;
    int i = 0, j = 0;
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
            edge[i][j] = 0;
    }
    edge[0][1] = 1;
    edge[0][3] = 1;
    edge[1][2] = 1;
    edge[0][3] = 1;
    edge[2][3] = 1;
    edge[3][1] = 1;
    edge[4][2] = 1;
    edge[4][5] = 1;
    edge[5][5] = 1;
}

int main()
{
    setval();
    int cur = 0;
    for (; cur < V; cur++)
    {
        if (0 == pre[cur])
        {
            printf("cur=%d:\n", cur);
            dfstag(cur, V);
            printf("**********\n");
        }
    }
    return 0;
}