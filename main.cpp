#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

void display();
void reshape(int w,int h);
void timer(int);
void keyboard(unsigned char Key, int k, int b);


void init(){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
}

void texture(void){
    const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
    const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

    const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
    const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
    const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}


float angle=0;


int main(int argc,char**argv)
{
    // used to initialize the GLUT library.
    glutInit(&argc,argv);
    //sets the initial display mode.
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    //sets display window properties
    glutInitWindowPosition(200,0);
    glutInitWindowSize(1200,800);
    glutCreateWindow("19109957 - 19103385");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(2500/60,timer,0);

    init();
    texture();

    //PlayResource("spaceSound");

    //BOOL sndPlaySound(TEXT("space.mp3"),SND_LOOP);

    //PlaySound(TEXT("space.mp3"),NULL,SND_FILENAME);
    //enters the GLUT event processing loop.
    glutMainLoop();
}

void display()
{
    //to clear ( all previous color frame buffers in this case due to color buffer bit sent )
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glLoadIdentity to reset all translation or any rotation done(simply resets coordinates system)
    glLoadIdentity();
    glTranslatef(0.0,0.0,-15.0);

//----------------------------------------------------------------------------------------------//
    //space base
    glBegin(GL_TRIANGLES);

      //upper cyan color front
      glColor3f(0.0, 1.0, 1.0); //cyan color for the upper part
      glVertex3f(-4.5, 4.0, -0.5);
      glVertex3f(-5.0, 3.0, 0.0);
      glVertex3f(-4.0, 3.0, 0.0);

      //upper cyan color right
      glVertex3f(-4.5, 4.0, -0.5);
      glVertex3f(-4.0, 3.0, 0.0);
      glVertex3f(-4.0, 3.0, -1.0);

      //upper cyan color left
      glVertex3f(-4.5, 4.0, -0.5);
      glVertex3f(-5.0, 3.0, 0.0);
      glVertex3f(-5.0, 3.0, -1.0);

      //upper cyan color back
      glVertex3f(-4.5, 4.0, -0.5);
      glVertex3f(-5.0, 3.0, -1.0);
      glVertex3f(-4.0, 3.0, -1.0);

      //lower green color front
      glColor3f(0.0, 1.0, 0.0);
      glVertex3f(-5.0, 3.0, 0.0);
      glVertex3f(-4.5, 2.0, -0.5);
      glVertex3f(-4.0, 3.0, 0.0);

      //lower green color right
      glVertex3f(-4.0, 3.0, 0.0);
      glVertex3f(-4.5, 2.0, -0.5);
      glVertex3f(-4.0, 3.0, -1.0);

      //lower green color left
      glVertex3f(-5.0, 3.0, 0.0);
      glVertex3f(-4.5, 2.0, -0.5);
      glVertex3f(-5.0, 3.0, -1.0);

      //lower green color back
      glVertex3f(-5.0, 3.0, -1.0);
      glVertex3f(-4.5, 2.0, -0.5);
      glVertex3f(-4.0, 3.0, -1.0);

    glEnd();

//----------------------------------------------------------------------------------------------//

    //Dodecahedron space meteorite
    glPushMatrix();

      glColor3f(1.0,0.0,0.0); //red color
      glTranslated(5.0,3.0,3.0); //to change the meteor place
      glScalef(0.4,0.4,0.2); //to scale Dodecahedron
      glutSolidDodecahedron();//draw Dodecahedron shape

    glPopMatrix();


    //Icosahedron space meteorite
    glPushMatrix();

      glColor3f(1.0,0.0,0.0); //red color
      glTranslated(-8.0,-4.0,-5.0); //to change the meteor place
      glScalef(0.6,0.6,0.6); //to scale Icosahedron
      glutSolidIcosahedron();//draw Icosahedron shape

    glPopMatrix();


    //tetrahedron star
    glPushMatrix();

      glColor3f(1.0,1.0,1.0); //white color
      glTranslated(5.0,-3.0,3.0); //to change the star place
      glScalef(0.2,0.2,0.2); //to scale tetrahedron
      glutSolidTetrahedron();//draw Tetrahedron shape

    glPopMatrix();


    //octahedron star
    glPushMatrix();

      glColor3f(1.0,1.0,1.0); //white color
      glTranslated(5.4,0.0,3.0); //to change the star place
      glScalef(0.2,0.2,0.2); //to scale octahedron
      glutSolidOctahedron();//draw octahedron shape

    glPopMatrix();


    //tetrahedron star 2
    glPushMatrix();

      glColor3f(1.0,1.0,1.0); //white color
      glTranslated(-0.8,3.8,3.0); //to change the star place
      glScalef(0.2,0.2,0.2); //to scale tetrahedron
      glutSolidTetrahedron();//draw Tetrahedron shape

    glPopMatrix();


    //octahedron star 2
    glPushMatrix();

      glColor3f(1.0,1.0,1.0); //white color
      glTranslated(-5.4,3.0,3.0); //to change the star place
      glScalef(0.2,0.2,0.2); //to scale octahedron
      glutSolidOctahedron();//draw octahedron shape

    glPopMatrix();


    //tetrahedron star 3
    glPushMatrix();

      glColor3f(1.0,1.0,1.0); //white color
      glTranslated(-4.0,-3.8,3.0); //to change the star place
      glScalef(0.25,0.2,0.2); //to scale tetrahedron
      glutSolidTetrahedron();//draw Tetrahedron shape

    glPopMatrix();


    //octahedron star 3
    glPushMatrix();

      glColor3f(1.0,1.0,1.0); //white color
      glTranslated(3.0,4.0,3.0); //to change the star place
      glScalef(0.2,0.25,0.2); //to scale octahedron
      glutSolidOctahedron();//draw octahedron shape

    glPopMatrix();

//----------------------------------------------------------------------------------------------//

    //stable sun
    glPushMatrix();

      glColor3f(1.0,1.0,0.0); //yellow color
      glTranslated(1.0,1.6,3.0); //to change the sun place
      glutSolidSphere(1,30,30);//draw sphere shape

    glPopMatrix();

    //multicolor cube
    glBegin(GL_QUADS);

      //front red color face
      glColor3f(1.0,0.0,0.0);//red color
      glVertex3f(-0.3,0.3,0.3);
      glVertex3f(-0.3,-0.3,0.3);
      glVertex3f(0.3,-0.3,0.3);
      glVertex3f(0.3,0.3,0.3);

      //back green color face
      glColor3f(0.0,1.0,0.0);//green color
      glVertex3f(0.3,0.3,-0.3);
      glVertex3f(0.3,-0.3,-0.3);
      glVertex3f(-0.3,-0.3,-0.3);
      glVertex3f(-0.3,0.3,-0.3);

      //right blue color face
      glColor3f(0.0,0.0,1.0);//blue color
      glVertex3f(0.3,0.3,0.3);
      glVertex3f(0.3,-0.3,0.3);
      glVertex3f(0.3,-0.3,-0.3);
      glVertex3f(0.3,0.3,-0.3);

      //left yellow color face
      glColor3f(1.0,1.0,0.0);//yellow color
      glVertex3f(-0.3,0.3,-0.3);
      glVertex3f(-0.3,-0.3,-0.3);
      glVertex3f(-0.3,-0.3,0.3);
      glVertex3f(-0.3,0.3,0.3);

      //top cyan color face
      glColor3f(0.0,1.0,1.0);//cyan color
      glVertex3f(-0.3,0.3,-0.3);
      glVertex3f(-0.3,0.3,0.3);
      glVertex3f(0.3,0.3,0.3);
      glVertex3f(0.3,0.3,-0.3);

      //bottom magenta color face
      glColor3f(1.0,0.0,1.0);// magenta color
      glVertex3f(-0.3,-0.3,-0.3);
      glVertex3f(0.3,-0.3,-0.3);
      glVertex3f(0.3,-0.3,0.3);
      glVertex3f(-0.3,-0.3,0.3);

    glEnd();

//----------------------------------------------------------------------------------------------//

    //rotation function of planet and moon and cube shape
    glRotatef(angle,1.0,1.0,1.0);

    //---------------//

    //the planet that rotates around the sun
    glPushMatrix();

      glTranslated(-4.0,1.6,3.0);//translate the planet's place
      glColor3f(0.0,0.0,1.0);//blue color
      glutSolidSphere(0.8,20,30);//draw sphere shape

    glPopMatrix();

    //---------------//

    //the moon of the planet that rotates with the planet around the sun
    glPushMatrix();

      glTranslated(-2.5,1.2,3.0);
      glColor3f(1.0,1.0,1.0);
      glutSolidSphere(0.3,20,30);

    glPopMatrix();

    //---------------//

    glutSwapBuffers();
}


void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    //replace the current matrix with the identity matrix.
    glLoadIdentity();
    gluPerspective(40.0,(GLdouble)w/(GLdouble)h,0.5,20.0);
    //Specify the coordinates for the clipping planes.
    glMatrixMode(GL_MODELVIEW);
}


// timer of angle of rotation
void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(2500/60,timer,0);
    angle+=1;
    //start over again when 1 rotation is completed
    if(angle>360){
        angle-=360;
    }
}

void keyboard(unsigned char Key, int k, int b){

    switch(Key)
    {
        //view a full screen when clicking 'f' key
        case 'f' : glutFullScreen();
        break;

        //close the run of program or exit when clicking 'esc' key
        case 27 : exit(0);
        break;
    }
}
