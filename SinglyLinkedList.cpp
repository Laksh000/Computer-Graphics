#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
#include<gl/glut.h>
int  n = 0;
float j = 0.8;
int num, ar[20];
int ptr;
float li = -7.5, R = 1.0, G = 1.0, B = 1.0, R1, G1, B1;
int l = 0;
char asd[], key;
char msg[60];
bool state[256];
int f1 = 1;
int w2;
int hhh = 0;
int maxNode = 5, nodeCount = 0;

struct node {
    int data;
    struct node* link = NULL;
};
struct node* head = NULL;
struct node* temp;
struct node* p;
struct node* b;
void display();
void help();


void displayText(float x, float y, float R1, float G1, float B1, const char* string) {
    int j = strlen(string);
    glColor3f(R1, G1, B1);
    glRasterPos2f(x, y);
    for (int i = 0; i < j; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
    glFlush();
}
void frontscreen()
{
    displayText(-2.3, 3.5, 0, 0, 1, "SDM INSTITUTE OF TECHNOLOGY");
    displayText(-3.3, 3, 0, 1, 0.1, "DEPARTMENT OF COMPUTER SEIENCE AND ENGINEERING");
    displayText(-1.8, 2.5, 1, 0.5, 1.0, "MINI PROJECT ON");
    displayText(-2.8, 1.7, 0, 1, 1, "SIMULATION OF SINGLY LINKED LIST");
    displayText(-6, 00, 0.6, 0.3, 0.9, "SUBMITED BY");
    displayText(-6, -0.5, 0.6, 0.3, 0.9, "GOURISH SEETARAM GOUDA");
    displayText(-6, -0.9, 0.6, 0.3, 0.9, "(4SU18CS027)");
    displayText(-6, -1.6, 0.6, 0.3, 0.9, "LAKSHMIKANTH K S");
    displayText(-6, -2.1, 0.6, 0.3, 0.9, "(4SU18CS036)");
    displayText(3.5, 00, 0.6, 0.3, 0.9, "GUIDED BY");
    displayText(3.5, -0.5, 0.6, 0.3, 0.9, "ARJUN K");
    displayText(3.5, -0.9, 0.6, 0.3, 0.9, "Asst. Prof Dept of CSE");
    displayText(-1, -3.1, 0.6, 0.3, 0.9, "[Press Enter to Start]");
    glFlush();
}

void draw_node(float i, float j, int n, int mv)

{

    if (l == 4)
    {
        if (maxNode == nodeCount) {
            displayText(-2.6, 2.9, 0, 1, 1, "LINKED LIST LIMIT REACHED");
        }
        if (n == 0)
        {



            char text[20];
            int vv = 0;
            sprintf_s(text, "%d", mv);
            glColor3f(1.0, 1.0, 0.0);
            glRasterPos2f(i + 0.18, j - 0.40);
            while (text[vv] != '\0')
            {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[vv]);
                vv++;
            }

            glColor3f(1.0, 0.60, 0.0);
            glBegin(GL_POLYGON);
            glVertex2f(i, 0);
            glVertex2f(i, j);
            glVertex2f(i + 0.8, j);
            glVertex2f(i + 0.8, 0);
            glEnd();

            glColor3f(0.0, 0.90, 0.80);
            glBegin(GL_POLYGON);
            glVertex2f(i + 0.8, 0);
            glVertex2f(i + 0.8, j);
            glVertex2f(i + 1.6, j);
            glVertex2f(i + 1.6, 0);
            glEnd();

            glLineWidth(4.0f);
            glColor3f(0, 1, 0);
            glBegin(GL_LINES);
            glVertex2f(i + 1.6, j / 2);
            glVertex2f(i + 2.4, j / 2);
            glEnd();


            glColor3f(0, 1, 0);
            glBegin(GL_LINES);
            glVertex2f(i + 2.4, j / 2);
            glVertex2f((i + 2.4) - 0.24, (j / 2) + 0.12);
            glVertex2f(i + 2.4, j / 2);
            glVertex2f((i + 2.4) - 0.24, (j / 2) - 0.14);
            glEnd();
        }
        else
        {
            char text[20];
            int vv = 0;
            sprintf_s(text, "%d", mv);
            glColor3f(1.0, 1.0, 0.0);
            glRasterPos2f(i + 0.18, j - 0.40);
            while (text[vv] != '\0')
            {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[vv]);
                vv++;
            }
            glColor3f(1.0, 0.60, 0.0);
            glBegin(GL_POLYGON);
            glVertex2f(i, 0);
            glVertex2f(i, j);
            glVertex2f(i + 0.8, j);
            glVertex2f(i + 0.8, 0);
            glEnd();

            glLineWidth(3.0f);
            glColor3f(0.0, 0.60, 0.0);
            glBegin(GL_LINES);
            glVertex2f(i + 0.8, j);
            glVertex2f(i + 1.6, 0);
            glEnd();

            glColor3f(0.0, 0.90, 0.80);
            glBegin(GL_POLYGON);
            glVertex2f(i + 0.8, 0);
            glVertex2f(i + 0.8, j);
            glVertex2f(i + 1.6, j);
            glVertex2f(i + 1.6, 0);
            glEnd();
        }
    }
    else if (l == 2)
    {

        displayText(-1.6, 3.7, 1, 0, 1, "[Right Click for the options]");


    }

    glFlush();
}


