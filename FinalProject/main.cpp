#include <GL/glut.h>
#include <stdio.h>
FILE * fout = NULL; ///一開始檔案沒有開,NULL
FILE * fin = NULL;  ///
///在project-properties 到build target 可以去上面把目錄改成小數點.
///build target debug 和 release 都要改成小數點.
///記得去freeglut把freeglut.dll放到錄中
float teapotX=0, teapotY=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX, teapotY, 0);
        glutSolidTeapot(0.3);
    glPopMatrix;
    glutSwapBuffers();

}
void mouse(int button, int state, int x, int y)
{
    if(state == GLUT_DOWN) {
        teapotX = (x-150)/150.0;
        teapotY = (150-y)/150.0;
        if(fout==NULL) fout = fopen("file.txt", "w");
        fprintf(fout, "%f %f\n", teapotX, teapotY);
    }
    display();
}
void keyboard(unsigned char key, int x, int y)
{
    if(fin==NULL) {
        fclose(fout);
        fin = fopen("file.txt", "r");
    }
    fscanf(fin, "%f %f", &teapotX, &teapotY);
    display();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}
