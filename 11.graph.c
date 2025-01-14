#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 20

void createGraph(int list[MAX][MAX])
{
    int u, v;
    printf("Enter the edges(form, to) -1 -1 to exit: \n");
    while(1)
        {
        scanf("%d %d", &u, &v);
        if (u == -1 && v == -1)
        {
            break;
        }
        list[u][v] = 1;
    }
}

void display(int list[MAX][MAX], int n){
    printf("Adujacency Maxtrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", list[i][j]);
        }
        printf("\n");
    }   
}

void bfs(int list[MAX][MAX], int n, int start){
    bool visited[MAX] = {false};
    int queue[MAX], front=0, rear=-1;
    queue[++rear] = start;
    visited[start] = true;
    while (front <= rear)
    {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 0; i < n; i++)
        {
            if(list[node][i]==1 && !visited[i]){
                queue[++rear] = i;
                visited[i] = true;
            }
        }
        
    }
    
}

int main(){
    int list[MAX][MAX],n,start;
    printf("Enter the No. of vertices: ");
    scanf("%d",&n);
    createGraph(list);
    display(list,n);
    printf("BFS: ");
    start =0;
    bfs(list,n,start);
    return 0;
}