#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

int partition(int *a,int start,int end){
    int pivot=a[start], p1=start+1, i, temp;
    for(i=start+1;i<=end;i++){
        this_thread::sleep_for(std::chrono::microseconds(100));
        if(a[i]<pivot){
            if(i!=p1){
                temp=a[p1];
                a[p1]=a[i];
                a[i]=temp;
            } 
            p1++;
        }
    }
    a[start]=a[p1-1];
    a[p1-1]=pivot;

    return p1-1;
}

void quicksort(int *a,int start,int end){
    int p1;
    if(start<end){
        p1=partition(a,start,end);
        sleep(0.9);
        quicksort(a,start,p1-1);
        sleep(0.9);
        quicksort(a,p1+1,end);
    }
}
void display(int a[], int n){
    for(int i=0; i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int t = 10000;
    while(t<=1200000){
        int a[t];
        for(int i=0;i<t;i++){
            int no = rand()%10 +1;
            a[i] = no;
        }
        cout << "for "<<t<<" array size"<<endl;
        time_t start,end;
        for(int i=0; i<t;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        time(&start);
        quicksort(a,0,t);
        time(&end);
        for(int i=0; i<t;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        double time = double(end-start);
        
        cout<<"time taken: "<<time<<" s"<<endl;
        t+=10000000;
    }
    

    return 0;
}