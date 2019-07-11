#include <stdio.h>
#define DEBUG    
#define DEBUG2 2
#define USB

int main()
{
#ifdef DEBUG     // DEBUG 매크로가 정의되어 있다면 #ifdef, #endif 사이의 코드를 컴파일
    printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
#endif

#if DEBUG2 >= 2     // condition true
    printf("DEBUG2 \n");
#endif

#if 1    // 조건이 항상 참이므로 #if, #endif 사이의 코드를 컴파일
    printf("1\n");
#endif

#if 0    // 조건이 항상 거짓이므로 #if, #endif 사이의 코드를 컴파일하지 않음
    printf("0\n");
#endif

#ifdef PS2              // PS2가 정의되어 있을 때 코드를 컴파일
    printf("PS2\n");
#elif defined USB       // PS2가 정의되어 있지 않고, USB가 정의되어 있을 때 코드를 컴파일
    printf("USB\n");
#else                   // PS2와 USB가 정의되어 있지 않을 때 코드를 컴파일
    printf("empty().\n");
#endif

#ifndef DEBUG     // DEBUG가 정의되어 있지 않을 때 코드를 컴파일
    printf("main function\n");
#endif

    return 0;
}
