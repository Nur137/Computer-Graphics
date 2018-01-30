#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED


int diffLight=1, ambLight=1, specularLight=1;

void myColor(float r,float g,float b,float shininess)
{
    GLfloat mat_ambient[] = {   r/2.0,g/2.0,b/2.0, 1.0 };
    GLfloat mat_diffuse[] = { r,g,b, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {shininess};

    if(ambLight)
    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    if(diffLight)
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    if(specularLight)
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
}

#endif // COLOR_H_INCLUDED
