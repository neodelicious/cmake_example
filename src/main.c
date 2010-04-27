#include <stdio.h>
#include "show.h"

int main(int argc, char *argv[])
{
 printf("%s():%d\n", __FUNCTION__, __LINE__);
 show();

 return 0;
}
