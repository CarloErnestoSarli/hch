#version 450

in float xPoint;
in float yPoint;
in float colourAttr;

uniform mat4 matrix;

out float colour;

void main()
{
    gl_Position = matrix * vec4(xPoint, yPoint, 0, 1);
    colour = colourAttr;
}
