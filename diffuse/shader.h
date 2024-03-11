#pragma once
#include <glad/glad.h> // include glad to get the required OpenGL headers
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class shader
{
public:
	int ID;
	shader(const char *vertShaderSource, const char *fragShaderSource);
	void use();
private:

};

shader::shader(const char* vertShaderPath, const char* fragShaderPath)
{
	int vertexShader, fragShader;

	std::ifstream vsfile;
	std::ifstream fsfile;

	string vertShaderCode;
	string fragShaderCode;

	try
	{
		vsfile.open(vertShaderPath);
		fsfile.open(fragShaderPath);
		stringstream vShaderStream, fShaderStream;
		vShaderStream << vsfile.rdbuf();
		fShaderStream << fsfile.rdbuf();
		vsfile.close();
		fsfile.close();
		vertShaderCode = vShaderStream.str();
		fragShaderCode = fShaderStream.str();

	}
	catch (ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	const char* vShaderCode = vertShaderCode.c_str();
	const char* fShaderCode = fragShaderCode.c_str();

	//vertex shader
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vShaderCode, NULL);
	glCompileShader(vertexShader);

	//frag shader
	fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragShader, 1, &fShaderCode, NULL);
	glCompileShader(fragShader);

	//shader program
	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragShader);
	glLinkProgram(ID);

	glDeleteShader(vertexShader);
	glDeleteShader(fragShader);
}

void shader::use()
{
	glUseProgram(ID);
}