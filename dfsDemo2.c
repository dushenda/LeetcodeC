#include <stdio.h>
#include <string.h>

#define V 6

int edge[V][V], visited[V];

void dfs(int cur, int n)
{
    if (visited[cur] != 0)
    {
        return;
    }
    visited[cur] = 1;
    int i;
    for (i = 0; i < n; i++)
    {
        if (edge[cur][i] == 1)
        {
            printf("%d-->%d\n", cur, i);
            dfs(i, n);
        }
    }
    return;
}

void setval()
{
    memset(visited, 0, sizeof(int) * V);
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
    int i;
    for (i = 0; i < V; i++)
    {
        dfs(i, V);
    }
    return 0;
}