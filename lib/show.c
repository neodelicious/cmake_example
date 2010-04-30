#include <stdio.h>
#include "config.h"

void show()
{
#ifdef DEBUG
 printf("show!!! %s():%d\n", __FUNCTION__, __LINE__);
#else
 printf("show!!!\n");
#endif
}
