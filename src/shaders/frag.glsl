#version 330 core

out vec4 FragColor;

uniform vec3 lightColor;
uniform vec3 cubeColor;
uniform vec3 viewPos;
uniform vec3 lightPos;

void main(){
    float ambiantStrength = 0.1;
    vec3 ambient = ambiantStrength*lightColor;

    vec3 diffuse = lightColor;

    float specularStrength = 0.5;
    vec3 specular = specularStrength * lightColor;  

    vec3 result = (ambient + diffuse + specular) * cubeColor;
    FragColor = vec4(result, 1.0);
}