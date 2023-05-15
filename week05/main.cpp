#include <GL/glut.h>
float angle = 0;
void display()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///清理背景不清會有殘影

	glColor3f(0,1,0);
	glPushMatrix();///備份矩陣
        glutSolidCube(0.5);

        glPushMatrix();
            glTranslatef(0.25, 0.25, 0);///step3把紅色又一向右上x,y各0.25
            glRotatef(angle, 0, 0, 1);///step2轉動
            glTranslatef(0.25,0.25,0.25);///step1把紅色放到旋轉中心

            glColor3f(1,0,0);
            glutSolidCube(0.5);
    glPopMatrix();/// 還原矩陣
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
