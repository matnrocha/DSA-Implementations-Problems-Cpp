#include <bits/stdc++.h>
using namespace std;

// não é necessário, pois c++ já tem a função gcd(a,b) built-in
//retorna 0 se os 2 forem 0, senão retorna o gcd dos dois numeros

int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}