#include<stdio.h>
#include<stdlib.h>

int visited[] = {0,0,0,0,0,0,0};
 
int A[7][7] = {
    {0,1,1,1,0,0,0},
    {1,0,1,0,0,0,0},
    {1,1,0,1,1,0,0},
    {1,0,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0}, 
    {0,0,0,0,1,0,0} 
};

void DFS(int i){
    printf("%d",i);
    visited[i]=1;
    for (int j = 0; j < 7; j++)
    {
        if (A[i][j]==1 && !visited[j])
        {
            DFS(j);
        }
    }
}

int main(){
    /*1. strart putting any pne of the graph vertics
    2.take the op most element and added the visited list
    3 .creating a list of that vertexs adjacent node add the the ones 
    4.which are not visited in the list
    //keep repeating the steps 2 and 3*/
    DFS(0);
    return 0;
}