#include <GL/freeglut.h>

float angle = 0.0f;     // For Part B: Rotation
float scale = 1.0f;     // For Part B: Scaling
float transX = 0.0f;    // For Part B: Translation
bool growing = true;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // PART B: Transformations
    glTranslatef(transX, 0.0f, 0.0f);   // a) Translation
    glRotatef(angle, 0.0f, 0.0f, 1.0f); // b) Rotation
    glScalef(scale, scale, 1.0f);       // c) Scaling

    // PART A: Colored Triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(-0.5f, -0.5f); // Red
    glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(0.5f, -0.5f);  // Green
    glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(0.0f, 0.5f);   // Blue
    glEnd();

    glutSwapBuffers();
}

void update(int value) {
    angle += 2.0f; // Continuous rotation

    // Translation logic
    transX += 0.01f;
    if (transX > 1.0f) transX = -1.0f;

    // Scaling logic
    if (growing) scale += 0.01f;
    else scale -= 0.01f;
    if (scale > 1.5f || scale < 0.5f) growing = !growing;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // 60 FPS
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Assignment 1");
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutMainLoop();
    return 0;
}