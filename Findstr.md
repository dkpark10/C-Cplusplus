```c++
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

int f(char* s1, char* s2)
{
    int cnt = 0, size = strlen(s2), temp;
    bool chk;
    
    for(int i=0; i< strlen(s1); i++){
        chk = true;
        if(s1[i] == s2[size - 1]){
            temp = i; 
            
            for(int j= size - 1; j >= 0; j--){
                
                if(s2[j] != s1[temp--]){
                    chk = false;
                    break;
                }
            }
            if(chk) cnt ++; 
        }
    }
    return cnt;
}

int main(void)
{
    char str1[] = "pencil               pencil       pencil";
    char str2[] = "pencil";
    printf("%d\n",f(str1,str2));

    int x = 10,y;
    y = 0 && ++x;
    printf("%d %d\n",x,y);

    return 0;
}

```
