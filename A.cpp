#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    set<long long int> words;
    long long int uno=1;
    for(int i=0; i<n; i++){
        long long int aux=0;
        string word;
        cin >> word;
        int x;
        for(int i=0; i<word.size(); i++){
            x=word[i]-'a';
            aux=aux | (uno<<x);
        }
        words.insert(aux);
    }
    cout << words.size() << "\n";


    return 0;
}
