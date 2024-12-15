#include <windows.h>  // Only for Visual Studio (required for OpenGL on Windows)
#include <GL/glut.h>  // Include GLUT header


float x1 = 0.2f, y1 = 0.2f, z1 = 0.2f;
float x2 = 0.6f, y2 = 0.6f, z2 = 0.6f;
float x3 = 0.2f, y3 = 0.6f, z3 = 0.6f;



// Function to draw XYZ axes
void drawAxes() {
    glLineWidth(2.0f); // Set line width

    // X-axis (Red)
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glBegin(GL_LINES);
    glVertex3f(-1.0f, 0.0f, 0.0f); // Negative X
    glVertex3f(1.0f, 0.0f, 0.0f);  // Positive X
    glEnd();

    // Y-axis (Green)
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glBegin(GL_LINES);
    glVertex3f(0.0f, -1.0f, 0.0f); // Negative Y
    glVertex3f(0.0f, 1.0f, 0.0f);  // Positive Y
    glEnd();

    // Z-axis (Blue)
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, -1.0f); // Negative Z
    glVertex3f(0.0f, 0.0f, 1.0f);  // Positive Z
    glEnd();
}






// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    glLineWidth(2.0f); // Set line width
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f); // Red line
    glVertex3f(x1, y1, z1);          // Start point of the line
    glVertex3f(x2, y2 ,z2);  
    
    
    // End point of the line
    glEnd();
    glLineWidth(2.0f); // Set line width
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f); // Red line
    glVertex3f(x1, y1, z1);          // Start point of the line
    glVertex3f(x3, y3, z3);


    // End point of the line
    glEnd();
    glFlush(); // Render the scene
    // Reset ModelView matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Draw axes
    drawAxes();
    

    glutSwapBuffers();
}


// Keyboard callback to change line coordinates
void keyboard(unsigned char key, int x, int y ,int z) {
    if (key == ' ') { // If the spacebar is pressed
        // Change line coordinates randomly or predefined
        x1 = 0.0f; y1 = 0.0f; z1= 0.0f;
        x2 = 0.0f;  y2 = 0.6f, z2=-0.5f;
        x3 = 0.3; y3 = 0.4; z3 = 0.1f;

        // Redraw the screen
        glutPostRedisplay();
    }
}
// Mouse callback to change line coordinates
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Change line coordinates on mouse click
        x1 = 0.0f; y1 = 0.0f; z1 = 0.0f;
        x2 = 0.0f;  y2 = 0.6f, z2 = -0.5f;
        x3 = 0.3; y3 = 0.4; z3 = 0.1f;

        // Redraw the screen
        glutPostRedisplay();
    }
}

// Initialization function

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
    glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D rendering

    gluPerspective(45.0f, 1.0f, 1.0f, 10.0f); // Set up perspective projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 3.0,   // Camera position
        0.0, 0.0, 0.0,   // Look-at point
        0.0, 1.0, 0.0);  // Up direction
}
// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("CLICK ON MOUSE");

    init();
    glutDisplayFunc(display);
   
    glutMouseFunc(mouse);         // Register mouse callback
    glutMainLoop();

    return 0;
}
