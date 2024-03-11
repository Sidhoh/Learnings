#version 330 core
out vec4 FragColor;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;

in vec3 Normal;
in vec3 FragPos;

void main()
{
	//ambient
	float ambientStrength = 0.5;
	vec3 ambient = ambientStrength * lightColor;

	//diffuse
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);
	float diff = dot(norm, lightDir);
	vec3 diffuse = diff * lightColor;

	vec3 result = (ambient * diffuse) * objectColor;
	FragColor = vec4(result, 1.0);
}
