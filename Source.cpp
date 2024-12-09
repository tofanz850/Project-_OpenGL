#include <GL/glut.h>
#include <iostream>

// Initial transformation values
float translateX = 0.0f, translateY = 0.0f, translateZ = -5.0f;
float rotateX = 0.0f, rotateY = 0.0f, rotateZ = 0.0f;
float scale = 1.0f;

// Function to draw a cube
void drawCube() {
    glBegin(GL_QUADS);

    // Front face (red)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    // Back face (green)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Left face (blue)
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    // Right face (yellow)
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Top face (cyan)
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Bottom face (magenta)
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    glEnd();
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Apply transformations
    glTranslatef(translateX, translateY, translateZ);
    glRotatef(rotateX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotateY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotateZ, 0.0f, 0.0f, 1.0f);
    glScalef(scale, scale, scale);

    // Draw the cube
    drawCube();

    glutSwapBuffers();
}

// Keyboard input handling
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'w': translateY += 0.1f; break; // Move up
    case 's': translateY -= 0.1f; break; // Move down
    case 'a': translateX -= 0.1f; break; // Move left
    case 'd': translateX += 0.1f; break; // Move right
    case 'q': translateZ += 0.1f; break; // Move forward
    case 'e': translateZ -= 0.1f; break; // Move backward

    case 'i': rotateX += 5.0f; break; // Rotate X-axis
    case 'k': rotateX -= 5.0f; break; // Rotate X-axis
    case 'j': rotateY += 5.0f; break; // Rotate Y-axis
    case 'l': rotateY -= 5.0f; break; // Rotate Y-axis
    case 'u': rotateZ += 5.0f; break; // Rotate Z-axis
    case 'o': rotateZ -= 5.0f; break; // Rotate Z-axis

    case '+': scale += 0.1f; break;   // Scale up
    case '-': scale -= 0.1f; break;   // Scale down

    case 27: exit(0); // Escape key to exit
    }
    glutPostRedisplay();
}

// Initialization
void init() {
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0f, 1.0f, 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Transformations");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
