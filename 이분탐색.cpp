// 이분탐색 그 값을 찾기까지 몇번의 연산을 하나 세는 간단한 프로그램

#include<iostream>
#include<algorithm>
using namespace std;

int BinarySearch(const int *arr, int size, const int find)
{
    int left = 0;
    int right = arr[size - 1];
    int mid;
    int cnt = 0;

    while (left <= right){
        mid = (left + right) / 2;
        if(mid > find){           // 찾고자 하는 값이 mid보다 작다면 
            right = mid;          // right를 땡김
            cnt++;
        }
        else if(mid < find){      // 찾고자 하는 값이 mid보다 크다면 
            left = mid;           // left를 땡김
            cnt++;
        }
        else {
            cnt++;
            break;
        }
    }
    return cnt;
}

int main(void)
{
    int arr[80]={0,};
    int num;
    int size = sizeof(arr) / sizeof(int);
    int count=0;

    for(int i=0; i<size; i++){
        arr[i] = i + 1;
    }
    cin >> num;

    count = BinarySearch(arr, size, num);

    return 0;
}
