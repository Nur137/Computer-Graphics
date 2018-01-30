#include <windows.h>        // For MS Windows
#include <GL/glut.h>        // GLUT, include glu.h and gl.h

#include "horse.h"
#include "operation.h"

#include "house.h"
#include "color.h"
#include <bits/stdc++.h>    // For C and C++ functionalities

using namespace std;


double rotation=0;
double fan_rotation=0;

int translationMode=0;      // for giving access to translation
int rotationMode=0;         // for giving access to rotation
int mirrorMode=0;
int xMode=0;
int yMode=0;
int zMode=0;


float headX=0;
float headY=1;
float headZ=0;


double front_wheel=0.0;
double back_wheel=0.0;

char title[] = "Toy Horse";                         // title if the window

double trans_x=0;           // translation in x-axis
double trans_y=0;           // translation in y-axis
double trans_z=-10;         // translation in z-axis

double angle_x=0;
double angle_y=0;
double angle_z=0;

int automatic =0;

int refreshMills = 150;                             // refresh interval in milliseconds
int wdth;                                              // width of screen
int hght;                                              // height of screen
double basic_mat[16];
double radius=0;
double q=0,w=.5,e=5;

double j=0,k=0,l=0;

int ml=1;
float za,xa,ya;
int zoom_mode=0;
int lightMode=1;
/* Initialize OpenGL Graphics */
/* Initialize OpenGL Graphics */

void initGL()
{
    glClearColor((232/255.0), (230/255.0), (209/255.0), 1.0f);    // set background color to black and opaque
    glClearDepth(1.0f);                      // set background depth to farthest
    glEnable(GL_DEPTH_TEST);                 // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);               // Set the type of depth-test
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}


void loadMatrix()
{
    memset(basic_mat,0,sizeof(basic_mat));
    for(int i=0; i<16; i+=5)basic_mat[i]=1;
}


//vector<float> Xv,Yv,Zv;

void lookAt(int eyeX, int eyeY, int eyeZ ,int lookX, int lookY, int lookZ, int headX,int headY,int headZ){
    //Xv.clear();Yv.clear();Zv.clear();
    float ZvX=(eyeX-lookX);
    float ZvY=(eyeY-lookY);
    float ZvZ=(eyeZ-lookZ);
    //Zv.push_back(eyeZ-lookZ);
    //for(int i=0;i<3;i++)cout<<Zv[i]<<" ";

    int i1=headX, j1=headY, k1=headZ;
    int i2=ZvX, j2=ZvY, k2=ZvZ;

    float XvX=((k2)*(j1)-(j2)*(k1));
    float XvY=(-(k2)*(i1)+(i2)*(k1));
    float XvZ=((j2)*(i1)-(i2)*(j1));
//    for(int i=0;i<3;i++)cout<<Xv[i]<<" ";
//    cout<<endl;
    i1=ZvX, j1=ZvY, k1=ZvZ;
    i2=XvX, j2=XvY, k2=XvZ;
    float YvX=((k2)*(j1)-(j2)*(k1));
    float YvY=(-(k2)*(i1)+(i2)*(k1));
    float YvZ=((j2)*(i1)-(i2)*(j1));
    //for(int i=0;i<3;i++)cout<<Yv[i]<<" ";

    float nMod=sqrt(ZvX*ZvX+ZvY*ZvY+ZvZ*ZvZ);
    float uMod=sqrt(XvX*XvX+XvY*XvY+XvZ*XvZ);
    float vMod=sqrt(YvX*YvX+YvY*YvY+YvZ*YvZ);

    //cout<<endl;
    //cout<<nMod<<" "<<uMod<<" "<<vMod;
    XvX/=uMod; XvY/=uMod; XvZ/=uMod;
    YvX/=vMod; YvY/=vMod; YvZ/=vMod;
    ZvX/=nMod; ZvY/=nMod; ZvZ/=nMod;


    float rot[16]={XvX, YvX, ZvX, 0,
                   XvY, YvY, ZvY, 0,
                   XvZ, YvZ, ZvZ, 0,
                   0,       0,     0,   1
                   };

    //cout<<endl;cout<<endl;

  /*  for(int i=0;i<16;i++){
        cout<<rot[i]<<"    ";
    }
*/


    glMatrixMode(GL_MODELVIEW);
    glMultMatrixf(rot);

    loadMatrix();
    translate(basic_mat,-eyeX,-eyeY,-eyeZ);
    glMultMatrixd(basic_mat);
}

