#include <iostream>
#include <cstdio>

using namespace std;

void print(int num){
    for (int i = 31; i >= 0; --i) { //8자리 숫자까지 나타냄
        int result = num >> i & 1;
        printf("%d", result);
    }

    cout << endl;

}

// 10 ops 
// ! ~ & ^ | +
int isTmax(int x){

    cout << x << endl;
    cout << x + 1 << endl;
    cout << ~(x+1) << endl;
    cout << (x^(~(x+1))) << endl;
    return !!(x&(~(x+1)));
}

int allEventBits(int x){
    print(x);
    print(0x55);
    cout << endl;
    print(x&0x55);
    print((x>>8)&0x55);
    print((x>>16)&0x55);
    print((x>>24)&0x55);

    print((x&0x55)&((x>>8)&0x55)&((x>>16)&0x55)&((x>>32)&0x55)^0x55);

    return !((x&0x55)&((x>>8)&0x55)&((x>>16)&0x55)&((x>>32)&0x55)^0x55);
}

int rotateLeft(int x, int n){
    print(x);
    print(x<<n); // 상위 n비트
    print(n);
    print(~n);
    cout << ~n+1 << endl;
    cout << 31+(~n+1) << endl;
    print(x >> (32+(~n+1))); // 상위 n비트를 구하기 위해 32-n  비트 >> 
    print((1<<n)-1); // 하위 1111
    print(~((~0)<<n)); // 하위 1111
    print((x >> (32+(~n+1)))&((1<<n)-1)); // 하위 n비트
    int a = x<<n;
    int b = (x >>(32+(~n+1)))&(~((~0)<<n));
    
    cout << a << " " << b <<endl;
    cout << (a|b) << endl;
    print((a|b));

    printf("%#x\n", a|b);

    return (x<<n)|(x >> (32+(~n+1)))&(~((~0)<<n));
}

int main(){
    int a = 0x7fffffff;
    a = 1;
    // cout << isTmax(a);

    // cout << allEventBits(0xfffffffe) << endl; 
    // cout << allEventBits(0x55555555) << endl;

    cout << rotateLeft(0x87654321, 4) << endl;
    return 0;
}