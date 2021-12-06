#include <stdio.h>
#include <string.h>

#define V 6
#define MAX_QUE 100

int edge[V][V], queue[MAX_QUE], idx, visited[V];

void bfs(int cur, int n)
{
    int i;
    int next;
    if (visited[i] == 1)
        return;
    visited[i] = 1;

    while (queue[idx] != -1)
    {
        int j = 1;
        for (i = 0; i < n; i++)
        {
            if (edge[idx][i]==1)
            {
                printf("%d-->%d\n", idx, i);
                visited[i] = 1;
                queue[idx + j] = i;
                j++;
            }
        }
        idx++;
    }
    return;
}

void setval()
{
    int i = 0, j = 0;
    idx = 0;
    for (i = 0; i < MAX_QUE; i++)
        queue[i] = -1;
    for (i = 0; i < V; i++)
    {
        visited[i] = 0;
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
    queue[0] = 0;
    for (i = 0; i < V; i++)
    {
        bfs(0, V);
    }
    return 0;
}