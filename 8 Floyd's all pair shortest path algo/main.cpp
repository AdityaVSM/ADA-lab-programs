#include <bits/stdc++.h>
using namespace std;

#define nV 14

int INF = 99999;

void printMatrix(int matrix[][nV]);

void floydWarshall(int graph[][nV]) {
    int matrix[nV][nV], i, j, k;

    for (i = 0; i < nV; i++)
        for (j = 0; j < nV; j++)
            matrix[i][j] = graph[i][j];

    for (k = 0; k < nV; k++) {
        for (i = 0; i < nV; i++) {
            for (j = 0; j < nV; j++){
                this_thread::sleep_for(std::chrono::milliseconds(1));
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
    // printMatrix(matrix);
}

void printMatrix(int matrix[][nV]) {
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
        if (matrix[i][j] == INF)
            printf("%4s", "INF");
        else
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}


int main() {
    vector<int> data = {0,1,2,3,4,5,6,7,8,9,INF};
    int graph[nV][nV];
    srand(time(0));
    for(int i=0; i<nV; i++){
        for(int j=0; j<nV; j++){
            if(i==j){
                graph[i][j] = 0;
            }else{
                int t = data.size()-1;
                int idx = rand()%t+1;
                graph[i][j] = data[idx];
            }            
        }
    }
    cout<<"For "<<nV<<" number of vertices: "<<endl;
    time_t start,end;
    time(&start);
    // printMatrix(graph);
    // cout<<endl<<endl;
    floydWarshall(graph);
    time(&end);
    double time_taken = (double)(end-start);
    cout<<"Time taken is "<<time_taken<<" s"<<endl;
}