#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
 
void merge(int arr[], int l, int m, int r){
    
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    int i = 0;
    int j = 0;
 
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[],int l,int r){
    this_thread::sleep_for(std::chrono::milliseconds(1));
    if(l>=r){
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
 

void printArray(int A[], int size){
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout<<"\n\n";
}
 
int main(){
    int t = 1000;   
    while(t<=10000000){
        int a[t];
        cout<<"For "<<t<<" array size: \n";
        for(int j=0;j<t;j++){
            int no = rand() % 1000 + 1;
            a[j] = no;
        }
        time_t start, end;
        time(&start);
        cout<<"unsorted: \n";
        printArray(a,t);
        mergeSort(a,0,t-1);
        cout<<"Sorted: \n";
        printArray(a,t);
        time(&end);
        double time_taken = (double)(end -start);
        cout << "Time taken by program is : " << time_taken<<" s"<<endl;
        t+=1000;
    }
    return 0;
}