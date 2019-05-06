#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int D[2001][4];
int mem[2001][4];
int num[] = {0,1,2,3,1,2,3};

int f(int i, int j) {
    if( i == 0 ) return 0;
    if( i == 1 ) {
        return D[1][j];
    }

    if( i == 2 ) {
        return std::min(
                D[2][num[j]]+ f(1, num[j + 1]),
                D[2][num[j]]+ f(1, num[j + 2])
                );
    }

    if( mem[i][j] == -1 ) {
        mem[i][j] = std::min(
                    f(i - 1, num[j + 1]),
                    f(i - 1, num[j + 2])
                    ) + D[i][j];
    }

    return mem[i][j];
}

int main() {
    int count;
    cin >> count;

    for (int i = 1; i <= count; ++i) {
        cin >> D[i][1];
        cin >> D[i][2];
        cin >> D[i][3];
    }

    memset(mem, -1, sizeof(int)*2001*4);

    int ret = std::min(f(count, 1), f(count, 2));
    ret = std::min(ret, f(count, 3));

    cout << ret;

    return 0;
}