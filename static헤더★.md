# static 헤더

## static을 헤더에 쓴다면

static은 헤더에 쓰면 그 헤더파일을 포함하는 cpp파일에서 각 독립적으로 </br>
메모리 할당 각 여러파일에 접근충돌을 막는다!!! 

```c++
// test.h

#ifndef __test_h__
#define __test_h__

#include<iostream>
static int s = 13;

#endif __test_h__
```

```c++
// main1.cpp

#include "test.h"
#include <iostream>

printf("%d\n, s);     // 13 출력
```

위 c++파일이 여러개이고 공통으로 test.h를 포함한다면 </br>
static 변수 s는 각 독립적으로 공간할당 여러 c++파일에서 13을 출력 </br>
헤더파일은 말그대로 치환한다고 생각하자 그러면 파일에 static int s 가 선언되고 </br>
이는 각 파일에서만 쓸 수 있는 전역변수가 아닌 static이 된다. 그러므로 독립적으로 메모리 공간 할당되고 </br>
접근 충돌을 막을 수 있는것

## 전역변수

외부파일 전역변수는 
extern 선언 외부에서 사용한다고 선언해주자 
