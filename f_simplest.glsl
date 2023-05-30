#version 330

uniform sampler2D textureMap0;
uniform sampler2D textureMap1;

out vec4 pixelColor; //Zmienna wyjsciowa fragment shadera. Zapisuje sie do niej ostateczny (prawie) kolor piksela

in vec4 l1;
in vec4 l2;
in vec4 n;
in vec4 v;
in vec2 iTexCoord0;

void main(void) {

	vec4 ml1=normalize(l1);
	vec4 ml2=normalize(l2);
	vec4 mn=normalize(n);
	vec4 mv=normalize(v);

	//przeniesione z vertex shadera
	vec4 r1=reflect(-ml1,mn);
	vec4 r2=reflect(-ml2,mn);

	float nl1=clamp(dot(ml1,mn),0,1); //iloczyn skalarny, clamp - jak wartosc < 0 to zrob 0
	float nl2=clamp(dot(ml2,mn),0,1);

    float rv1=pow(clamp(dot(r1,mv),0,1),50);
    float rv2=pow(clamp(dot(r2,mv),0,1),50);

	vec4 texColor0=texture(textureMap0,iTexCoord0);
	vec4 texColor1=texture(textureMap1,iTexCoord0);

	pixelColor=(texColor0*nl1+texColor1*rv1)+(texColor0*nl2+texColor1*rv2);
}
