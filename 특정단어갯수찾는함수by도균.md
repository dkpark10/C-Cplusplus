# 특정단어 갯수 찾는 함수

냉무

```c++
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

int f(char* s1, char* s2)                           // s1 = 문장 s2 = 찾을 단어
{
    int cnt = 0, size = strlen(s2), temp;
    bool chk;
    
    for(int i=0; i< strlen(s1); i++){               // 문장 전체를 훑는다.
        chk = true;
        if(s1[i] == s2[size - 1]){                  // 찾을 단어 끝문장이 같으면
            temp = i;                               // 인덱스 거꾸로 가야하기 때문에 temp 변수 필요 
            
            for(int j= size - 1; j >= 0; j--){      // 단어 갯수만큼 거꾸로 반복해서 
                
                if(s2[j] != s1[temp--]){            // 단 하나라도 틀리면
                    chk = false;                    // 체크 false
                    break;
                }
            }
            if(chk) cnt ++;                         // 단어가 같다면 저 위 이프문을 안들어갔을 테니 cnt++
        }
    }
    return cnt;
}

int main(void)
{
    char str1[] = "pencil               pencil       pencil";
    char str2[] = "pencil";
    printf("%d\n",f(str1,str2));

    return 0;
}
```
