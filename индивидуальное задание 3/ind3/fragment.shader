in Vertex{
	vec2 texcoord;
	vec3 normal;
	vec3 lightDir;
	vec3 viewDir;
} Vert;

uniform struct LandMaterial {
	vec4 ambient;
	vec4 diffuse;
	vec4 specular;
	vec4 emission;
	float shininess;
} land;

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

uniform sampler2D texture1;

out vec4 FragColor;

void main() {

	vec3 normal = normalize(Vert.normal);
	vec3 lightDir = normalize(Vert.lightDir);
	vec3 viewDir = normalize(Vert.viewDir);
	float dist = length(Vert.lightDir);
	float attenuation = 1.0 / (lights.moon.attenuation[2] + lights.moon.attenuation[1] * dist + lights.moon.attenuation[0] * dist * dist);

	vec4 lightCoef = land.emission; //прибавляем к значению цвета излучение земли

	lightCoef += land.ambient * lights.moon.ambientColor * attenuation; //прибавляем фоновое освещение от луны

	float NdotL = max(dot(normal, lightDir), 0.0);
	lightCoef += land.diffuse * lights.moon.diffuseColor * NdotL * attenuation; //прибавляем диффузное освещение от луны

	float RdotVpow = max(pow(dot(reflect(-lightDir, normal), viewDir), land.shininess), 0.0);
	lightCoef += land.specular * lights.moon.specularColor * RdotVpow * attenuation;

	FragColor = lightCoef * texture(texture1, Vert.texcoord);
}