#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 u_Model;

void main()
{
  //vec3 pos = aPos * 0.3333;
  vec4 pos = u_Model * vec4(aPos,1.0);
  gl_Position = pos;
}
