/*
소수 구하기 N이 아무리 큰수라도 빠르게 구해진다
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    bool check[10000 + 1]; // 여기다 MAX 
    int num;

    fill(check, check + 10000 + 1, true); // 모두 소수라 가정
    check[1] = false;

    for (int i = 2; i <= 10000; i++){ // 2부터 끝까지

        if(check[i])                  // true 라면 즉 소수이면
            num = i;

        for (int j = num * 2; j <= MAX; j += num){ // 배수를 차례대로 false 판정
            check[j] = false;                      // check 배열에 true는 소수
        }
    }

    return 0;
}
