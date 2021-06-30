#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

int isSubstring(string &s1, string &s2){
    int M = s1.length();
    int N = s2.length();
 
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++){
            this_thread::sleep_for(std::chrono::milliseconds(1));
            if (s2[i + j] != s1[j])
                break;
        }
 
        if (j == M) {
            //cout << "Pattern found at index " << i << endl;
            return i;
        }
    }
    return -1;
    //cout<< "Pattern not found"<<endl;
}
 
int main(){
    vector<char> alphanum ={
        '0','1','2','3','4',
        '5','6','7','8','9',
        'A','B','C','D','E','F',
        'G','H','I','J','K',
        'L','M','N','O','P',
        'Q','R','S','T','U',
        'V','W','X','Y','Z',
        'a','b','c','d','e','f',
        'g','h','i','j','k',
        'l','m','n','o','p',
        'q','r','s','t','u',
        'v','w','x','y','z'
    };
    
    int range = 1000;
    while(range < 1000000){
        string text = "";
        string pattern = "";
        int len = range;
        for(int i=0; i<len;i ++){
            int t = alphanum.size()-1;
            int idx = rand()%t;
            text += alphanum[idx];
        }
        cout << "Length of main string = "<<len<<endl;
        cout<<text<<endl;
        int len2 = 100;
        int end2 = range-1;
        int strt = (end2-99);
        
        for(int i=strt; i<=end2; i++){
            pattern += text[i];
        }
        cout<<pattern<<endl;
        time_t start, end;
        time(&start);
        int result = isSubstring(pattern, text);
        if(result >= 0)
            cout << "\n Patter found at index " << result<<endl;
        else
            cout << "\n Patter Not found"<<endl;
        time(&end);
        double time_taken = (double)(end -start);
        cout<<"time taken: "<<time_taken<<" s"<<endl<<"\n\n";
        range += 10000000;
    }
    return 0;  
}
