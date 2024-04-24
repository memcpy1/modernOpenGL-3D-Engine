#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

class VertexBuffer
{
	unsigned int VertexBufferID;
	

public:
	
	VertexBuffer(const void* data, unsigned int size, unsigned int usage);
	~VertexBuffer();

	void Bind();
	void UnBind();
};

class IndexBuffer
{
	unsigned int IndexBufferID;
	
public:

	IndexBuffer(const void* data, unsigned int size, unsigned int usage);
	~IndexBuffer();
	

	void Bind();
	void UnBind();
	
};

class VertexArray
{
	unsigned int VertexArrayID;


public:

	VertexArray();
	~VertexArray();

	void Bind();
	void UnBind();
};

