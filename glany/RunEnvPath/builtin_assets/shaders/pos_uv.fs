#version 330 core

out vec4 FragColor;
in vec2 uv;

uniform sampler2D u_Texture1;
uniform sampler2D u_Texture2;

uniform float u_MixFactor;

void main()
{
  //FragColor = vec4(1.0,0.5,0.3,1.0);

  vec4 col1 = texture(u_Texture1,uv);
  vec4 col2 = texture(u_Texture2,uv);
  FragColor = mix(col1,col2,u_MixFactor);
}
