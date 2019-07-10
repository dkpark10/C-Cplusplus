/*
현재시간으로 된 폴더 생성 시간까지
ex)20190625_105548
폴더 있는지 없는지 검사
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>

void TimetoString(time_t time, char *str)
{
    struct tm* tmptr;   // tm 포인터
    tmptr = localtime(&time); // 유닉스시간이 저장된 변수의 주소를 넘겨 년원일로 변형

    sprintf(str, "%d%02d%02d-%02d%02d%02d", // 문자열로 변환 02d% 이렇게 넣어줘야 한자리수 시간도 자릿수에 맞춰 출력
            tmptr->tm_year + 1900, tmptr->tm_mon + 1, tmptr->tm_mday,
            tmptr->tm_hour, tmptr->tm_min, tmptr->tm_sec);
}

int main(void)
{
    struct timeval curtime;
    gettimeofday(&curtime, NULL);
    printf("%ld: %ld\n", curtime.tv_sec, curtime.tv_usec);

    ////
    
    time_t timer; // 시간
    char strtime[256]; // 현재시간을 문자열로 받는 배열

    timer = time(NULL); // 현재 시각을 초 단위로 얻기 유닉스 시간으로 표시됨

    TimetoString(timer,strtime); // 유닉스 시간은 년 월 일 시간으로 변형하고 문자열을 넣어주는 함수
    printf("%s",strtime);

    if (mkdir(strtime, 0776) < 0 && errno != EEXIST){ // 디렉토리 만들기 0776은 권한
        perror("Create Folder Fail\n");
        return -1;
    }

    return 0;
}
