#include<bits/stdc++.h>
using namespace std;

void bfs(int s, vector<int> adj[], bool visited[], int n){
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        // cout << curr <<" ";
        for(int i=0 ;i<adj[curr].size(); i++){
            if(visited[adj[curr][i]] == false){
	            this_thread::sleep_for(std::chrono::milliseconds(10));
                q.push(adj[curr][i]);
                visited[adj[curr][i]] = true;
            }
        }
    }
}

bool eleExists(int in, int ele, vector<int> adj[]){
    for(int i=0; i<adj[in].size(); i++){
        if(adj[in][i] == ele)
            return true;
    }
    return false;
}

bool pairExists(int from, int to, vector<int>adj[]){
	for(int i=0; i<adj[from].size(); i++){
        if(adj[from][i] == to){
            return true;
        }
	}
	return false;
}


int main(){
    int range = 100;
    while(range < 1000){
        int noOfVertices,noOfEdges;
        noOfVertices = range;
        noOfEdges = range + 2;
        cout<<"for "<<noOfVertices <<" vertices "<<endl;
        vector<int> adj[noOfVertices];
        bool visited[noOfVertices] = {false};

        for(int i=0; i<noOfEdges; i++){ //taking from and to for all edges
            int from,to;
            from = rand() % noOfVertices;
			to = rand() % noOfVertices;
			while(to == from || pairExists(from,to,adj) || pairExists(to,from,adj)){
                from = rand() % noOfVertices;
				to = rand() % noOfVertices;
			}
            adj[from].push_back(to);
        }
        for(int i=0; i<noOfVertices; i++){  //cleaning list adjacency matrix
            for(int j=0; j<adj[i].size(); j++){
                if(!eleExists(adj[i][j],i,adj))
                    adj[adj[i][j]].push_back(i);
            }
        }
        // for(int i=0; i<noOfVertices; i++){  //printing list adjacency matrix
        //     cout<<i<<" ----> ";
        //     for(int j=0; j<adj[i].size(); j++){
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        time_t start,end;
		time(&start);
        bfs(0,adj, visited, noOfVertices);
        time(&end);
        double time_taken = (double)(end -start);
        cout << "Time taken by program for " << noOfVertices << " number of vertices is : " << time_taken<<" s"<<endl;
        range += 100;
    }    
    return 0;
}