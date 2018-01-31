#ifndef RENDERER_H
#define RENDERER_H

#include "SimpleModel.h"
#include "TexturedModel.h"


class Renderer
{
    public:
        Renderer();
        //Renders a SimpleModel to the screen
        void render(SimpleModel model);
        //Renders a TexturedModel to the screen
        void render(TexturedModel model);
        //Prepares screen for rendering
        void prepare();
        ~Renderer();

    protected:

    private:

};

#endif // RENDERER_H
