#include <stdio.h>

#define INF 9999
#define MAX 10

int main()
{
    int graph[MAX][MAX];
    int dist[MAX], visited[MAX];
    int n, source;
    int i, j, count, min, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);

            if(graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    for(i = 0; i < n; i++)
    {
        dist[i] = graph[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    for(count = 1; count < n; count++)
    {
        min = INF;
        u = -1;

        for(i = 0; i < n; i++)
        {
            if(!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if(u == -1)
            break;

        visited[u] = 1;

        for(i = 0; i < n; i++)
        {
            if(!visited[i] &&
               dist[u] + graph[u][i] < dist[i])
            {
                dist[i] = dist[u] + graph[u][i];
            }
        }
    }

    printf("\nShortest distances:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d -> %d = %d\n", source, i, dist[i]);
    }

    return 0;
}