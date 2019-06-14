/* 
파이썬에서 최대 최소를 찾으려면 리스트변수.max()하면 끝 간단하다.
c도 파이썬처럼 최대 최소값 함수가 구현되 있다.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef struct Point{
    int x; 
    int y;
}Point;

bool Maxcmp(const Point &p1, const Point &p2)
{
    if (p1.y < p2.y) return true;
    else return false;
}

bool Mincmp(const Point &p1, const Point &p2)
{
    if (p1.y < p2.y) return true;
    else return false;
}

int main(void)
{
    int arr[10] = {12, 4, 3456, 37, 8, 45, 73, 5, 364, 2};
    printf("Max is %d\n",*max_element(arr,arr + 10)); // max_element 함수는 최대값의 주소를 반환 시작주소와 끝주소를 인자로 넘김
    printf("Min is %d\n",*min_element(arr,arr + 10)); // min_element 함수는 최소값의 주소를 반환 

    Point p[10]; // 포인터 구조체 10개 생성 
    for(int i=0; i<10; i++){
        p[i].x = i + 1 * 4;   // 4 5 6 7 8 9 ...
        p[i].y = i + 1 * 7;   // 7 8 9 10 11 ...
    }

    Point *ptr;                                // 주소를 반환하기 때문에 구조체를 가리키는 포인터 생성
    ptr = max_element(p, p + 10, Maxcmp);      // 포인트 구조체의 y값의 최대를 구하기위한 함수를 구현하고 세번째 인자로 넘겨준다 
    printf("Max value of Y is %d\n", ptr->y);  // 16
    ptr = min_element(p, p + 10, Mincmp);      // 포인트 구조체의 y값의 최소를 구하기위한 함수를 구현하고 세번째 인자로 넘겨준다 
    printf("Min value of Y is %d\n", ptr->y);  // 7

    return 0;
}
