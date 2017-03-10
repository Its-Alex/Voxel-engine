#include "Shaders.hpp"

using namespace glm;

Shaders::Shaders(std::string vertexFilePath, std::string fragmentFilePath) :
	mVertexPath(vertexFilePath), mFragmentPath(fragmentFilePath)
{
    // Crée les shaders
    mVertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    mFragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
}

Shaders::~Shaders()
{
}

GLuint Shaders::Load()
{
    // Lit le code du vertex shader à partir du fichier
    std::string VertexShaderCode;
    std::ifstream VertexShaderStream(mVertexPath, std::ios::in);
    if(VertexShaderStream.is_open())
    {
        std::string Line = "";
        while(getline(VertexShaderStream, Line))
            VertexShaderCode += "\n" + Line;
        VertexShaderStream.close();
    }

    // Lit le code du fragment shader à partir du fichier
    std::string FragmentShaderCode;
    std::ifstream FragmentShaderStream(mFragmentPath, std::ios::in);
    if(FragmentShaderStream.is_open()){
        std::string Line = "";
        while(getline(FragmentShaderStream, Line))
            FragmentShaderCode += "\n" + Line;
        FragmentShaderStream.close();
    }

    GLint Result = GL_FALSE;
    int InfoLogLength;

    // Compile le vertex shader
    printf("Compiling shader : %s\n", mVertexPath.c_str());
    char const * VertexSourcePointer = VertexShaderCode.c_str();
    glShaderSource(mVertexShaderID, 1, &VertexSourcePointer , NULL);
    glCompileShader(mVertexShaderID);

    // Vérifie le vertex shader
    glGetShaderiv(mVertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(mVertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> VertexShaderErrorMessage(InfoLogLength);
    glGetShaderInfoLog(mVertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
    fprintf(stdout, "%s\n", &VertexShaderErrorMessage[0]);

    // Compile le fragment shader
    printf("Compiling shader : %s\n", mFragmentPath.c_str());
    char const * FragmentSourcePointer = FragmentShaderCode.c_str();
    glShaderSource(mFragmentShaderID, 1, &FragmentSourcePointer , NULL);
    glCompileShader(mFragmentShaderID);

    // Vérifie le fragment shader
    glGetShaderiv(mFragmentShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(mFragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> FragmentShaderErrorMessage(InfoLogLength);
    glGetShaderInfoLog(mFragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
    fprintf(stdout, "%s\n", &FragmentShaderErrorMessage[0]);

    // Lit le programme
    fprintf(stdout, "Linking program\n");
    GLuint ProgramID = glCreateProgram();
    glAttachShader(ProgramID, mVertexShaderID);
    glAttachShader(ProgramID, mFragmentShaderID);
    glLinkProgram(ProgramID);

    // Vérifie le programme
    glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> ProgramErrorMessage( max(InfoLogLength, int(1)) );
    glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
    fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);

    glDeleteShader(mVertexShaderID);
    glDeleteShader(mFragmentShaderID);

    return (ProgramID);
}