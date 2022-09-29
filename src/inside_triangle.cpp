#include <iostream>

using namespace std;

bool inside_triangle(pair<float, float> px, pair<float , float> p0, pair<float , float>p1, pair<float , float>p2){
    float x0 = px.first, y0 = px.second;
    float x1 = p0.first, y1 = p0.second;
    float x2 = p1.first, y2 = p1.second;
    float x3 = p2.first, y3 = p2.second;
    float dir1 = (x1-x0)*(y2-y0) - (x2-x0) * (y1-y0);
    float dir2 = (x1-x0)*(y3-y0) - (x3-x0) * (y1-y0);
    if(dir1 >= 0 && dir2 >= 0 || dir1 <= 0 && dir2 <= 0){cout << "Fora do triangulo\n"; return false;}
    dir1 = (x2-x0)*(y1-y0) - (x1-x0) * (y2-y0);
    dir2 = (x2-x0)*(y3-y0) - (x3-x0) * (y2-y0);
    if(dir1 >= 0 && dir2 >= 0 || dir1 <= 0 && dir2 <= 0){cout << "Fora do triangulo\n"; return false;}
    else{cout << "Dentro do triangulo\n"; return true;}
}
int main(void){
    pair<float, float> a(3, 2), b(2, 3), c(1, 1), p;
    cout << "Digite x e y do ponto\n";
    cin >> p.first >> p.second;
    inside_triangle(p, a, b, c);
    return 0;
}