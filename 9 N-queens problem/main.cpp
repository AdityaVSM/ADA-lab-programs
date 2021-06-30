#include <bits/stdc++.h>
using namespace std;
  
#define N 12

void printSolution(int board[N][N]){ 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) 
            printf(" %d ", board[i][j]); 
        printf("\n"); 
    } 
} 
  
bool isSafe(int board[N][N], int row, int col){ 
    int i, j; 
  
    /* Check this row on left side */
    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
  
    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) 
            return false; 
  
    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < N; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
} 

bool solveNQUtil(int board[N][N], int col){ 
    if (col >= N) 
        return true; 
  
    for (int i = 0; i < N; i++) { 
        this_thread::sleep_for(std::chrono::milliseconds(1));
        if (isSafe(board, i, col)) { 
            /* Place this queen in board[i][col] */
            board[i][col] = 1; 
  
            /* recur to place rest of the queens */
            if (solveNQUtil(board, col + 1)) 
                return true; 
  
            /* If placing queen in board[i][col] 
               doesn't lead to a solution, then 
               remove queen from board[i][col] */
            board[i][col] = 0; // BACKTRACK 
        } 
    } 
  
    /* If the queen cannot be placed in any row in 
        this colum col  then return false */
    return false; 
} 
bool solveNQ(){ 
    int board[N][N] = { { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 } }; 
  
    if (solveNQUtil(board, 0) == false) { 
        printf("Solution does not exist"); 
        return false; 
    } 
  
    // printSolution(board); 
    return true; 
} 
  
int main(){ 
    time_t start,end;
    cout<<"For "<<N<<" X "<<N<<" board: "<<endl;
    time(&start);
    solveNQ(); 
    time(&end);
    double time_taken = (double)(end - start);
    cout << "Time taken = "<<time_taken<<" s "<<endl; 
    return 0; 
} 