//#include "SOIL2\SOIL2\SOIL2.h"
//#include "GL/glew.h"
//#include "GL/freeglut.h"
//#include <vector>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtx/transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <glm/gtc/matrix_inverse.hpp>
//#include "shaders.h"
//
//#include <iostream>
//#include <random>
//
//using namespace std;
//
//static int w = 0, h = 0;
//
//
//GLuint floor_texture_id;
//GLuint snowman_texture_id;
//GLuint shaderProgram;
//GLuint VAO, VBO, EBO;
//
//GLfloat dist_x = 0, dist_y = 0, dist_z = 0;
//GLfloat angle = 180;
//
//GLfloat snowman_coord_x = 0, snowman_coord_y = 0;
//GLfloat snowman_angle = 0;
//
//GLfloat cam_dist = 20;
//GLfloat ang_hor = 0, ang_vert = -60;
//
//GLfloat no_light[] = { 0, 0, 0, 1 };
//GLfloat light[] = { 1, 1, 1, 0 };
//glm::mat4 projModelViewMatrix;
//
//std::vector<float> light_angle{ 0, 90, 180 };
//std::vector<float> light_pos{ 5, 5, 5 };
//std::vector<float> light_rad{ 10, 10, 10 };
//
//const double pi = 3.14159265358979323846;
//
//double cam_x = 0;
//double cam_y = 0;
//double cam_z = 0;
//
//float amb[] = { 0.8, 0.8, 0.8 };
//float dif[] = { 0.2, 0.2, 0.2 };
//
//const double step = 1;
//
//
//struct Transform {
//	glm::mat3 normalUp;
//	glm::vec3 lookAt;
//};
//
//struct RoadMaterial {
//	glm::vec4 ambient;  //прин€тие фонового освещени€
//	glm::vec4 diffuse;  //прин€тие диффузного освещени€
//	glm::vec4 specular; //отражение
//	glm::vec4 emission; //излучение
//	float shininess;	//блеск
//};
//
//void init() {
//	glClearColor(0, 0, 0, 1);
//
//	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
//
//	const GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
//	const GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//
//	floor_texture_id = SOIL_load_OGL_texture("road.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
//		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//
//	//snowman_texture_id = SOIL_load_OGL_texture("1.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
//	//	SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//
//	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
//	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);
//	glLightfv(GL_LIGHT3, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT3, GL_SPECULAR, light_specular);
//	glLightfv(GL_LIGHT4, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT5, GL_SPECULAR, light_specular);
//	glLightfv(GL_LIGHT5, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT6, GL_SPECULAR, light_specular);
//	glLightfv(GL_LIGHT6, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT7, GL_SPECULAR, light_specular);
//	glLightfv(GL_LIGHT7, GL_DIFFUSE, light_diffuse);
//
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_COLOR_MATERIAL);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//}
//
//void drawFloor() {
//	glEnable(GL_TEXTURE_2D);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
//	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
//	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dif);
//	glBindTexture(GL_TEXTURE_2D, floor_texture_id);
//
//	glBegin(GL_QUADS);
//	glTexCoord2f(0, 0); glNormal3f(0, 0, 1); glVertex3f(-10, -10, 0);
//	glTexCoord2f(0, 1); glNormal3f(0, 0, 1); glVertex3f(-10, 10, 0);
//	glTexCoord2f(1, 1); glNormal3f(0, 0, 1); glVertex3f(10, 10, 0);
//	glTexCoord2f(1, 0); glNormal3f(0, 0, 1); glVertex3f(10, -10, 0);
//	glEnd();
//
//	glDisable(GL_TEXTURE_2D);
//}
//
//void drawLamps() {
//
//	const GLfloat light_pos[] = { 0.f, 0.f, 4.6f, 1.f };
//	glPushMatrix();
//	glTranslatef(-7, -7, 0);
//	glColor3f(0.0, 0.0, 0.0);
//	glutSolidCylinder(0.5, 0.3, 10, 10);
//	glPushMatrix();
//	glTranslatef(0, 0, 0.6);
//	if (glIsEnabled(GL_LIGHT1))
//		glMaterialfv(GL_FRONT, GL_EMISSION, light);
//	else
//		glMaterialfv(GL_FRONT, GL_EMISSION, no_light);
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glutSolidSphere(0.5, 10, 10);
//	glPopMatrix();
//	glLightfv(GL_LIGHT1, GL_POSITION, light_pos);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-7, 7, 0);
//	glColor3f(0.0, 0.0, 0.0);
//	glutSolidCylinder(0.5, 0.3, 10, 10);
//	glPushMatrix();
//	glTranslatef(0, 0, 0.6);
//	if (glIsEnabled(GL_LIGHT2))
//		glMaterialfv(GL_FRONT, GL_EMISSION, light);
//	else
//		glMaterialfv(GL_FRONT, GL_EMISSION, no_light);
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glutSolidSphere(0.5, 10, 10);
//	glPopMatrix();
//	glLightfv(GL_LIGHT2, GL_POSITION, light_pos);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(7, 7, 0);
//	glColor3f(0.0, 0.0, 0.0);
//	glutSolidCylinder(0.5, 0.3, 10, 10);
//	glPushMatrix();
//	glTranslatef(0, 0, 0.6);
//	if (glIsEnabled(GL_LIGHT5))
//		glMaterialfv(GL_FRONT, GL_EMISSION, light);
//	else
//		glMaterialfv(GL_FRONT, GL_EMISSION, no_light);
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glutSolidSphere(0.5, 10, 10);
//	glPopMatrix();
//	glLightfv(GL_LIGHT5, GL_POSITION, light_pos);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(7, -7, 0);
//	glColor3f(0.0, 0.0, 0.0);
//	glutSolidCylinder(0.5, 0.3, 10, 10);
//	glPushMatrix();
//	glTranslatef(0, 0, 0.6);
//	if (glIsEnabled(GL_LIGHT6))
//		glMaterialfv(GL_FRONT, GL_EMISSION, light);
//	else
//		glMaterialfv(GL_FRONT, GL_EMISSION, no_light);
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glutSolidSphere(0.5, 10, 10);
//	glPopMatrix();
//	glLightfv(GL_LIGHT6, GL_POSITION, light_pos);
//	glPopMatrix();
//
//}
//
//void drawSnowman()
//{
//	glPushMatrix();
//	const GLfloat light_pos[] = { 1.f, 0.f, 0.f };
//	GLfloat dir[] = { 1, 0, 0, 1 };
//	GLfloat pos[] = { 0,0,0 };
//	glTranslated(dist_x, dist_y, 1);
//	glRotated(angle, 0, 0, 1);
//
//	//body
//	glPushMatrix();
//	glColor3f(1.0, 1.0, 1.0);
//	glutSolidSphere(1, 20, 40);
//	glPopMatrix();
//	glPushMatrix();
//	glTranslated(0, 0, 1.5);
//	glutSolidSphere(0.7, 20, 40);
//	glPopMatrix();
//	glPushMatrix();
//	glTranslated(0, 0, 2.45);
//	glutSolidSphere(0.45, 20, 40);
//	glPopMatrix();
//
//	//eyes
//	glColor3f(0, 0, 0);
//	glPushMatrix();
//	if (glIsEnabled(GL_LIGHT3))
//		glMaterialfv(GL_FRONT, GL_EMISSION, light);
//	else
//		glMaterialfv(GL_FRONT, GL_EMISSION, no_light);
//	glTranslated(0.3, 0.3, 2.45);
//	glutSolidSphere(0.1, 20, 20);
//	glMaterialfv(GL_FRONT, GL_EMISSION, no_light);
//	glLightfv(GL_LIGHT3, GL_POSITION, pos);
//	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 60);
//	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, dir);
//	glTranslated(0, -0.6, 0);
//	if (glIsEnabled(GL_LIGHT4))
//		glMaterialfv(GL_FRONT, GL_EMISSION, light);
//	else
//		glMaterialfv(GL_FRONT, GL_EMISSION, no_light);
//	glutSolidSphere(0.1, 20, 20);
//	glLightfv(GL_LIGHT4, GL_POSITION, pos);
//	glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 60);
//	glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, dir);
//	glMaterialfv(GL_FRONT, GL_EMISSION, no_light);
//	glPopMatrix();
//
//
//	//nose
//	glColor3f(1.0f, 0.5f, 0.5f);
//	glPushMatrix();
//	glTranslated(0.4, 0.0, 2.35);
//	glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
//	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
//	glutSolidCone(0.08f, 0.5f, 10, 2);
//	glPopMatrix();
//
//	glDisable(GL_TEXTURE_2D);
//	glPopMatrix();
//	glPopMatrix();
//}
//
//
//void draw_tree(double scale, double x, double y)
//{
//	float amb1[] = { 0.1, 0.1, 0.1 };
//	float dif1[] = { 0.1, 0.1, 0.1 };
//	float spec[] = { 0.1, 0.1, 0.1 };
//	float shin[] = { 0.1, 0.1, 0.1 };
//	glPushMatrix();
//	/*glEnable(GL_TEXTURE_2D);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);*/
//	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb1);
//	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dif1);
//	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
//	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shin);
//	//glBindTexture(GL_TEXTURE_2D, snowman_texture_id);
//	glTranslated(x, y, 3.4 * scale);
//	glColor3f(0.0f, 0.2f, 0.0f);
//	glutSolidCone(0.5 * scale, 0.5 * scale, 20, 20);
//	glPopMatrix();
//	glPushMatrix();
//	glTranslated(x, y, 2.5 * scale);
//	glutSolidCone(0.8 * scale, 1.3 * scale, 20, 20);
//	glPopMatrix();
//	glPushMatrix();
//	glTranslated(x, y, 1.5 * scale);
//	glutSolidCone(1.2 * scale, 1.7 * scale, 20, 20);
//	glPopMatrix();
//	glPushMatrix();
//	glTranslated(x, y, 0.3 * scale);
//	glutSolidCone(1.7 * scale, 2.1 * scale, 20, 20);
//	glPopMatrix();
//	glPushMatrix();
//	glTranslated(x, y, 0);
//	glColor3f(0.65f, 0.17f, 0.17f);
//	glutSolidCylinder(0.5 * scale, 0.3, 20, 20);
//	glPopMatrix();
//}
//
//void setupBuffers() {
//	float vertices[] = {
//		-500, 0, -500, 0, 0, 0, 1, 0,
//		 500, 0, -500, 1, 0, 0, 1, 0,
//		 500, 0, 500, 1, 1, 0, 1, 0,
//		-500, 0, 500, 0, 1, 0, 1, 0
//	};
//
//	//VAO
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//
//	//VBO
//	glGenBuffers(1, &VBO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glGenBuffers(1, &EBO);
//	GLuint ebo_data[] = { 0, 1, 2, 3 };
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(ebo_data), ebo_data, GL_STATIC_DRAW);
//}
//
//void drawLand() {
//	setupBuffers();
//	glUseProgram(shaderProgram);
//
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
//
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//
//	glEnableVertexAttribArray(2);
//	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(5 * sizeof(GLfloat)));
//
//	glActiveTexture(GL_TEXTURE0);
//	glBindTexture(GL_TEXTURE_2D, floor_texture_id);
//	glUniform1i(glGetUniformLocation(shaderProgram, "texture1"), 0);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	//устанавливаем uniform параметры
//
//	glm::mat4 viewMatrix = glm::lookAt(glm::vec3(dist_x, 25, dist_z), glm::vec3(dist_x, 0, dist_z + 100), glm::vec3(0, 1, 0));
//	glm::mat4 rotateYMatrix = glm::rotate(glm::radians(snowman_coord_x), glm::vec3(0.0f, 1.0f, 0.0f));
//	glm::mat4 mvp = projModelViewMatrix * viewMatrix * rotateYMatrix;
//	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "mvp"), 1, GL_FALSE, &mvp[0][0]);
//
//	Transform transform;
//	transform.lookAt = glm::vec3(0, 0, 0);
//	transform.normalUp = glm::mat3(rotateYMatrix);
//	glUniformMatrix3fv(glGetUniformLocation(shaderProgram, "cameraProps.normalUp"), 1, GL_FALSE, &transform.normalUp[0][0]);
//	glUniform3fv(glGetUniformLocation(shaderProgram, "cameraProps.lookAt"), 1, &transform.lookAt[0]);
//
//	RoadMaterial land;
//	glUniform4fv(glGetUniformLocation(shaderProgram, "land.ambient"), 1, &land.ambient[0]);
//	glUniform4fv(glGetUniformLocation(shaderProgram, "land.diffuse"), 1, &land.diffuse[0]);
//	glUniform4fv(glGetUniformLocation(shaderProgram, "land.specular"), 1, &land.specular[0]);
//	glUniform4fv(glGetUniformLocation(shaderProgram, "land.emission"), 1, &land.emission[0]);
//	glUniform1f(glGetUniformLocation(shaderProgram, "land.shiness"), land.shininess);
//
//	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, 0);
//	glUseProgram(0);
//}
//
//
//void update() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glLoadIdentity();
//
//	double ang_vert_r = ang_vert / 180 * 3.1416;
//	double ang_hor_r = ang_hor / 180 * 3.1416;
//	cam_x = cam_dist * std::sin(ang_vert_r) * std::cos(ang_hor_r);
//	cam_y = cam_dist * std::sin(ang_vert_r) * std::sin(ang_hor_r);
//	cam_z = cam_dist * std::cos(ang_vert_r);
//
//	gluLookAt(cam_x, cam_y, cam_z, 0., 0., 0., 0., 0., 1.);
//	drawLamps();
//	drawFloor();
//	drawSnowman();
//	double trees[] = { 1,5,5,
//					  0.7,3,7,
//					  1.2, 6, 7.5 };
//	for (int i = 0; i < 9; i += 3)
//	{
//		draw_tree(trees[i], trees[i + 1], trees[i + 2]);
//	}
//	glFlush();
//	glutSwapBuffers();
//}
//
//void updateCamera() {
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(60.f, (float)w / h, 1.0f, 1000.f);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//
//void keyboard(unsigned char key, int x, int y) {
//	switch (key) {
//	case '1':
//		if (glIsEnabled(GL_LIGHT1))
//			glDisable(GL_LIGHT1);
//		else
//			glEnable(GL_LIGHT1);
//		break;
//	case '2':
//		if (glIsEnabled(GL_LIGHT2))
//			glDisable(GL_LIGHT2);
//		else
//			glEnable(GL_LIGHT2);
//		break;
//	case '5':
//		if (glIsEnabled(GL_LIGHT3))
//		{
//			glDisable(GL_LIGHT3);
//			glDisable(GL_LIGHT4);
//		}
//		else
//		{
//			glEnable(GL_LIGHT3);
//			glEnable(GL_LIGHT4);
//		}
//		break;
//	case '3':
//		if (glIsEnabled(GL_LIGHT5)) {
//			glDisable(GL_LIGHT5);
//		}
//		else {
//			glEnable(GL_LIGHT5);
//		}
//		break;
//	case '4':
//		if (glIsEnabled(GL_LIGHT6)) {
//			glDisable(GL_LIGHT6);
//		}
//		else {
//			glEnable(GL_LIGHT6);
//		}
//		break;
//	case '6':
//		if (glIsEnabled(GL_LIGHT0)) {
//			glDisable(GL_LIGHT0);
//		}
//		else {
//			glEnable(GL_LIGHT0);
//		}
//		break;
//	}
//	glutPostRedisplay();
//}
//
//void reshape(int width, int height) {
//	w = width;
//	h = height;
//
//	glViewport(0, 0, w, h);
//	updateCamera();
//}
//
//void SpecialKeys(int key, int x, int y) {
//	switch (key) {
//	case GLUT_KEY_UP:
//		dist_x += std::cos(angle / 180 * 3.1416) * 0.3;
//		dist_y += std::sin(angle / 180 * 3.1416) * 0.3;
//		break;
//	case GLUT_KEY_DOWN:
//		dist_x -= std::cos(angle / 180 * 3.1416) * 0.3;
//		dist_y -= std::sin(angle / 180 * 3.1416) * 0.3;
//		break;
//	case GLUT_KEY_LEFT:angle -= 5; break;
//	case GLUT_KEY_RIGHT:angle += 5; break;
//	case GLUT_KEY_SHIFT_L: ang_vert -= 5;; break;
//	case GLUT_KEY_SHIFT_R: ang_vert += 5; break;
//	case GLUT_KEY_CTRL_L: ang_hor -= 5; break;
//	case GLUT_KEY_CTRL_R: ang_hor += 5; break;
//	}
//	glutPostRedisplay();
//}
//
//int main(int argc, char* argv[]) {
//	glutInit(&argc, argv);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(600, 600);
//	glutCreateWindow("Ind3");
//
//	glutReshapeFunc(reshape);
//	glutDisplayFunc(update);
//	glutKeyboardFunc(keyboard);
//	glutSpecialFunc(SpecialKeys);
//	init();
//
//
//	//shaderProgram = getShaderProgram("ind3/vertex.shader", "ind3/fragment.shader"); //загрузка шейдеров
//
//	glutMainLoop();
//
//	return 0;
//}