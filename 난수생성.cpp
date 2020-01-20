#include <cstdio>
#include <cstdlib>
#include <time.h>
using namespace std;
int main(void)
{
  srand(time(NULL));
  int rannum = rand() % 10;
  printf("%d\n,rannum);
  return 0;
}
