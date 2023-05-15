#include<stdio.h>
#include"glm.h"


GLMmodel* pmodel = NULL;
void display()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///清理背景不清會有殘影

    if(pmodel==NULL) {
        pmodel = glmReadOBJ("Al.obj");
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90);
    }
    glmDraw(pmodel, GLM_MATERIAL);

    glutSolidTeapot(0.3);
	glutSwapBuffers();

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
