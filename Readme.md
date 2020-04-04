
# Simple Vertex Face Model


## Purpose:

  * Demonstrate ability to load a SVFM (Simple Vertex Face Model)
    file.

  * Demonstrate ability to write some (simple) C code.


### Background:

  * SVFM files :
    - Blank lines are to be ignored.  (A blank line has no
      characters at all or is just whitespace.)

    - Lines with '#' as the first non-whitespace character are
      comments and are to be ignored.

    - Lines with 'v' as the first non-whitespace character are
      Vertex lines.  There will be three numbers following the
      'v': the X, Y, and Z coordinates of the vertex.  The 'v' and
      the coordinates will be separated by whitespace.  Example:

        v 27.34  16  8.9

    - Lines with 'f' as the first non-whitespace character are
      Face lines.  There will be three integers following the
      'f': the numbers of the three vertices making up the face.
      (Faces are triangles.)  The 'f' and the vertex numbers will
      be separated by whitespace.  Example:

        f  17   23   56

      In the SVFM file, the vertices are numbered 1 to n.  In
      the program, the vertices will be refered to as 0 to n-1.

    - If a line starts with any other non-whitespace character, it
      should be silently ignored.

