varying vec2 texcoord0;


void main()
{
    gl_Position = ftransform();
    
    // transform texcoords
    texcoord0 = vec2(gl_TextureMatrix[0] * gl_MultiTexCoord0);
   

}