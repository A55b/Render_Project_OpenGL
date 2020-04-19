#version 330

out vec4 FragColor;

in vec4 Colour0;

void main()
{
	//float r = abs(noise1(1.0));
    //float g = abs(noise1(1.0));
    //float b = abs(noise1(1.0));
    //FragColor = vec4(r, g, b, 1.0);
    //FragColor = vec4(0, 1.0, 0, 1.0);

	 FragColor = Colour0;
}