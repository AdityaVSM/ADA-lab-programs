#include<bits/stdc++.h>
using namespace std;

struct node {
	int parent;
	int rank;
};
struct Edge {
	int src;
	int dst;
	int wt;
};

vector<node> dsuf;
vector<Edge> mst;

int find(int v){
	if(dsuf[v].parent == -1)
		return v;
	return dsuf[v].parent = find(dsuf[v].parent);	
}

void union_op(int fromP,int toP){
	if(dsuf[fromP].rank > dsuf[toP].rank)	
		dsuf[toP].parent = fromP;
	else if(dsuf[fromP].rank < dsuf[toP].rank)	
		dsuf[fromP].parent = toP;
	else{
		dsuf[fromP].parent = toP;
		dsuf[toP].rank +=1;		
	}
}

bool comparator(Edge a,Edge b){
	return a.wt < b.wt;
}

void Kruskals(vector<Edge>& edge_List,int V,int E){
	sort(edge_List.begin(), edge_List.end(), comparator);

	int i = 0, j = 0;
	while(i<V-1 && j<E){
	    this_thread::sleep_for(std::chrono::milliseconds(1));

		int fromP = find(edge_List[j].src);	
		int toP = find(edge_List[j].dst);
		
		if(fromP == toP){	
            j++;	
            continue;	
        }
		union_op(fromP,toP);
		mst.push_back(edge_List[j]);
		i++;
	}
}

void display(vector<Edge>& mst){
    int sum = 0;
	// cout<<"MST formed is\n";
	for(auto p: mst)
    {
        // cout<<"src: "<<p.src<<"  dst: "<<p.dst<<"  wt: "<<p.wt<<"\n";
        sum = sum + p.wt;
    }
    cout << "Total weight of the MST = " << sum <<endl;
}


bool pairExists(int from, int to, vector<Edge> edge_list){
	for(int i=0; i<edge_list.size(); i++){
		if(edge_list[i].src == from && edge_list[i].dst == to || edge_list[i].src == to && edge_list[i].dst == from){
			return true;
		}
	}
	return false;
}

int main()
{
	int size = 200;
	while(size < 10000){
		vector<Edge> edge_List;
		Edge temp;
		int E = size+1;	
		int V = size;	

		dsuf.resize(V);	
		for(int i = 0; i < V; i++){	
			dsuf[i].parent = -1;
			dsuf[i].rank = 0;
		}

		for(int i=0; i < E; i++){
			int from,to,wt;
			from = rand() % V;
			to = from;
			while(to == from || pairExists(from,to,edge_List)){
				from = rand() % V;
				to = rand() % V;
			}
			wt = rand()%10+1;
			// cout<<"from = "<<from<<endl;
			// cout<<"to = "<<to<<endl;
			// cout<<"weight = "<<wt<<endl;
			temp.src = from;
			temp.dst = to;
			temp.wt = wt;
			edge_List.push_back(temp);
		}
		time_t start,end;
		time(&start);
		Kruskals(edge_List, V ,E);
		time(&end);
		double time_taken = (double)(end -start);
        cout << "Time taken by program for " << size << " number of edges is : " << time_taken<<" s"<<endl;
		display(mst);
		size+=200;
	}	
	return 0;
}