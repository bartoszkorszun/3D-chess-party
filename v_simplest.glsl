#version 330

//Zmienne jednorodne
uniform mat4 P;
uniform mat4 V;
uniform mat4 M;

//Atrybuty
in vec4 vertex; //wspolrzedne wierzcholka w przestrzeni modelu
in vec4 normals;
in vec2 texCoord0;

out vec4 l1;
out vec4 l2;
out vec4 n;
out vec4 v;
out vec2 iTexCoord0;

uniform vec4 lp1;
uniform vec4 lp2;

void main(void) {
    
    l1=normalize(V*lp1-V*M*vertex); //przenoszenie do przestreni oka i normalizowanie
    l2=normalize(V*lp2-V*M*vertex);
    n=normalize(V*M*normals); //przenoszenie do przestreni oka i normalizowanie

    //model phonga
    v=normalize(vec4(0,0,0,1)-V*M*vertex);

    iTexCoord0=texCoord0;
    gl_Position=P*V*M*vertex;
}
