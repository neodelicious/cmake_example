#include <stdio.h>
#include "config.h"
#include "show.h"

int main(int argc, char *argv[])
{
#ifdef ARG
 printf("ARG : %d\n", ARG);
#endif

 printf("%s():%d\n", __FUNCTION__, __LINE__);
 show();

 return 0;
}
