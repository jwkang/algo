#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> mem(300, -1);

long long fibo(int n) {

    if( n == 0 ) return 0;
    if( n == 1 ) return 1;
    if( n == 2 ) return 1;

    if( mem[n] == -1 ) {
        mem[n] = fibo(n-1) + fibo(n-2);
    }

    return mem[n];
}

int main() {
    int in;
    cin >> in;

    cout << fibo(in);

    return 0;
}