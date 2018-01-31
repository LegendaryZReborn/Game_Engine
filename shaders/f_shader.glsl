#version 430

in vec4 color;
in vec2 texCoords;

out vec4 f_color;

layout(location = 2) uniform int sampleTexture;
uniform sampler2D tex;

layout(location = 1) uniform float time;

void main(){
   vec4 nColor = vec4(color.x + sin(time), color.y + cos(time), color.z + sin(time) + cos(time), 1.0);
   f_color = sampleTexture * texture(tex, texCoords) - (sampleTexture - 1) * nColor;

}
