#include "GL/glew.h"
#include "iostream"
#include "SDL2/SDL.h"
#include "filesystem"
#include "fstream"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/trigonometric.hpp>
#include <glm/gtc/type_ptr.hpp> 
#include "include/world/chunk/chunk.h"

class Renderer{
private:
    
    GLuint VAO[6], VBO[6], EBO[6];
    GLuint ShaderProgram;

public:
    void Init();

    void Clear();
    
    void RenderChunk(const Chunk& chunk, const glm::mat4& view, const glm::mat4& projection);
 
    GLuint CompileShader(const char* vertSource, const char* fragSource);

};
