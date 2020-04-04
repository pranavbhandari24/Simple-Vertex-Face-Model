// Bhandari, Pranav
// pjb1132
// 2020-04-04
//----------------------------------------------------------
#include <stdio.h>

#include "face.h"

//----------------------------------------------------------
void dumpFace( Face *face )
{
  /*
    The printf here that dumps the given face's
    three vertex numbers. These are integers.
  */
  printf("%5d, %5d, %5d", face->v1, face->v2, face->v3);
}

//----------------------------------------------------------

