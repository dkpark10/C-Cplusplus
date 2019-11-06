#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "person.h"                                                   # 헤더 선언 !!!
using namespace std;

Person::Person(char* name, int age, int bench, int dead, int squart)
{
	strcpy(this->name, name);
	this->age = age;
	this->benchpress = bench;
	this->deadlift = dead;
	this->squart = squart;
}

void Person::PrintStat()
{
	printf("name = %s\n", this->name);
	printf("age = %d\n", this->age);
	printf("bench = %d\n", this->benchpress);
	printf("dead = %d\n", this->deadlift);
	printf("squart = %d\n", this->squart);
}

void Person::Upbench(int b)
{
	this->benchpress += b; 
}

void Person::Updead(int d)
{
	this->deadlift += d;
}

void Person::Upsuqrt(int s)
{
	this->squart += s;
}
