// Bhandari, Pranav
// pjb1132
// 2020-04-04
//----------------------------------------------------------
#include <stdio.h>

#include "vertex.h"

//----------------------------------------------------------
void dumpVertex( Vertex *vertex )
{
  /* 
    The printf here that dumps the given vertex's
    X, Y, and Z coordinates. It shows 6 decimal places.
  */
  printf("%13.6f, %13.6f, %13.6f", vertex->x, vertex->y, vertex->z);
}

//----------------------------------------------------------
