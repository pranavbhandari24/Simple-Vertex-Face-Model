// Dalio, Brian A.
// dalioba
// 2020-04-02

#if !defined( __MODEL_H__ )
#define __MODEL_H__

//----------------------------------------------------------
#include "vertex.h"
#include "face.h"

//----------------------------------------------------------
typedef struct _Model {
  int     m_numVertices;
  int     m_numFaces;
  Vertex *m_vertex;
  Face   *m_face;
} Model;

//----------------------------------------------------------
Model *allocModel( int numVertices, int numFaces );
void   dumpModel( Model *model );
void   freeModel( Model *m );
Model *loadModel( char *fName );

//----------------------------------------------------------
#endif

