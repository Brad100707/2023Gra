#include <GL/glut.h>
float angle = 0;

void drawHand()
{
    glPushMatrix();
        glScaled(1, 0.3, 0.3);
        glutSolidCube(0.5);

    glPopMatrix();

}

void display()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glPushMatrix();///右上臂
        glTranslatef(0.25, 0, 0);
        glRotatef(angle, 0, 0, 1);
        glTranslatef(0.25, 0, 0);
        drawHand();

        glPushMatrix();///右上走
            glTranslatef(0.25, 0, 0);///掛上去
            glRotatef(angle, 0, 0, 1);
            glTranslatef(0.25, 0, 0);
            drawHand();
        glPopMatrix();

    glPopMatrix();

    glPushMatrix();///左上臂
        glTranslatef(-0.25, 0, 0);
        glRotatef(angle, 0, 0, 1);
        glTranslatef(-0.25, 0, 0);
        drawHand();

        glPushMatrix();///左上走
            glTranslatef(-0.25, 0, 0);///掛上去
            glRotatef(angle, 0, 0, 1);
            glTranslatef(-0.25, 0, 0);
            drawHand();
        glPopMatrix();

    glPopMatrix();


	glutSwapBuffers();
	angle++;///把角度++
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");

    glutDisplayFunc(display);
    glutIdleFunc(display);///清畫面
    glutMainLoop();
}
