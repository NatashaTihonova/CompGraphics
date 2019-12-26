layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec3 normal;

uniform mat4 mvp;

uniform struct Transform {
	mat3 normalUp;
	vec3 lookAt;
} cameraProps;

struct Light {
	vec4 position;
	vec4 ambientColor;
	vec4 diffuseColor;
	vec4 specularColor;
	vec3 attenuation;
};

uniform struct Lights {
	Light moon;
} lights;

out Vertex {
	vec2 texcoord;
	vec3 normal;
	vec3 lightDir;
	vec3 viewDir;
} Vert;

void main() {
	vec4 vertex = vec4(position, 1.0f);
	gl_Position = mvp * vertex;

	//заполнение структуры
	Vert.texcoord = texCoord;
	Vert.normal = cameraProps.normalUp * normal;
	Vert.lightDir = vec3(lights.moon.position - vertex);
	Vert.viewDir = cameraProps.lookAt - vec3(vertex);
}