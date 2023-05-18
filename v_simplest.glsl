#version 330

//Zmienne jednorodne
uniform mat4 P;
uniform mat4 V;
uniform mat4 M;

uniform vec4 color;

//Atrybuty
in vec4 vertex; //wspolrzedne wierzcholka w przestrzeni modelu

out vec4 iColor;

void main(void) {
    gl_Position=P*V*M*vertex;

    iColor=color;
}
