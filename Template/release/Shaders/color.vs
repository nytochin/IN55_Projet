#version 140


uniform mat4 MVP;

in vec3 position;
in vec2 texCoord;
in vec3 color;

out vec3 fColor;
out vec2 fTexCoord;


void main()
{
  gl_Position = MVP * vec4( position, 1.0f );

  fColor = color;
  fTexCoord = texCoord;
}