void light(){

GLfloat light_ambient[]  = {1.0, 1.0, 1.0, 1.0};
GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1 };
GLfloat light_specular[] = { 1, 1, 1, 1 };
GLfloat light_position[] = { 0.0, 1.5, 0.0, 1.0 };
if(lightMode)
glEnable( GL_LIGHT0);
else glDisable(GL_LIGHT0);

		glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);
		glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);
		glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular);
		glLightfv( GL_LIGHT0, GL_POSITION, light_position);
		GLfloat spot_direction[] = { 0.0, -1, 0 };
		glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
		glLightf( GL_LIGHT0, GL_SPOT_CUTOFF, 90.0);



//		glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 5.0);
//        glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 2.0);
}

void drawTable()
{
    // drawing table
    // table base
    glPushMatrix();
    //glColor3f(33/255.0, 21/255.0, 14/255.0);

    //myColor(33/255.0, 21/255.0, 14/255.0,4.0);
    myColor(49/255.0, 92/255.0, 73/255.0,4.0);

    //myColor(33/255.0, 2/255.0, 255/255.0,2.0);

    loadMatrix();
    translate(basic_mat,0,-2.075,0);
    glMultMatrixd(basic_mat);

    loadMatrix();
    scale(basic_mat,7.6, 0.2, 4);
    glMultMatrixd(basic_mat);

    drawBaseCube();

    glPopMatrix();

    // table leg front right
    glPushMatrix();

    //glColor3f(139/255.0, 87/255.0, 62/255.0);
    //myColor(0/255.0, 255/255.0, 0/255.0,2);

    myColor(139/255.0, 87/255.0, 62/255.0,3);
    loadMatrix();
    translate(basic_mat, 7.3, -5.275 , 3.7);
    glMultMatrixd(basic_mat);

    loadMatrix();
    scale(basic_mat, 0.23, 3, .2);
    glMultMatrixd(basic_mat);

    drawBaseCube();
    glPopMatrix();

    // table leg front left
    glPushMatrix();

    //glColor3f(139/255.0, 87/255.0, 62/255.0);
    myColor(139/255.0, 87/255.0, 62/255.0,3);
    loadMatrix();
    translate(basic_mat, -7.3, -5.275 , 3.7);
    glMultMatrixd(basic_mat);

    loadMatrix();
    scale(basic_mat, 0.23, 3, .2);
    glMultMatrixd(basic_mat);

    drawBaseCube();
    glPopMatrix();


    // table leg back left
    glPushMatrix();

    //glColor3f(139/255.0, 87/255.0, 62/255.0);
    myColor(139/255.0, 87/255.0, 62/255.0,3);
    loadMatrix();
    translate(basic_mat, -7.3, -5.275 , -3.7);
    glMultMatrixd(basic_mat);

    loadMatrix();
    scale(basic_mat, 0.23, 3, .2);
    glMultMatrixd(basic_mat);

    drawBaseCube();
    glPopMatrix();

    // table leg back right
    glPushMatrix();

    //glColor3f(139/255.0, 87/255.0, 62/255.0);
    myColor(139/255.0, 87/255.0, 62/255.0,3);
    loadMatrix();
    translate(basic_mat, 7.3, -5.275 , -3.7);
    glMultMatrixd(basic_mat);

    loadMatrix();
    scale(basic_mat, 0.23, 3, .2);
    glMultMatrixd(basic_mat);

    drawBaseCube();
    glPopMatrix();
}


