#include "renderer/renderer.h"

void Renderer::Init(){

    ShaderProgram = CompileShader("/home/abror/Gamedev/Voxel_Engine/shaders/vertexShader.glsl", 
                                  "/home/abror/Gamedev/Voxel_Engine/shaders/fragmentShader.glsl");

    float Front[] = {
  
        -0.5f, -0.5f, -0.5f,   0.0f,  0.0f, -1.0f,  // pos + normal
        0.5f, -0.5f, -0.5f,   0.0f,  0.0f, -1.0f,
        0.5f,  0.5f, -0.5f,   0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,   0.0f,  0.0f, -1.0f,
        0.5f,  0.5f, -0.5f,   0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,   0.0f,  0.0f, -1.0f,
    };
  
    float Back[] = {
        0.5f, -0.5f,  0.5f,   0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,   0.0f,  0.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,   0.0f,  0.0f,  1.0f,
        0.5f, -0.5f,  0.5f,   0.0f,  0.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,   0.0f,  0.0f,  1.0f,
        0.5f,  0.5f,  0.5f,   0.0f,  0.0f,  1.0f,
    };
    float Left[]{

        -0.5f, -0.5f,  0.5f,  -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  -1.0f,  0.0f,  0.0f,
    };
    float Right[]{

        0.5f, -0.5f, -0.5f,   1.0f,  0.0f,  0.0f,
        0.5f, -0.5f,  0.5f,   1.0f,  0.0f,  0.0f,
        0.5f,  0.5f,  0.5f,   1.0f,  0.0f,  0.0f,
        0.5f, -0.5f, -0.5f,   1.0f,  0.0f,  0.0f,
        0.5f,  0.5f,  0.5f,   1.0f,  0.0f,  0.0f,
        0.5f,  0.5f, -0.5f,   1.0f,  0.0f,  0.0f,
    };
    float Top[]{

        -0.5f, -0.5f,  0.5f,   0.0f, -1.0f,  0.0f,
        0.5f, -0.5f,  0.5f,   0.0f, -1.0f,  0.0f,
        0.5f, -0.5f, -0.5f,   0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,   0.0f, -1.0f,  0.0f,
        0.5f, -0.5f, -0.5f,   0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,   0.0f, -1.0f,  0.0f,
    
    };
    float Down[]{
        -0.5f,  0.5f, -0.5f,   0.0f,  1.0f,  0.0f,
        0.5f,  0.5f, -0.5f,   0.0f,  1.0f,  0.0f,
        0.5f,  0.5f,  0.5f,   0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,   0.0f,  1.0f,  0.0f,
        0.5f,  0.5f,  0.5f,   0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,   0.0f,  1.0f,  0.0f,
    };


    glGenVertexArrays(6, VAO);
    glGenBuffers(6, VBO);

    float* faces[6] = {Front, Back, Left, Right, Top, Down};
 
    for (int i = 0; i < 6; i++) {
    
        glBindVertexArray(VAO[i]);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[i]);
        glBufferData(GL_ARRAY_BUFFER, 36 * sizeof(float), faces[i], GL_STATIC_DRAW); 
    
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
    }
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

 //   glEnable(GL_POLYGON_MODE);

}


void Renderer::Clear(){
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::RenderChunk(const Chunk& chunk, const glm::mat4& view, const glm::mat4& projection){
    glUseProgram(ShaderProgram);
    
    glm::vec3 color;
 
    unsigned int modelLoc = glGetUniformLocation(ShaderProgram, "model");
    unsigned int viewLoc = glGetUniformLocation(ShaderProgram, "view");
    unsigned int projLoc = glGetUniformLocation(ShaderProgram, "projection");
    unsigned int lightPosLoc = glGetUniformLocation(ShaderProgram, "lightPos");
    unsigned int lightColorLoc = glGetUniformLocation(ShaderProgram, "lightColor");
    unsigned int objectColorLoc = glGetUniformLocation(ShaderProgram, "objectColor");
 
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
    glUniform3f(lightPosLoc, 0.0f, 0.0f, 100.0f);

    glUniform3f(lightColorLoc, 1.0f, 1.0f, 1.0f);
    

    for (int x=0; x<32; x++) {
        for (int y=0; y<32; y++) {
            for (int z=0; z<32; z++) {
                if (chunk.blocks[x][y][z] == 0){
                    continue;
                }
                else if (chunk.blocks[x][y][z] == 1) {
                    color = {0.5f, 1.0f, 0.2f};
                }
 
                glm::mat4 model = glm::translate(glm::mat4(1.0f), 
                                                 glm::vec3(x * 0.5f, y * 0.5f, z * 0.5f));

                glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

                glUniform3f(objectColorLoc, color.r, color.g, color.b);

                if (chunk.getBlock(x+1, y, z) == 0) {  
                    glBindVertexArray(VAO[3]); 
                    glDrawArrays(GL_TRIANGLES, 0, 6);
                }
                if (chunk.getBlock(x-1, y, z) == 0) {  
                    glBindVertexArray(VAO[2]); 
                    glDrawArrays(GL_TRIANGLES, 0, 6);
                }
 
                if (chunk.getBlock(x, y+1, z) == 0) {  
                    glBindVertexArray(VAO[5]); 
                    glDrawArrays(GL_TRIANGLES, 0, 6);
                }
                if (chunk.getBlock(x, y-1, z) == 0) {  
                    glBindVertexArray(VAO[4]); 
                    glDrawArrays(GL_TRIANGLES, 0, 6);
                }
 
                if (chunk.getBlock(x, y, z+1) == 0) {  
                    glBindVertexArray(VAO[1]); 
                    glDrawArrays(GL_TRIANGLES, 0, 6);
                }
                if (chunk.getBlock(x, y, z-1) == 0) { 
                    glBindVertexArray(VAO[0]);  
                    glDrawArrays(GL_TRIANGLES, 0, 6);
                }
            }
        }
    }
}

GLuint Renderer::CompileShader(const char* vertSource, const char* fragSource){
 
    std::ifstream vShaderFile(vertSource);
    std::ifstream fShaderFile(fragSource);

    std::stringstream vShaderStream, fShaderStream;
    
    vShaderStream << vShaderFile.rdbuf();
    fShaderStream << fShaderFile.rdbuf();

    std::string vertexCode = vShaderStream.str();
    std::string fragmentCode = fShaderStream.str();

    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    GLuint vertex, fragment;
    int success;
    char infoLog[512];


    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cout << "Vertex Shader compilation error:\n" << infoLog << std::endl;
    }

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        std::cout << "Fragment Shader compilation error:\n" << infoLog << std::endl;
    }

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertex);
    glAttachShader(shaderProgram, fragment);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "Shader Linking Error:\n" << infoLog << std::endl;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    return shaderProgram;
};








