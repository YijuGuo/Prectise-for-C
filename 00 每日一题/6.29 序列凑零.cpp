/*
因为 n 为偶数， 可以两两分成一组。
假设一组的数是 x, y。 
则让对应的 -y,x 与这一组的对应位置乘积之和一定为 0 ，
即： -y * x + y * y 一定为 0.
所以根据 a 分组，就能构造出 b 。 b[i] = -a[i +1], b[i +1] = a[i].
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int a[N];

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        cin >> n;
        for (int i = 0; i < n; i ++ ) cin >> a[i];
        for (int i = 0; i < n; i += 2)
            cout << -a[i + 1] << ' ' << a[i] << ' ';
        cout << endl;
    }
    return 0;
}

