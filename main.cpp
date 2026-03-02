#include <GL/freeglut.h>

void render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0); glVertex2f(-0.5, -0.5);
    glColor3f(0, 1, 0); glVertex2f(0.5, -0.5);
    glColor3f(0, 0, 1); glVertex2f(0, 0.5);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Assignment 1 - Part A");
    glutDisplayFunc(render);
    glutMainLoop();
    return 0;
}