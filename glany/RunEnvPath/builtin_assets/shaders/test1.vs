#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 u_Model;

uniform mat4 u_Translation;
uniform mat4 u_Rotation;
uniform mat4 u_Scale;

uniform mat4 u_View;
uniform mat4 u_Projection;

void main()
{
  vec4 pos = u_Projection * u_View * u_Model * vec4(aPos,1.0);
  //vec4 pos = u_View * u_Model * vec4(aPos,1.0);
  gl_Position = pos;
}

