#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "person.h"
using namespace std;

int main(void)
{
	Person Jung("Jung", 24, 120, 240, 220);
	Jung.PrintStat();
	Jung.Upbench(20);
	Jung.Updead(34);
	Jung.Upsuqrt(5);
	Jung.PrintStat();

	return 0;
}
