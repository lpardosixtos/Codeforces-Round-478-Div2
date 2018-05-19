#include <bits/stdc++.h>

using namespace std;

long long int score(long long int stones[14], int n){
    if(stones[n]==0) return 0;
    long long int aux=stones[n], res=aux%14;
    stones[n]=0;
    for(int i=1; i<=res; i++){
        stones[(n+i)%14]++;
    }
    aux/=14;
    long long int sum=0, uno=1;
    for(int i=0; i<14; i++){
        stones[i]+=aux;
        if(!(stones[i]&uno)) sum+=stones[i];
    }
    return sum;

}

int main(void){

    long long int stones[14];
    for(int i=0; i<14; i++){
        cin >> stones[i];
    }
    long long int stonesaux[14];
    for(int i=0; i<14; i++){
        stonesaux[i]=stones[i];
    }
    long long int maxi=score(stonesaux, 0);
    for(int i=1; i<14; i++){
        for(int j=0; j<14; j++){
            stonesaux[j]=stones[j];
        }
        maxi=max(maxi, score(stonesaux, i));
    }
    cout << maxi << "\n";


    return 0;
}
