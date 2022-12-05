#include <iostream>
#include <unordered_set>

using namespace std;

//Nn sei pq inventei de usar unordered_set ao inves de vector, inventei moda atoa.
void subsetSum(unordered_set<int> T, int val, unordered_set<int> selected){
    if(val == 0){
        cout << "Encontrado uma soma com os valores:\n";
            for(auto i = selected.begin(); i != selected.end(); i++){
                cout << *i << " ";
            }
            cout << endl;
    }
    else if(!T.empty()){
        int item = *(T.begin());
        unordered_set<int> cpySelected = selected;
        cpySelected.insert(item);
        T.erase(T.begin());
        subsetSum(T, val - item, cpySelected);
        subsetSum(T, val, selected);
    }
}

void subsetSumCall(unordered_set<int> T, int val){
    unordered_set<int> selected;
    subsetSum(T, val, selected);
}


int main(){
    cout << "Digite o numero de elementos do conjunto\n";
    int in;
    cin >> in;
    unordered_set<int> s;
    cout << "Digite os elementos do conjunto\n";
    for(int i = 0; i < in ; i++){
        int element; cin >> element;
        s.insert(element);
    }
    cout << "Digite o valor do somatorio para verificar\n";
    int val; cin >> val;
    subsetSumCall(s, val);
    return 0;
}