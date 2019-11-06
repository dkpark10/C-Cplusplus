#pragma once
#ifndef __PERSON_H__							// 헤더파일 중복문제 매크로
#define __PERSON_H__
#include <string>

class Person {

private:

	char name[20];
	int age;
	int benchpress;
	int deadlift;
	int squart;

public:

	Person(char*, int, int, int, int);
	void PrintStat();
	void Upbench(int);
	void Updead(int);
	void Upsuqrt(int);
};

#endif
