#include <stdio.h>
#include <string.h>

#define MAX 500
#define INF 999999

char name[MAX][64];
int graph[MAX][MAX];
int n = 0;

int getNode(char s[]){
    for(int i = 0; i < n; i++){
        if(strcmp(name[i], s) == 0)
            return i;
    }

    strcpy(name[n], s);
    return n++;
}

int main(){

    FILE *fp;
    char a[64], b[64];
    int min, max, u, v, w;

    fp = fopen("navigation_data.txt", "r");

    if(fp == NULL){
        printf("Cannot open navigation_data.txt\n");
        return 1;
    }

    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            graph[i][j] = (i == j) ? 0 : INF;

char line[256];

while(fgets(line, sizeof(line), fp)){

    if(line[0] == '#' || line[0] == '\n')
        continue;

    if(sscanf(line, "%63s %63s %d %d", a, b, &min, &max) != 4)
        continue;

    u = getNode(a);
    v = getNode(b);

    w = (min + max) / 2;

    graph[u][v] = w;
    graph[v][u] = w;
}

    fclose(fp);

    char start[64], end[64];

    printf("Enter starting location: ");
    scanf("%63s", start);

    printf("Enter destination: ");
    scanf("%63s", end);

    int src = -1, dest = -1;

    for(int i = 0; i < n; i++){
        if(strcmp(name[i], start) == 0) src = i;
        if(strcmp(name[i], end) == 0) dest = i;
    }

    if(src == -1 || dest == -1){
        printf("Invalid starting location or destination!\n");
        return 1;
    }

    int dist[MAX], visited[MAX] = {0}, parent[MAX];

    for(int i = 0; i < n; i++){
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[src] = 0;

    for(int count = 0; count < n; count++){

        int u = -1, best = INF;

        for(int i = 0; i < n; i++){
            if(!visited[i] && dist[i] < best){
                best = dist[i];
                u = i;
            }
        }

        if(u == -1) break;

        visited[u] = 1;

        for(int v = 0; v < n; v++){
            if(!visited[v] && graph[u][v] != INF &&
               dist[u] + graph[u][v] < dist[v]){

                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    if(dist[dest] == INF){
        printf("No route found!\n");
        return 0;
    }

    int path[MAX], count = 0;

    for(int i = dest; i != -1; i = parent[i])
        path[count++] = i;

    printf("\nShortest Route:\n");

    for(int i = count - 1; i >= 0; i--){
        printf("%s", name[path[i]]);
        if(i > 0) printf(" -> ");
    }

    printf("\nEstimated total steps: %d\n", dist[dest]);

    return 0;
}