void drawBed()
{
    glPushMatrix();
    //glColor3f(211/255.0, 203/255.0, 201/255.0);
    myColor(211/255.0, 203/255.0, 201/255.0,3);
    glTranslated(0,-3.375,-25);
    // bed-shed

    glPushMatrix();
    loadMatrix();
    scale(basic_mat, 15, .3, 4);
    glMultMatrixd(basic_mat);
    drawBaseCube();
    glPopMatrix();


    //pillow
    glPushMatrix();
    //glColor3f(237/255.0, 122/255.0, 101/255.0);
    myColor(237/255.0, 122/255.0, 101/255.0,3);

    loadMatrix();
    translate(basic_mat, -13.5,.3, 0);
    glMultMatrixd(basic_mat);

    loadMatrix();
    scale(basic_mat, 1, .3, 1.5);
    glMultMatrixd(basic_mat);
    drawBaseCube();
    glPopMatrix();

    //base
    glPushMatrix();
    //glColor3f(0,0,0);
    myColor(0,0,0,3);

    loadMatrix();
    translate(basic_mat, 0, -.6, 0);
    glMultMatrixd(basic_mat);

    loadMatrix();
    scale(basic_mat, 15, .3, 4);
    glMultMatrixd(basic_mat);
    drawBaseCube();
    glPopMatrix();


    //Back_stand
    glPushMatrix();
    //glColor3f(33/255.0, 21/255.0, 14/255.0);
    myColor(33/255.0, 21/255.0, 14/255.0,3);

    loadMatrix();
    translate(basic_mat, -15.3 , 2.1 , 0);
    glMultMatrixd(basic_mat);

    loadMatrix();
    scale(basic_mat, .3, 3, 4);
    glMultMatrixd(basic_mat);
    drawBaseCube();
    glPopMatrix();

    // front left leg

    glPushMatrix();
    //glColor3f(33/255.0, 21/255.0, 14/255.0);
    myColor(33/255.0, 21/255.0, 14/255.0,3);

    loadMatrix();
    translate(basic_mat, -15.3, -2.9 , 3.7);
    glMultMatrixd(basic_mat);

    loadMatrix();
    scale(basic_mat, .3, 2, .3);
    glMultMatrixd(basic_mat);
    drawBaseCube();
    glPopMatrix();



    // back left leg

    glPushMatrix();
    //glColor3f(33/255.0, 21/255.0, 14/255.0);
    myColor(33/255.0, 21/255.0, 14/255.0,3);

    loadMatrix();
    translate(basic_mat, -15.3, -2.9 , -3.7);
    glMultMatrixd(basic_mat);

    loadMatrix();
    scale(basic_mat, .3, 2, .3);
    glMultMatrixd(basic_mat);
    drawBaseCube();
    glPopMatrix();

    // front right leg

    glPushMatrix();
    //glColor3f(33/255.0, 21/255.0, 14/255.0);
    myColor(33/255.0, 21/255.0, 14/255.0,3);

    loadMatrix();
    translate(basic_mat, 14.7, -2.9 , 3.7);
    glMultMatrixd(basic_mat);

    loadMatrix();
    scale(basic_mat, .3, 2, .3);
    glMultMatrixd(basic_mat);
    drawBaseCube();
    glPopMatrix();

    // back right leg

    glPushMatrix();
    //glColor3f(33/255.0, 21/255.0, 14/255.0);
    myColor(33/255.0, 21/255.0, 14/255.0,4);

    loadMatrix();
    translate(basic_mat, 14.7, -2.9 , -3.7);
    glMultMatrixd(basic_mat);

    loadMatrix();
    scale(basic_mat, .3, 2, .3);
    glMultMatrixd(basic_mat);
    drawBaseCube();
    glPopMatrix();
    glPopMatrix();
}

void drawFan(){
//draw fan
    glPushMatrix();

    loadMatrix();
    translate(basic_mat, 0, 6.275 , 0);
    glMultMatrixd(basic_mat);


    loadMatrix();
    rotateX(basic_mat,-acos(-1)/2);
    glMultMatrixd(basic_mat);


    loadMatrix();
    rotateZ(basic_mat,fan_rotation);
    glMultMatrixd(basic_mat);


    //glColor3f(219/255,196/255,144/255);
    //glColor3f(1,0,0);
    // fan center

    double init_fan=0;
    for(int i=-10;i<=10;i++)
    {
        drawWheel(0,0,i*.01,1,1000);
    }

    // upper bottom hand
    glPushMatrix();
    loadMatrix();
    scale(basic_mat, .3 , 3, .1);
    glMultMatrixd(basic_mat);
    drawBaseCube();
    glPopMatrix();


    // left right hand
    glPushMatrix();
    loadMatrix();
    scale(basic_mat, 3 , .3, .1);
    glMultMatrixd(basic_mat);
    drawBaseCube();
    glPopMatrix();

    // holder

    //glColor3f(102/255,204/255,30/255);
    myColor(102/255,204/255,30/255,3);

    loadMatrix();
    translate(basic_mat, 0, 0 , -1);
    glMultMatrixd(basic_mat);

    glPushMatrix();
    loadMatrix();
    scale(basic_mat, .08 , .08, 1);
    glMultMatrixd(basic_mat);
    drawBaseCube();
    glPopMatrix();


    glPopMatrix();

// End  fan

}

