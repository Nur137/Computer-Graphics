#ifndef HORSE_H_INCLUDED
#define HORSE_H_INCLUDED
#include "shape.h"
#include "color.h"

const double MAX_INTENSITY=255.0;


void drawBody( double front_wheel, double back_wheel)
{

    /* Eye */
    //glColor3f(0,0,0);
    myColor(0,0,0,2);

    drawWheel(-1.9f, 1.1, -.29, 0.08f, 10000);
    drawWheel(-1.9f, 1.1, -.61, 0.08f, 10000);


    /* Mouth */
    //glColor3f((85/MAX_INTENSITY), (76/MAX_INTENSITY), (71/MAX_INTENSITY));     // Red
    myColor((85/MAX_INTENSITY), (76/MAX_INTENSITY), (71/MAX_INTENSITY),3);     // Red
    drawCube(-2.32f, 0.82f, -2.5f, 0.6f,-.3,-.6);

    /* Ear */
    //glColor3f((99/MAX_INTENSITY), (24/MAX_INTENSITY), (1/MAX_INTENSITY));
    myColor((99/MAX_INTENSITY), (24/MAX_INTENSITY), (1/MAX_INTENSITY),3);
    drawCube(-1.86f, 1.46f, -2.05f, 1.6f, -2.05f, 1.6f, -2.0f, 1.29f, -.3,-.6);

    /* Neck */
    //glColor3f((136/MAX_INTENSITY), (0/MAX_INTENSITY), (21/MAX_INTENSITY));     // Red
    myColor((136/MAX_INTENSITY), (0/MAX_INTENSITY), (21/MAX_INTENSITY),3);     // Red
    drawCube(0, 1.0f,  -1.8f, 1.55f,  -1.89, 1.42f, -0.7f, -.1f, -.3, -.6);

    //drawCube(-1.6,1.32,  -1.8f, 1.55f,  -1.9,1.55f,  -2,1.6, -.3, -.6);

    // Face
    //glColor3f((185/MAX_INTENSITY), (122/MAX_INTENSITY), (87/MAX_INTENSITY));     // Red
    myColor((185/MAX_INTENSITY), (122/MAX_INTENSITY), (87/MAX_INTENSITY),3);     // Red
    drawCube(-1.38, .8, -1.9, 1.42, -2.33,.8, -2.33,.65, -.3, -.6);

    //drawCube(-1.21, .8, -1.78, 1.45, -2.33,.8, -2.33,.65);

    /* Collar */
    //glColor3f((39/MAX_INTENSITY), (34/MAX_INTENSITY), (28/MAX_INTENSITY));     // Red
    myColor((39/MAX_INTENSITY), (34/MAX_INTENSITY), (28/MAX_INTENSITY),3);     // Red
    drawCube(0.1f, 1.0f, -.1f, 1.05f, -0.7f, -.1f,-0.6f, -.18f,-.3,-.6);

    /* Body of horse */

    //glBegin(GL_POLYGON);

    //glColor3f((185/MAX_INTENSITY), (122/MAX_INTENSITY), (87/MAX_INTENSITY));     // Red
    myColor((185/MAX_INTENSITY), (122/MAX_INTENSITY), (87/MAX_INTENSITY),2);     // Red

    drawCube(2.4f, .5f, 2.3f, .8f,2.1f, 1.0f,2.4f, -.38f,-.3, -.6);
    drawCube( -0.6f, -.38f, 2.4f, -.38f, 0.1f, 1.0f,-0.6f, -.18f, -.3,-.6);
    drawCube( -0.6f, -.38f, 2.4f, -.38f, 0.1f, 1.0f,-0.6f, -.18f, -.3,-.6);
    drawCube(2.4f, -.38f,2.1f, 1.0f,0.1f, 1.0f,-0.6f, -.18f,-.3,-.6);

    /* Front left leg */
    //glColor3f((39/MAX_INTENSITY), (34/MAX_INTENSITY), (28/MAX_INTENSITY));     // Red
    myColor((39/MAX_INTENSITY), (34/MAX_INTENSITY), (28/MAX_INTENSITY),3);     // Red
    drawCube(0.1f, -.38f,-0.1f, -1.38f, -0.3, -0.4);

    /* back left leg */
    //glColor3f((39/MAX_INTENSITY), (34/MAX_INTENSITY), (28/MAX_INTENSITY));     // Red
    myColor((39/MAX_INTENSITY), (34/MAX_INTENSITY), (28/MAX_INTENSITY),3);     // Red
    drawCube(0.1f, -.38f,-0.1f, -1.38f, -0.5, -0.6);


    /* Front right leg */

    drawCube(1.8f, -.38f, 1.6f, -1.38f, -0.3, -0.4);

    /* Back right leg */

    drawCube(1.8f, -.38f, 1.6f, -1.38f, -0.5, -0.6);



    /* Tail */
    //glColor3f((39/MAX_INTENSITY), (34/MAX_INTENSITY), (28/MAX_INTENSITY));     // Red
    myColor((39/MAX_INTENSITY), (34/MAX_INTENSITY), (28/MAX_INTENSITY),3);     // Red

    double init_tail=4.0;
    for(int i=0;i<=100;i++){
    glBegin(GL_POLYGON);
    glVertex3f(2.6f, -.38f,-.4-.001*i);
    glVertex3f(2.6f, .7f,-.4-.001*i);
    glVertex3f(2.5f, -.38f,-.4-.001*i);
    glVertex3f(2.5f, .7f,-.4-.001*i);
    glVertex3f(2.6f, .7f,-.4-.001*i);
    glVertex3f(2.45f, .75f,-.4-.001*i);
    glVertex3f(2.45f, .75f,-.4-.001*i);
    glVertex3f(2.3f, .79f,-.4-.001*i);

    glEnd();
    }
    /* Base */
    //glColor3f((136/MAX_INTENSITY), (0/MAX_INTENSITY), (21/MAX_INTENSITY));     // Red
    myColor((136/MAX_INTENSITY), (0/MAX_INTENSITY), (21/MAX_INTENSITY),3);
    drawCube(-1.32f, -1.7f, 2.9f, -1.3f, 0,-1);


    /* Front forward wheel*/
    glPushMatrix();
    // Changing center
    glTranslatef(-0.62f, -1.475f, 0);
    glRotatef(front_wheel, 0.0f, 0.0f, 1.0f);
    glTranslatef(.62f,1.475f, 0);

    //glColor3f(0,0,0);
    myColor(0,0,0,3);
    double init_z_of_front_for_wheel = 0;

    for(int i=0;i<=10;i++){
    drawWheel(-0.62f, -1.475f, init_z_of_front_for_wheel, 0.4f, 10000);
    init_z_of_front_for_wheel+= .01;
    }
    //drawing line
    //glColor3f(1,1,1);
    myColor(1,1,1,3);
    glBegin(GL_LINES);
    glVertex3f(-1.02f, -1.475f, 0.1);
    glVertex3f(-0.22f,-1.475f, 0.1);
    glVertex3f(-0.62f,-1.875f, 0.1);
    glVertex3f(-0.62f,-1.075f, 0.1);
    glEnd();

    glPopMatrix();


    /* Front backward wheel */
    glPushMatrix();

    // Changing center
    glTranslatef(2.22f, -1.475f, 0.0f);
    glRotatef(back_wheel, 0.0f, 0.0f, 1.0f);
    glTranslatef(-2.22f,1.475f, 0);

    double init_z_of_front_back_wheel = 0;

    //glColor3f(0,0,0);
    myColor(0,0,0,3);
    for(int i=0;i<=10;i++){
    drawWheel(2.22f, -1.475f, init_z_of_front_back_wheel, 0.4f, 10000);
    init_z_of_front_back_wheel+= .01;
    }

    //glColor3f(1,1,1);
    myColor(1,1,1,3);
    glBegin(GL_LINES);


    glVertex3f(1.82f, -1.475f, .1);
    glVertex3f(2.62f, -1.475f, .1);
    glVertex3f(2.22f,-1.875f, .1);
    glVertex3f(2.22f,-1.075f, .1);
    glEnd();
    glPopMatrix();


    /* Back forward wheel*/

    glPushMatrix();
    // Changing center
    glTranslatef(-0.62f, -1.475f, 0);
    glRotatef(front_wheel, 0.0f, 0.0f, 1.0f);
    glTranslatef(.62f,1.475f, 0);

    myColor(0,0,0,30);

    double init_z_of_back_for_wheel = 0;

    for(int i=0;i<=10;i++){
    drawWheel(-0.62f, -1.475f, -1-init_z_of_back_for_wheel, 0.4f, 10000);
    init_z_of_back_for_wheel+= .01;
    }
    //drawing line
    //glColor3f(1,1,1);
    myColor(1,1,1,3);

    glBegin(GL_LINES);
    glVertex3f(-1.02f, -1.475f, -1.1);
    glVertex3f(-0.22f,-1.475f, -1.1);
    glVertex3f(-0.62f,-1.875f, -1.1);
    glVertex3f(-0.62f,-1.075f, -1.1);
    glEnd();

    glPopMatrix();


    /* Back backward wheel */
    glPushMatrix();

    // Changing center
    glTranslatef(2.22f, -1.475f, 0.0f);
    glRotatef(back_wheel, 0.0f, 0.0f, 1.0f);
    glTranslatef(-2.22f,1.475f, 0);

    double init_z_of_back_back_wheel = 0;

    //glColor3f(0,0,0);
    myColor(0,0,0,3);
    for(int i=0;i<=10;i++){
    drawWheel(2.22f, -1.475f, -1-init_z_of_back_back_wheel, 0.4f, 10000);
    init_z_of_back_back_wheel+= .01;
    }

    //glColor3f(1,1,1);
    myColor(1,1,1,3);
    glBegin(GL_LINES);


    glVertex3f(1.82f, -1.475f, -1.1);
    glVertex3f(2.62f, -1.475f, -1.1);
    glVertex3f(2.22f,-1.875f, -1.1);
    glVertex3f(2.22f,-1.075f, -1.1);
    glEnd();
    glPopMatrix();
}


#endif // HORSE_H_INCLUDED
