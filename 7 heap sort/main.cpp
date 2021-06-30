#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){
	int largest = i; 
	int l = 2*i + 1; 
	int r = 2*i + 2; 

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n){
	for (int i = n/2 - 1; i >= 0; i--){
		heapify(arr, n, i);
    }
	for (int i = n - 1; i >= 0; i--) {
        this_thread::sleep_for(std::chrono::milliseconds(1));
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int n){
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main(){
    int range = 1000;
    while(range < 10000){
        int n = range; //size of array
        int arr[n];
        for(int i=0; i<n; i++){
            arr[i] = rand()%1000;
        }
        // cout<<"Before sorting"<<endl;
        // printArray(arr,n);
        
        cout<<"For "<<n<<" array size"<<endl;
        time_t start, end;
        time(&start);
        heapSort(arr, n);
        time(&end);

        // cout << "\nSorted array is \n";
        // printArray(arr, n);
        double time_taken = (double)(end - start);
        cout<<"time taken is "<<time_taken<<endl<<endl;
        range += 1000;
    }
}