/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void rotateAroundLine(double start_x, double start_y, double start_z,
                      double end_x, double end_y, double end_z)
{
// inverse translate
    glMatrixMode(GL_MODELVIEW);

    loadMatrix();
    translate(basic_mat,start_x,start_y,start_z);
    glMultMatrixd(basic_mat);
    //glTranslatef(start_x,start_y,start_z);

// inverse align
    loadMatrix();
    double a=end_x-start_x, b=end_y-start_y, c=end_z-start_z;
    double lambda= sqrt(b*b+c*c);
    double v_mod= sqrt(a*a+b*b+c*c);

    basic_mat[0]=lambda/v_mod;
    basic_mat[1]= -(a*b) /(lambda*v_mod);
    basic_mat[2]= -(a*c) /(lambda*v_mod);
    basic_mat[5]= c/lambda;
    basic_mat[6]= -b/lambda;
    basic_mat[8]=a/v_mod;
    basic_mat[9]= b/v_mod;
    basic_mat[10]= c/v_mod;

    glMultMatrixd(basic_mat);


    // rotate

    loadMatrix();
    rotateZ(basic_mat,rotation);
    glMultMatrixd(basic_mat);
    //glRotatef(rotation,0,0,1);


// Aligning with Z axis
    loadMatrix();
    basic_mat[0]=lambda/v_mod;
    basic_mat[2]=a/v_mod;
    basic_mat[4]= -(a*b) /(lambda*v_mod);
    basic_mat[5]= c/lambda;
    basic_mat[6]= b/v_mod;
    basic_mat[8]= -(a*c) /(lambda*v_mod);
    basic_mat[9]= -b/lambda;
    basic_mat[10]= c/v_mod;

    glMultMatrixd(basic_mat);

// Translate
    //glTranslatef(-start_x,-start_y,-start_z);

    loadMatrix();
    translate(basic_mat,-start_x,-start_y,-start_z);
    glMultMatrixd(basic_mat);

// draw Line
    //glColor3f(0,0,0);
    myColor(0,0,0,3);
    glBegin(GL_LINES);
    glVertex3f(start_x,start_y,start_z);
    glVertex3f(end_x,end_y,end_z);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
    // Making model-view an identity matrix
    glLoadIdentity();

    //Translation

    loadMatrix();

    // Translating in all axis
    translate(basic_mat,trans_x,trans_y,trans_z);
    glMultMatrixd(basic_mat);

    // Rotating about x axis
    loadMatrix();
    rotateX(basic_mat,angle_x);
    glMultMatrixd(basic_mat);

    // Rotating about y axis
    loadMatrix();
    rotateY(basic_mat,angle_y);
    glMultMatrixd(basic_mat);

    // Rotating about z axis
    loadMatrix();
    rotateZ(basic_mat,angle_z);
    glMultMatrixd(basic_mat);

    // scaling
    loadMatrix();
    //scale(basic_mat,.3);
    glMultMatrixd(basic_mat);

    //gluLookAt(q,w,e, j,k,l ,headX,headY,headZ);
    lookAt(q,w,e, j,k,l ,headX,headY,headZ);

    light();
    glPushMatrix();

     //house

    myColor(0,0,1,3);

    loadMatrix();
    scale(basic_mat,60,8.275,40);
    glMultMatrixd(basic_mat);

    drawCube(1,1, -1,-1 ,1,-1);
    glPopMatrix();


    glPushMatrix();
    rotateAroundLine(5,-6,2,3,5,-2);

/*
    GLfloat mat_ambient[] = { 0, .5, 0.0, 1.0 };
    GLfloat mat_diffuse[] = { 0, 1.0, 0.0, 1.0 };
    //GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {1};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    //glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

*/

    drawBody(front_wheel,back_wheel);
    glPopMatrix();


    glPushMatrix();
glTranslated(4,-1,0);
glScaled(.6,.6,.6);
    myColor(1,0,0,4);

    for(float k=0;k<180;k+=.02){

    glRotatef(k,0,1,0);

    glBegin(GL_LINE_STRIP);

    glVertex3f(.8,-1.3,0);
    glVertex3f(.8,-1.0,0);
    glVertex3f(.5,-1,0);
    glVertex3f(.5,1,0);
    glVertex3f(.8,1.3,0);
    glVertex3f(.8,1.8,0);

    glEnd();
    }

    glPopMatrix();


    //drawing table
    drawTable();
    // draw Bed
    drawBed();

    //draw Fan
    drawFan();

    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}


