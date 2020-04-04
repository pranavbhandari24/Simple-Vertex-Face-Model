// Bhandari, Pranav
// pjb1132
// 2020-04-04
//----------------------------------------------------------
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "model.h"

//----------------------------------------------------------
Model *allocModel( int numVertices, int numFaces )
{
  /*  
      Allocate a Model structure.
      Initialize its fields using the given number of
      vertices and faces.
      Return a pointer to the Model structure as the
      result of this function. 
  */
  Model *result;
  result->m_numVertices = numVertices;
  result->m_numFaces    = numFaces;
  result->m_vertex      = (Vertex*) calloc(numVertices*sizeof(Vertex));
  result->m_face        = (Face*)   calloc(numFaces   *sizeof(Vertex));
  return result;
}

//----------------------------------------------------------
void dumpModel( Model *model )
{
  printf( "#- Model parameters --------------------\n" );
  printf( "Vertex count : %5d\n", model->m_numVertices );
  printf( "Face count   : %5d\n", model->m_numFaces );

  printf( "\n#- Vertex list -------------------------\n" );
  for ( int i=0; i<model->m_numVertices; i++ ) {
    printf( "  [%5d]  ", i );
    dumpVertex( &model->m_vertex[i] );
    putc( '\n', stdout );
  }

  printf( "\n#- Face list ---------------------------\n" );
  for ( int i=0; i<model->m_numFaces; i++ ) {
    printf( "  [%5d]  ", i );
    dumpFace( &model->m_face[i] );
    putc( '\n', stdout );
  }

  printf( "#---------------------------------------\n" );
}

//----------------------------------------------------------
void freeModel( Model *model )
{
  // TODO: Free the vertex and face data of the given model.
  //       Free the model structure itself.
}

//----------------------------------------------------------
Model *loadModel( char *fName )
{
  // TODO: Open the file indicated by fName.
  //       Determine how many vertex lines and how many face
  //         lines it includes.
  //       Allocate a Model structure using the vertex and face
  //         counts as arguments.
  //       Read each vertex line from the file and save its X, Y,
  //         Z coordinates.
  //       Read each face line from the file and save its three
  //         vertex numbers.  Don't forget to subtract one from
  //         each number so it can be used as an index into the
  //         vertex list.
  //       Return a pointer to the allocated model structure as
  //         the value of this function.
}

//----------------------------------------------------------

