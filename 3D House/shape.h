#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

#include <bits/stdc++.h>
#include <windows.h>        // For MS Windows
#include <GL/glut.h>        // GLUT, include glu.h and gl.h

using namespace std;

/* Drawing circle using LINE_LOOP */
void drawKingHead(float cx, float cy, float cz, float r, int num_segments)
{
    glBegin(GL_POLYGON);
    for (int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float z = r * sinf(theta);//calculate the y component
        glVertex3f(x + cx, cy ,z+cz);//output vertex
    }
    glEnd();
}

void drawWheel(float cx, float cy, float cz, float r, int num_segments)
{
    glBegin(GL_POLYGON);
    for (int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glVertex3f(x + cx, y + cy, cz);//output vertex
    }
    glEnd();
}


void drawCube(double tr_x, double tr_y,  double bl_x, double bl_y,  double front_z, double back_z)
{
    glEnableClientState( GL_VERTEX_ARRAY );
    glEnableClientState( GL_INDEX_ARRAY );

    GLfloat vertices[] = {tr_x,  tr_y,  front_z, // front top right corner
                          bl_x,  tr_y,  front_z, // front top left corner
                          bl_x,  bl_y,  front_z, // front bottom left corner
                          tr_x,  bl_y,  front_z, // back bottom right corner
                          tr_x,  tr_y,  back_z,  // back top right corner
                          bl_x,  tr_y,  back_z,  // back top left corner
                          bl_x,  bl_y,  back_z,  // back bottom left corner
                          tr_x,  bl_y,  back_z   // back bottom right corner
                         }; // bottom right corner

    GLubyte indices[] = {0,1,2,3, // first triangle (bottom left - top left - top right)
                         4,0,3,7,
                         4,5,6,7,
                         1,5,6,2,
                         0,4,5,1,
                         2,6,7,3
                        }; // second triangle (bottom left - top right - bottom right)

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, indices);
}


void drawCube(double tr_x, double tr_y,  double bl_x, double bl_y,  double front_z, double back_z, int i)
{
    glEnableClientState( GL_VERTEX_ARRAY );
    glEnableClientState( GL_INDEX_ARRAY );
    glEnableClientState( GL_COLOR_ARRAY);

    float vertexColors[24] = {  // An RGB color value for each vertex
           1,0,0,   1,0,0,   1,0,0,   1,0,0,   0,0,1,   0,0,1,   0,0,1,   0,0,1,};

    GLfloat vertices[] = {tr_x,  tr_y,  front_z, // front top right corner
                          bl_x,  tr_y,  front_z, // front top left corner
                          bl_x,  bl_y,  front_z, // front bottom left corner
                          tr_x,  bl_y,  front_z, // back bottom right corner
                          tr_x,  tr_y,  back_z,  // back top right corner
                          bl_x,  tr_y,  back_z,  // back top left corner
                          bl_x,  bl_y,  back_z,  // back bottom left corner
                          tr_x,  bl_y,  back_z   // back bottom right corner
                         }; // bottom right corner

    GLubyte indices[] = {0,1,2,3, // first triangle (bottom left - top left - top right)
                         4,0,3,7,
                         4,5,6,7,
                         1,5,6,2,
                         0,4,5,1,
                         2,6,7,3
                        }; // second triangle (bottom left - top right - bottom right)

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer( 3, GL_FLOAT, 0, vertexColors );
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, indices);
    glDisableClientState(GL_COLOR_ARRAY);
}


void drawCube(double tr_x, double tr_y, double tl_x, double tl_y,
              double bl_x, double bl_y, double br_x, double br_y,
              double front_z, double back_z)
{
    glEnableClientState( GL_VERTEX_ARRAY );
    glEnableClientState( GL_INDEX_ARRAY );

    GLfloat vertices[] = {tr_x,  tr_y,  front_z, // front top right corner
                          tl_x,  tl_y,  front_z, // front top left corner
                          bl_x,  bl_y,  front_z, // front bottom left corner
                          br_x,  br_y,  front_z, // back bottom right corner
                          tr_x,  tr_y,  back_z,  // back top right corner
                          tl_x,  tl_y,  back_z,  // back top left corner
                          bl_x,  bl_y,  back_z,  // back bottom left corner
                          br_x,  br_y,  back_z   // back bottom right corner
                         }; // bottom right corner

    GLubyte indices[] = {0,1,2,3, // first triangle (bottom left - top left - top right)
                         4,0,3,7,
                         4,5,6,7,
                         1,5,6,2,
                         0,4,5,1,
                         2,6,7,3
                        }; // second triangle (bottom left - top right - bottom right)

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, indices);
}


#endif // SHAPE_H_INCLUDED
