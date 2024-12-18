#include <GLES2/gl2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "upng.h"
#include "texture.h"
#include "utils.h"
#include "init.h"
#include <math.h>

void bindBuffers(const GLfloat* vertices, GLsizeiptr verticesSize, const GLuint* indices, GLsizeiptr indicesSize) {
    GLuint vbo, ebo;
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);

    GLint positionAttrib = glGetAttribLocation(textureProgram, "aPosition");
    glEnableVertexAttribArray(positionAttrib);
    glVertexAttribPointer(positionAttrib, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void*)0);

    GLint texCoordAttrib = glGetAttribLocation(textureProgram, "aTexCoord");
    glEnableVertexAttribArray(texCoordAttrib);
    glVertexAttribPointer(texCoordAttrib, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));
}

void unbindBuffers() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

GLuint LoadTexture(const char* assetPath)
{
    FILE* file = fopen(assetPath, "rb");
    if (!file)
    {
        Log("Failed to open asset file: %s", assetPath);
        return 0;
    }

    fseek(file, 0, SEEK_END);
    long len_file = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char* buffer = (unsigned char*)malloc(len_file);
    if (!buffer)
    {
        Log("Failed to allocate memory for file: %s", assetPath);
        fclose(file);
        return 0;
    }

    fread(buffer, 1, len_file, file);
    fclose(file);

    upng_t* png = upng_new_from_bytes(buffer, len_file);
    if (png == NULL)
    {
        Log("Error creating PNG from file: %s", assetPath);
        free(buffer);
        return 0;
    }

    upng_decode(png);
    if (upng_get_error(png) != UPNG_EOK)
    {
        Log("Error decoding PNG from file: %s", assetPath);
        upng_free(png);
        free(buffer);
        return 0;
    }

    unsigned width = upng_get_width(png);
    unsigned height = upng_get_height(png);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, upng_get_buffer(png));

    upng_free(png);
    free(buffer);

    if (!texture)
    {
        Log("Error load texture '%s'", assetPath);
        return 0;
    }
    else
    {
        Log("Texture '%s' is loaded!", assetPath);
    }

    return texture;
}

void RenderTexture(GLuint texture, float x, float y, float width, float height) {
    glUseProgram(textureProgram);

    float normalized_x = (2.0f * x / WindowSizeX) - 1.0f;
    float normalized_y = 1.0f - (2.0f * y / WindowSizeY);
    float normalized_width = 2.0f * width / WindowSizeX;
    float normalized_height = 2.0f * height / WindowSizeY;

    GLfloat vertices[] = {
        normalized_x, normalized_y, 0.0f, 0.0f,
        normalized_x + normalized_width, normalized_y, 1.0f, 0.0f,
        normalized_x + normalized_width, normalized_y - normalized_height, 1.0f, 1.0f,
        normalized_x, normalized_y - normalized_height, 0.0f, 1.0f
    };

    GLuint indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    bindBuffers(vertices, sizeof(vertices), indices, sizeof(indices));

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glUniform1i(glGetUniformLocation(textureProgram, "uTexture"), 0);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    unbindBuffers();
}

void RenderTexturePro(GLuint texture, float x, float y, float width, float height, float angle) {
    glUseProgram(textureProgram);

    float angle_rad = angle * M_PI / 180.0f;
    float cos_angle = cos(angle_rad);
    float sin_angle = sin(angle_rad);

    float center_x = x + width / 2.0f;
    float center_y = y + height / 2.0f;

    float transform[4][4] = {
        {cos_angle, -sin_angle, 0.0f, center_x * (1.0f - cos_angle) + center_y * sin_angle},
        {sin_angle, cos_angle, 0.0f, center_y * (1.0f - cos_angle) - center_x * sin_angle},
        {0.0f, 0.0f, 1.0f, 0.0f},
        {0.0f, 0.0f, 0.0f, 1.0f}
    };

    GLfloat vertices[] = {
        x, y, 0.0f, 0.0f,
        x + width, y, 1.0f, 0.0f,
        x + width, y + height, 1.0f, 1.0f,
        x, y + height, 0.0f, 1.0f
    };

    for (int i = 0; i < 4; ++i) {
        float x = vertices[i * 4];
        float y = vertices[i * 4 + 1];
        vertices[i * 4] = transform[0][0] * x + transform[0][1] * y + transform[0][3];
        vertices[i * 4 + 1] = transform[1][0] * x + transform[1][1] * y + transform[1][3];
    }

    for (int i = 0; i < 4; ++i) {
        vertices[i * 4] = (2.0f * vertices[i * 4] / WindowSizeX) - 1.0f;
        vertices[i * 4 + 1] = 1.0f - (2.0f * vertices[i * 4 + 1] / WindowSizeY);
    }

    GLuint indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    bindBuffers(vertices, sizeof(vertices), indices, sizeof(indices));

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glUniform1i(glGetUniformLocation(textureProgram, "uTexture"), 0);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    unbindBuffers();
}

void CreateBox(uint32_t color, float posX, float posY, float width, float height)
{
    float normalizedPosX = (2.0f * posX / WindowSizeX) - 1.0f;
    float normalizedPosY = 1.0f - (2.0f * posY / WindowSizeY);
    float normalizedWidth = 2.0f * width / WindowSizeX;
    float normalizedHeight = 2.0f * height / WindowSizeY;

    float vertices[] = {
        normalizedPosX,                 normalizedPosY,
        normalizedPosX + normalizedWidth, normalizedPosY,
        normalizedPosX,                 normalizedPosY - normalizedHeight,
        normalizedPosX + normalizedWidth, normalizedPosY - normalizedHeight
    };

    glUseProgram(colorProgram);

    glVertexAttribPointer(gPositionHandle, 2, GL_FLOAT, GL_FALSE, 0, vertices);
    glEnableVertexAttribArray(gPositionHandle);

    float r = ((color >> 16) & 0xFF) / 255.0f;
    float g = ((color >> 8) & 0xFF) / 255.0f;
    float b = (color & 0xFF) / 255.0f;
    float a = ((color >> 24) & 0xFF) / 255.0f;

    glUniform4f(gColorHandle, r, g, b, a);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}