#include <iostream>
#include <vector>


using namespace std;

void permutation(vector<int> &T, int n, int r){
    if(r == n){
        std::cout << "Achou permutacao correta\n";
        }
    else{
        for(int j = 0; j<n; j++){
            bool valid = 1;
            for(int i = 0; i<r; i++){
                if(T[i] == j || T[i] == j + r + i || T[i] == j - r + i){
                    valid = 0;
                    break;
                }
            }
            if(valid){
                T[r] = j;
                permutation(T, n, r+1);
            }
        }
    }
}


void nQueens(int n){
    vector<int> vec(n, -1);
    permutation(vec, n, 0);
}

int main(){
    nQueens(8);
    return 0;
}