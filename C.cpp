#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n, q;
    cin >> n >> q;
    vector<long long int> warriors(n, 0);
    long long int aux;
    cin >> aux;
    warriors[0]=aux;
    long long int sum=aux;
    for(int i=1; i<n; i++){
        cin >> aux;
        warriors[i]=warriors[i-1]+aux;
        sum+=aux;
    }
    long long int attack;
    long long int rem;
    vector<long long int>::iterator lastIt;
    cin >> attack;
    if(attack>=sum){
        cout << n << "\n";
        lastIt=warriors.begin();
        rem=0;
    }
    else{
        vector<long long int>::iterator it;
        it=lower_bound(warriors.begin(), warriors.end(), attack);
        if(*it==attack){
            cout << n-((it-warriors.begin())+1) << "\n";
            lastIt=it+1;
            rem=0;
        }
        else{
            cout << n-(it-warriors.begin()) << "\n";
            rem=*it-attack;
            lastIt=it;
        }
    }


    for(int i=1; i<q; i++){
        cin >> attack;
        if(rem!=0){
            if(attack<rem){
                cout << n-(lastIt-warriors.begin()) << "\n";
                rem-=attack;
            }
            else{
                attack-=rem;
                if(lastIt+1==warriors.end()){
                    cout << n << "\n";
                    lastIt=warriors.begin();
                    rem=0;
                }
                else{
                    if(attack==0){
                        rem=0;
                        cout << n-(lastIt-warriors.begin()+1) << "\n";
                        lastIt++;
                    }
                    else{
                        if(attack<sum-*lastIt){
                            vector<long long int>::iterator it=lower_bound(lastIt+1, warriors.end(), attack+*lastIt);
                            if(*it==attack+*lastIt){
                                cout << n-(it-warriors.begin()+1) << "\n";
                                lastIt=it+1;
                                rem=0;
                            }
                            else{
                                cout << n-(it-warriors.begin()) << "\n";
                                rem=*it-(attack+*lastIt);
                                lastIt=it;
                            }
                        }
                        else{
                            cout << n << "\n";
                            lastIt=warriors.begin();
                            rem=0;
                        }
                    }
                }
            }
        }
        else{
            int ind=lastIt-warriors.begin();
            if(ind==0){
                if(attack>=sum){
                    cout << n << "\n";
                    lastIt=warriors.begin();
                    rem=0;
                }
                else{
                    vector<long long int>::iterator it;
                    it=lower_bound(warriors.begin(), warriors.end(), attack);
                    if(*it==attack){
                        cout << n-((it-warriors.begin())+1) << "\n";
                        lastIt=it+1;
                        rem=0;
                    }
                    else{
                        cout << n-(it-warriors.begin()) << "\n";
                        rem=*it-attack;
                        lastIt=it;
                    }
                }
            }
            else{
                if(attack>=sum-warriors[ind-1]){
                    cout << n << "\n";
                    lastIt=warriors.begin();
                    rem=0;
                }
                else{
                    vector<long long int>::iterator it;
                    it=lower_bound(lastIt, warriors.end(), attack+warriors[ind-1]);
                    if(*it==attack+warriors[ind-1]){
                        cout << n-((it-warriors.begin())+1) << "\n";
                        lastIt=it+1;
                        rem=0;
                    }
                    else{
                        cout << n-(it-warriors.begin()) << "\n";
                        rem=*it-(attack+warriors[ind-1]);
                        lastIt=it;
                    }
                }
            }
        }
    }

    return 0;
}
