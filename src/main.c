#include <stdio.h>
#include "config.h"
#include "show.h"

int main(int argc, char *argv[])
{
#ifdef ENABLE_SHARED
 printf("ENABLE_SHARED : %s\n", ENABLE_SHARED);
#endif

#ifdef DEBUG
 printf("hello world %s():%d\n", __FUNCTION__, __LINE__);
#else
 printf("hello world\n");
#endif

 show();

 return 0;
}
