#include <GL/glut.h>
float angle = 0;
void display()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///清理背景不清會有殘影


    glutSolidSphere(0.05, 30, 30);///創一個glutSolidSphere來輔助

    glPushMatrix();


        glRotatef(angle, 0, 0, 1);/// step02,開始旋轉
        glTranslatef(0.46, -0.05, 0);/// step1把茶壺移到中心點,可創一個glutSolidSphere來輔助
        glutSolidTeapot(0.3);
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
