#include <iostream>
#include <string>
#include <vector>


using namespace std;

vector<int> compute_prefix(string P){
    int k = -1;
    vector<int> prefix(P.length());
    prefix[0] = -1;
    for(int q = 1; q<P.length(); q++){
        while(k >= 0 && P[k+1] != P[q]){
            k = prefix[k];
        }
        if(k+1 == P[q]) k++;
        if(k >= 0) prefix[q] = k;
        else prefix[q] = -1;
    }
    return prefix;
}

void kmp_matcher(string T, string P){
    int m = P.length(), q = -1;
    vector<int> prefix = compute_prefix(P);
    for(int i = 0; i<T.length(); i++){
        while(q >= 0 && P[q+1] != T[i]){
            q = prefix[q];
        }
        if(P[q + 1] == T[i]) q++;
        if (q == m-1){
            cout << "Padrao ocorre com deslocamento de " << i - (m - 1)+ 1 << " caracteres do inicio do texto\n";
            q = prefix[m-1];
        }
    }

}

int main(){
        string a, p;
        cin >> a;
        cin >> p;
        kmp_matcher(a, p);
        return 0;
}