void node_vertex(void)
{
    int c = -1;
    li = -7.5;
    p = head;
    if (p == NULL) {
        draw_node(R, G, B, 1);
    }
    else {
        printf("The Data present in Linked List are: ");
        while (p != NULL) {
            printf("\n%d", p->data);
            li = li + 2.4;
            p = p->link;
        }
        p = head;
        for (float i = -6; i <= li; i += 2.4)
        {
            n = 0;
            if (p->link == NULL)
            {
                n = 1;
            }
            draw_node(i, j, n, p->data);
            p = p->link;

        }
    }

}
void buttonm() {
    displayText(-1.2, 2.2, 1.0, 1.0, 1.0, "New Simulation");
    glColor3f(1.0, 0.7, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-1.5, 2);
    glVertex2f(-1.5, 2.5);
    glVertex2f(0.5, 2.5);
    glVertex2f(0.5, 2);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(6.5f);
    glBegin(GL_LINES);
    glVertex2f(0.5, 2);
    glVertex2f(-1.53, 2);
    glVertex2f(-1.5, 2);
    glVertex2f(-1.5, 2.5);
    glEnd();
    displayText(-0.8, 0.7, 1.0, 1.0, 1.0, "Help");
    glColor3f(1.0, 0.7, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-1.5, 0.5);
    glVertex2f(-1.5, 1);
    glVertex2f(0.5, 1);
    glVertex2f(0.5, 0.5);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(6.5f);
    glBegin(GL_LINES);
    glVertex2f(0.5, 0.5);
    glVertex2f(-1.53, 0.5);
    glVertex2f(-1.5, 0.5);
    glVertex2f(-1.5, 1);
    glEnd();
    displayText(-0.8, -0.8, 1.0, 1.0, 1.0, "Exit");
    glColor3f(1.0, 0.7, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-1.5, -0.5);
    glVertex2f(-1.5, -1);
    glVertex2f(0.5, -1);
    glVertex2f(0.5, -0.5);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(6.5f);
    glBegin(GL_LINES);
    glVertex2f(-1.5, -0.5);
    glVertex2f(-1.5, -1);
    glVertex2f(-1.53, -1);
    glVertex2f(0.5, -1);
    glEnd();


}
void mouse(int button, int state, int x, int y)//change this to mimic a button function to change the screen (main menu/restart sorting/etc...)
{
    y = 700 - y;

    if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (x <= 820) && (x >= 610) && (y <= 545) && (y >= 490) && l == 1)
    {
        l = 2;
        head = NULL;
        display();
        nodeCount = 0;


    }
    if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (x <= 820) && (x >= 610) && (y <= 385) && (y >= 330) && l == 1)
    {

        l = 3;
        display();

    }
    if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (x <= 820) && (x >= 610) && (y <= 225) && (y >= 170) && l == 1)
    {
        exit(0);

    }
}
void display()
{
    glClearColor(R, G, B, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    switch (l)
    {
    case 0:
        frontscreen();
        break;
    case 1:
        buttonm();

        break;
    case 2:
        node_vertex();
        break;
    case 3:
        help();
        break;
    case 4:
        node_vertex();
        break;
    }
    glFlush();
}



void myReshape(int w, int h)

{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-4.0, 4.0, -4.0 * (GLfloat)h / (GLfloat)w, 4.0 * (GLfloat)h / (GLfloat)w, -4.0, 4.0);
    else
        glOrtho(-4.0 * (GLfloat)w / (GLfloat)h, 4.0 * (GLfloat)w / (GLfloat)h, -4.0, 4.0, -4.0, 4.0);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}



