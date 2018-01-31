#include "Renderer.h"

Renderer::Renderer(){
    //ctor
}

void Renderer::render(SimpleModel model){
        /*Render*/
    glBindVertexArray(model.GetvaoID());
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, model.GetnumVertices());
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}

void Renderer::render(TexturedModel model){
    /*Render*/
    glBindVertexArray(model.GetvaoID());
//    glEnableVertexAttribArray(0);
//    glEnableVertexAttribArray(1);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, model.getTex());
    glDrawArrays(GL_TRIANGLES, 0, model.GetnumVertices());
//    glDisableVertexAttribArray(0);
//    glDisableVertexAttribArray(1);
    glBindVertexArray(0);
}

void Renderer::prepare(){
     /*Clear the buffer*/
    glClearColor(1.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

Renderer::~Renderer(){
    //dtor
}
