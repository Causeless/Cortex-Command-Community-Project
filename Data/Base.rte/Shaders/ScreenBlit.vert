#version 330 core

layout(location = 0) in vec2 rteVertexPosition;
layout(location = 1) in vec2 rteTexUV;

out vec2 textureUV;

uniform mat4 rteTransform;
uniform mat4 rteProjection;

void main() {
	gl_Position = rteProjection * rteTransform * vec4(rteVertexPosition.xy, 0.0, 1.0);
	textureUV = rteTexUV;
}