/* Called back when timer expired */
void timer(int value)
{
    fan_rotation+=.15;
    if(automatic==1)
    rotation+=.2;
    //anglePyramid += 0.5f;
    //front_wheel+=10.0f;
    //back_wheel+=10.0f;
    glutPostRedisplay();      // Post re-paint request to activate display()
    glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later

}

void my_keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
// yaw
case '2':
    j+=.2;
    break;

case '3':
    j-=.2;
    break;

// pitch
case '4':
    //cout<<q<<" "<<w<<" "<<e<<" "<<j<<" "<<k<<" "<<l<<endl;
    k+=.2;
    break;

case '5':
    //cout<<q<<" "<<w<<" "<<e<<" "<<j<<" "<<k<<" "<<l<<endl;
    k-=.2;
    break;


    //roll
    case 'f':
        cout<<headX<<" "<<headY<<endl;
        if(headX>-1.1 && headX<-.9){
            if(headY>.9 && headY<1.1){headX+=.1;cout<<"posX"<<endl;}
            else headY+=.2;
        }
        else if(headX>.9 && headX<1.1){
            if(headY>-1.1 && headY<-.9){headX-=.1;cout<<"negX"<<endl;}
            else headY-=.1;
        }
        else if(headY>.9 && headY<1.1){
            headX+=.1;
            cout<<"posY"<<endl;
        }
        else if(headY>-1.1 && headY<-.9){
            headX-=.1;
            cout<<"negY"<<endl;
        }

    break;


    case 'Q':
        q+=.2f;
        break;

    case 'W':
        w+=.2f;
        break;
    case 'E':
        e+=.2f;
        break;


        if(mirrorMode==1)trans_y+=.5f;
        else cout<<"Select translation mode"<<endl;
        break;

    case 'J':
        if(translationMode==1)trans_x-=.5f;
        else cout<<"Select translation mode"<<endl;
        break;
    case 'K':
        if(translationMode==1)trans_y-=.5f;
        else cout<<"Select translation mode"<<endl;
        break;
    case 'L':
        if(translationMode==1)trans_x+=.5f;
        else cout<<"Select translation mode"<<endl;
    case 'q':
        q-=.2f;
        break;
    case 'w':
        w-=.2f;
        break;
    case 'e':
        e-=.2f;
        break;


    // Translate if translation mode is on
    case 'I':
        if(translationMode==1)trans_y+=.5f;
        else cout<<"Select translation mode"<<endl;
        break;
        break;

    // Accessing rotation
    case 'R':
        if(rotationMode==0)
        {
            rotationMode=1;
            cout<<"Rotation Mode Activated"<<endl;
        }
        else
        {
            rotationMode=0;
            cout<<"Rotation Mode Deactivated"<<endl;
        }
        break;

    // Accessing translation
    case 'T':
        if(translationMode==0)
        {
            translationMode=1;
            cout<<"Translation Mode Activated"<<endl;
        }
        else
        {
            translationMode=0;
            cout<<"Translation Mode Deactivated"<<endl;
        }
        break;

    // Accessing x direction
    case 'X':
        if(rotationMode==1)
        {
            cout<<"X Mode Activated"<<endl;
            xMode=1;
            yMode=0;
            zMode=0;
        }
        else cout<<"Select Rotation Mode"<<endl;

        break;

    // Accessing y direction
    case 'Y':
        if(rotationMode==1)
        {
            cout<<"Y Mode Activated"<<endl;
            xMode=0;
            yMode=1;
            zMode=0;
        }
        else cout<<"Select Rotation Mode"<<endl;
        break;
    // Accessing z direction
    case 'Z':
        if(rotationMode==1)
        {
            cout<<"Z Mode Activated"<<endl;
            xMode=0;
            yMode=0;
            zMode=1;
        }
        else cout<<"Select Rotation Mode"<<endl;
        break;





    // Rotating clockwise
    case 'c':
        if(rotationMode==1)
        {
            if(xMode==1)
            {
                angle_x -= .05;
            }
            else if(yMode==1)
            {
                angle_y -= .05;
            }
            else if(zMode==1)
            {
                angle_z -= .05;
            }
            else cout<<"Select x,y or z mode"<<endl;
        }
        else cout<<"Select rotation mode"<<endl;
        break;


    //counter counter-clockwise
    case 'C':
        if(rotationMode==1)
        {
            if(xMode==1)
            {
                angle_x+= .05;
            }
            else if(yMode==1)
            {
                angle_y += .05;
            }
            else if(zMode==1)
            {
                angle_z += .05;
            }
            else cout<<"Select x,y or z mode"<<endl;
        }
        else cout<<"Select rotation mode"<<endl;
        break;

    // Flip operation
    case 'F':
        cout<<"Flip Mode Activated"<<endl;
        angle_y+=acos(-1);
        break;


    case 'M':
        cout<<radius<<" "<<q<<" "<<e<<endl;
        radius=sqrt(q*q+ e*e);

        if((q+ml*.5)>=radius)ml=-1;
        else if((q+ml*.5)<=-radius)ml=1;

        q=q+ ml*.5;

        e= ml*sqrt(radius*radius-q*q);

        break;

    //birds eye view
    case '6':
        cout<<radius<<" "<<w<<" "<<e<<endl;
        radius=sqrt(w*w+ e*e);

        if((w+ml*.3)>=radius)ml=-1;
        else if((w+ml*.3)<=-radius)ml=1;
        if((radius-w)>.3){
        w=w+ ml*.3;
        e= ml*sqrt(radius*radius-w*w);
        }
        else{
            w=radius;
            e=0.1;

        }

        break;


    case 'U':
        rotation+=.2;
        break;

    case 'A':
        if(automatic==0)automatic=1;
        else automatic=0;
        break;


    case 'S':

    if(zoom_mode==0)
    {zoom_mode=1;
    xa=q;ya=w;za=e;
    cout<<"Zoom Mode Activated"<<endl;
    }
    else {zoom_mode=0; cout<<"Zoom In Mode Activated"<<endl;
    }
    break;


    case 'b':
        if(zoom_mode==1)
        {
        cout<<q<<" "<<w<<" "<<e<<endl;
        q=xa- (xa/za)*(za-e);
        e+=.2;
        w=ya- (ya/za)*(za-e);
        }
    break;

    case 'B':
        if(zoom_mode==1)
        {
        cout<<q<<" "<<w<<" "<<e<<endl;
        q=xa- (xa/za)*(za-e);
        e-=.2;
        w=ya- (ya/za)*(za-e);
        }
    break;

    // lightMode
    case '7':
        if(lightMode)lightMode=0;
        else lightMode=1;
     break;

     case '8':
        if(diffLight)diffLight=0;
        else diffLight=1;
     break;

     case '9':
        if(ambLight)ambLight=0;
        else ambLight=1;
     break;

     case '0':
        if(specularLight)specularLight=0;
        else specularLight=1;
     break;

    case 'O':
        exit(0);			// exit
    }
    glutPostRedisplay();		// redraw the image now
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height)    // GLsizei for non-negative integer
{
    // Compute aspect ratio of the new window
    wdth=width;
    hght=height;
    if (height == 0) height = 1;                // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping volume to match the viewport
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();             // Reset
    // Enable perspective projection with fovy, aspect, zNear and zFar
    gluPerspective(45.0f, aspect, 0.1f, 1000.0f);
}



/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv)
{
    cout<<ambLight;
    lookAt(5,6,2,1,1,1,0,1,0);
    glutInit(&argc, argv);               // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE);    // Enable double buffered mode
    glutInitWindowSize(640, 480);        // Set the window's initial width & height
    glutInitWindowPosition(50, 50);      // Position the window's initial top-left corner
    glutCreateWindow(title);             // Create window with the given title
    glEnable(GL_LIGHTING);
    glutDisplayFunc(display);            // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);            // Register callback handler for window re-size event
    glutKeyboardFunc(my_keyboard);		// call keyboard() when key is hit
    initGL();                            // Our own OpenGL initialization
    glutTimerFunc(0, timer, 0);          // First timer call immediately [NEW]
    glutMainLoop();                      // Enter the infinite event-processing loop
    return 0;
}
