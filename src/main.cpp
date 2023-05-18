#include "Application.h"
#include "Cube.h"

/*
    Implement Line Drawing
    Implement Triangle Drawing
    Implement 
*/
int main()
{
    Model cube(cubeTris);
    Application app("Software Rasterizer", 1080, 720);
    app.run();
    return 0;
}