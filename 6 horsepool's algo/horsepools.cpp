#include <bits/stdc++.h>
using namespace std;

int match(string text, string pattern){
    int i, k, p_size = pattern.length();
    int table[126];
    for(i = 0; i < 126; i++)
        table[i] = p_size;
    for(int j = 0; j <= p_size - 2; j++)
        table[pattern[j]] = p_size - 1 - j;

    i = p_size - 1;
    while(i <= text.length()-1){
        this_thread::sleep_for(std::chrono::milliseconds(3));
        k = 0;
        while(k <= p_size-1 && pattern[p_size-1-k] == text[i-k]){
            this_thread::sleep_for(std::chrono::milliseconds(3));
            k++;
        }

        if(k == p_size)
            return (i - p_size + 1);
        else
            i = i + table[text[i]];
    }
    return -1;
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
    
    int range = 10000;
    while(range < 100000){
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
        int result = match(text, pattern);
        if(result >= 0)
            cout << "\n Patter found at index " << result<<endl;
        else
            cout << "\n Patter Not found"<<endl;
        time(&end);
        double time_taken = (double)(end -start);
        cout<<"time taken: "<<time_taken<<" s"<<endl<<"\n\n";
        range += 100000000;
    }
    return 0;
}