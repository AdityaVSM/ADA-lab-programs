#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

void swap(int a[], int x, int y){
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

void selectionSort(int a[], int n){
    for(int i=0; i<n-1; i++){
        int min_index = i;
        for(int j=i+1; j<n; j++){
            this_thread::sleep_for(std::chrono::microseconds(100));
            if(a[j] < a[min_index])
                min_index = j;
        }
        swap(a, i, min_index);
    }
}

void display(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] <<" ";
    }
    cout<<endl;
}

int main(){
    int t = 5000;   
    while(t<=1200000){
        int a[t];
        cout<<"For "<<t<<" array size: ";
        for(int j=0;j<t;j++){
            int no = rand() % 1000 + 1;
            a[j] = no;
        }
        time_t start, end;
        time(&start);
        cout<<"unsorted: ";
        display(a,t);
        selectionSort(a,t);
        cout<<"Sorted: ";
        display(a,t);
        time(&end);
        double time_taken = double(end - start);
        cout << "Time taken by program is : "<< time_taken << setprecision(5);
        cout << " sec " << endl;
        t+=5000000;
    }    
       
    return 0;
}