void sll_menu(int choice)
{
    int va, va2;

    switch (choice)
    {
    case 1:
        if (nodeCount != maxNode)
        {
            temp = (struct node*)malloc(sizeof(struct node*));
            printf("Enter the data: ");
            scanf_s("%d", &temp->data);
            temp->link = head;
            head = temp;
            l = 4;
            nodeCount += 1;
        }

        display();
        break;
    case 2:
        if (nodeCount != maxNode)
        {
            temp = (struct node*)malloc(sizeof(struct node*));
            printf("Enter the data: ");
            scanf_s("%d", &temp->data);
            temp->link = NULL;
            if (head == NULL) {
                head = temp;
            }
            else {
                p = head;
                while (p->link != NULL) {
                    p = p->link;
                }
                p->link = temp;
            }
            l = 4;
            nodeCount += 1;
        }
        display();
        break;
    case 3:
        if (nodeCount != maxNode)
        {
            temp = (struct node*)malloc(sizeof(struct node*));
            printf("Enter the data: ");
            scanf_s("%d", &temp->data);

            if (head == NULL)
            {
                temp->link = NULL;
                head = temp;
            }
            else
            {
                printf("Enter the Key : ");
                scanf_s("%d", &va2);
                p = head;
                b = head->link;
                while (p->data != va2)
                {
                    p = p->link;
                    b = b->link;
                }
                p->link = temp;
                temp->link = b;
            }
            nodeCount += 1;
        }
        display();
        break;
    case 4:
        if (head == NULL)
        {
            l = 1;
            printf("List is EMPTY");
        }
        else
        {
            if (head->link == NULL)
            {
                head = NULL;
                l = 1;
                printf("List is EMPTY");
            }
            else
            {
                head = head->link;
            }
            nodeCount -= 1;
        }
        display();
        break;
    case 5:
        if (head == NULL)
        {
            l = 1;
            printf("List is EMPTY");
        }
        else
        {
            if (head->link == NULL)
            {
                head = NULL;
                l = 1;
                printf("List is EMPTY");
            }
            else
            {


                p = head->link;
                b = head;
                while (p->link != NULL) {
                    p = p->link;
                    b = b->link;
                }
                b->link = NULL;
            }
            nodeCount -= 1;
        }
        display();

        break;
    case 6:
        printf("Enter the key : ");
        scanf_s("%d", &va2);
        if (head == NULL)
        {
            l = 1;
            printf("List is EMPTY");
        }
        else
        {
            if (head->data == va2)
            {

                head = NULL;
                l = 1;
                printf("List is EMPTY");
            }
            else
            {
                p = head->link;
                b = head;
                while (p->data != va2) {
                    p = p->link;
                    b = b->link;
                }
                b->link = p->link;
            }
            nodeCount -= 1;
        }
        display();
        break;
    case 7:
        exit(0);
    }
}
void help() {
    displayText(-1.5, 3.5, 0.4666, 0.8784, 0.9058, "HELP FOR USER");
    displayText(-5.5, 2.9, 0.9450, 0.5607, 0.5607, "->To change the color of the background press 'c/C',pressing 'c/C' upto 3 times can change the color 3 times.");
    displayText(-5.5, 2.6, 0.9450, 0.5607, 0.5607, "->By pressing the 'Esc' button you can come backwards");
    displayText(-5.5, 2.3, 0.9450, 0.5607, 0.5607, "->By pressing the 'Enter' button in the title screen, you will get Menu:");
    displayText(-2.0, 2.0, 0.9450, 0.5607, 0.5607, "->1.First button is: 'New Simulation'");
    displayText(-2.0, 1.7, 0.9450, 0.5607, 0.5607, "->2.Second button is: 'Help'");
    displayText(-2.0, 1.4, 0.9450, 0.5607, 0.5607, "->3.Third button is: 'Exit'");
    displayText(-5.5, 1.1, 0.9450, 0.5607, 0.5607, "->Right click of the mouse will bring up a menu, In which:");
    displayText(-2.0, 0.8, 0.9450, 0.5607, 0.5607, "1.First option is: 'Insert Front'");
    displayText(-2.0, 0.5, 0.9450, 0.5607, 0.5607, "2.Second option is: 'Insert Rear'");
    displayText(-2.0, 0.2, 0.9450, 0.5607, 0.5607, "3.Third option is: 'Insert Specified'");
    displayText(-2.0, -0.1, 0.9450, 0.5607, 0.5607, "4.Fourth option is: 'Delete Front'");
    displayText(-2.0, -0.4, 0.9450, 0.5607, 0.5607, "5.Fifth option is: 'Delete Rear'");
    displayText(-2.0, -0.7, 0.9450, 0.5607, 0.5607, "6.Sixth option is: 'Delete Specified'");
    displayText(-2.0, -1.0, 0.9450, 0.5607, 0.5607, "7.Seventh option is: 'Exit'");
    displayText(-5.5, -1.4, 0.9450, 0.5607, 0.5607, "The maximun number of nodes is '5'");

}

void keys(unsigned char key, int x, int y) {
    if (key == 'c' || key == 'C')
    {
        if (f1 == 1) {
            R = 0.0666; G = 0.0588; B = 0.4313;
            f1 = 2;
        }
        else if (f1 == 2) {
            R = 0.3686; G = 0.0; B = 0.5803;
            f1 = 3;
        }
        else if (f1 == 3) {
            R = 0.0078; G = 0.4313; B = 0.5607;
            f1 = 1;
        }
    }

    if (key == 13) {
        l = 1;
    }
    if (key == 27)
    {
        if (l == 3)
        {
            l--;
        }
        if (l == 4)
        {
            l = l - 2;
        }
        l--;
    }
    display();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Singly Linked List");
    glutCreateMenu(sll_menu);
    glutAddMenuEntry("Insert Front", 1);
    glutAddMenuEntry("Insert Rear", 2);
    glutAddMenuEntry("Insert Specified", 3);
    glutAddMenuEntry("Delete Front", 4);
    glutAddMenuEntry("Delete Rear", 5);
    glutAddMenuEntry("Delete Specified", 6);
    glutAddMenuEntry("Exit", 7);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutKeyboardFunc(keys);
    glutMouseFunc(mouse);
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}