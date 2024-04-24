#include "BufferObject.h"


VertexBuffer::VertexBuffer(const void* data, unsigned int size, unsigned int usage)
{
		glGenBuffers(1, &VertexBufferID);
		glBindBuffer(GL_ARRAY_BUFFER, VertexBufferID);
		glBufferData(GL_ARRAY_BUFFER, size, data, usage);
}

VertexBuffer::~VertexBuffer()
{
		glDeleteBuffers(1, &VertexBufferID);
}

void VertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, VertexBufferID);
}

void VertexBuffer::UnBind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


IndexBuffer::IndexBuffer(const void* data, unsigned int size, unsigned int usage)
{
	glGenBuffers(1, &IndexBufferID);
	glBindBuffer(IndexBufferID, GL_ELEMENT_ARRAY_BUFFER);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, usage);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &IndexBufferID);
}


void IndexBuffer::Bind()
{
	glBindBuffer(IndexBufferID, GL_ELEMENT_ARRAY_BUFFER);
}
void IndexBuffer::UnBind()
{
	glBindBuffer(0, GL_ELEMENT_ARRAY_BUFFER);
}


VertexArray::VertexArray() 
{
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
}
VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &VertexArrayID);
}
void VertexArray::Bind()
{
	glBindVertexArray(VertexArrayID);
}
void VertexArray::UnBind() 
{
	glBindVertexArray(0);
}