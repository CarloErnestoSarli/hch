#version 450

in float colour;

uniform sampler1D colourTexture;

out vec4 fColour;

void main()
{
    fColour = texture(colourTexture, colour);
}
