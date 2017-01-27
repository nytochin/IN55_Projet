#version 140


in vec3 fColor;
in vec2 fTexCoord;
uniform sampler2D texId;

out vec4 fragColor;


void main()
{
	vec4 texColor = texture2D(texId, fTexCoord);
  fragColor = texColor;
}
