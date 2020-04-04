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
  Model *result = (Model*)calloc(1, sizeof(Model));
  result->m_numVertices = numVertices;
  result->m_numFaces    = numFaces;
  result->m_vertex      = (Vertex*) calloc(numVertices, sizeof(Vertex));
  result->m_face        = (Face*)   calloc(numFaces   , sizeof(Vertex));
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
  /*
    Free the vertex and face data of the given model.
    Free the model structure itself.
  */
  free(model->m_vertex);
  free(model->m_face);
  free(model);
}

//----------------------------------------------------------
Model *loadModel( char *fName )
{
  /*
    Open the file indicated by fName.
    Determine how many vertex lines and how many face lines it includes.
    Allocate a Model structure using the vertex and face counts as arguments.
    Read each vertex line from the file and save its X, Y, Z coordinates.
    Read each face line from the file and save its three vertex numbers.  
    Don't forget to subtract one from each number so it can be used as an index 
    into the vertex list.
    Return a pointer to the allocated model structure as the value of this function.
  */
  FILE *file = fopen(fName, "r");
  char *line = NULL;
  size_t size = 1000;
  int v = 0, f = 0;
  if(file == NULL) {
    printf("Unable to Open file. Please try again.\n");
    exit(1);
  }
  // Counting the number of vertices and faces.
  while(getline(&line, &size, file) >=0) {
    if(isspace(line[0]) || line[0] == '#')
      continue;
    else if(line[0] == 'v'){
      v++;
    }
    else if(line[0] == 'f'){
      f++;
    }
  }
  // Allocating the Model
  Model *m;
  m = allocModel(v,f);
  rewind(file);
  // Reading the values of each vertice and face
  v = 0; f = 0;
  while(getline(&line, &size, file) >=0) {
    if(isspace(line[0]) || line[0] == '#')
      continue;
    else if(line[0] == 'v'){
      char* pend;
      Vertex v_temp;
      v_temp.x = (double)strtof(line+2, &pend);
      v_temp.y = (double)strtof(pend  , &pend);
      v_temp.z = (double)strtof(pend  , NULL);
      m->m_vertex[v] = v_temp;
      v++;
    }
    else if(line[0] == 'f'){
      char* pend;
      Face f_temp;
      f_temp.v1  = (int)strtof(line+2, &pend) - 1;
      f_temp.v2  = (int)strtof(pend  , &pend) - 1;
      f_temp.v3  = (int)strtof(pend  , NULL)  - 1;
      m->m_face[f] = f_temp;
      f++;
    }
  }
  fclose(file);
  return m;
}

//----------------------------------------------------------

