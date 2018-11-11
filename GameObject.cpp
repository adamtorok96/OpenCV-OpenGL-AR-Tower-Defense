#include "GameObject.h"

GameObject::GameObject(GLuint modelId) {
    this->modelId = modelId;
}

GameObject::~GameObject() {
    glDeleteLists(modelId, 1);
}

void GameObject::setPosition(Detector * detector, const Vec3d &rvec, const Vec3d &tvec) {
    this->rvec = rvec;
    this->tvec = tvec;
    this->modelViewMatrix = detector->getModelViewMatrix(rvec, tvec);
}

void GameObject::draw() {
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixd(&modelViewMatrix.at<double>(0, 0));

    glCallList(modelId);
}

GLuint GameObject::load(const string filename) {
    tinyobj::attrib_t attrib;
    vector<tinyobj::shape_t> shapes;
    vector<tinyobj::material_t> materials;

    std::string warn_err;

    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn_err, &warn_err, filename.c_str());

    if( !ret) {
        return 0;
    }

    bool hasNormals = !attrib.normals.empty();
    bool hasTextureCoordinates = !attrib.texcoords.empty();
    bool hasColors = !attrib.colors.empty();

    GLuint modelId = glGenLists(1);

    glNewList(modelId, GL_COMPILE);

    for (auto &shape : shapes) {
        size_t index_offset = 0;

        for (size_t f = 0; f < shape.mesh.num_face_vertices.size(); f++) {
            int fv = shape.mesh.num_face_vertices[f];

            glBegin(GL_TRIANGLES);

            for (size_t v = 0; v < fv; v++) {
                tinyobj::index_t idx = shape.mesh.indices[index_offset + v];

                tinyobj::real_t vx = attrib.vertices[3 * idx.vertex_index + 0];
                tinyobj::real_t vy = attrib.vertices[3 * idx.vertex_index + 1];
                tinyobj::real_t vz = attrib.vertices[3 * idx.vertex_index + 2];
                tinyobj::real_t nx = attrib.normals[3 * idx.normal_index + 0];
                tinyobj::real_t ny = attrib.normals[3 * idx.normal_index + 1];
                tinyobj::real_t nz = attrib.normals[3 * idx.normal_index + 2];

                tinyobj::real_t tx = attrib.texcoords[2 * idx.texcoord_index + 0];
                tinyobj::real_t ty = attrib.texcoords[2 * idx.texcoord_index + 1];

                tinyobj::real_t red = attrib.colors[3 * idx.vertex_index + 0];
                tinyobj::real_t green = attrib.colors[3 * idx.vertex_index + 1];
                tinyobj::real_t blue = attrib.colors[3 * idx.vertex_index + 2];

                if( hasColors )
                    glColor3f(red, green, blue);

                if( hasTextureCoordinates )
                    glTexCoord2f(tx, ty);

                if( hasNormals )
                    glNormal3f(nx, ny, nz);

                glVertex3f(vx, vy, vz);
            }

            glEnd();

            index_offset += fv;

            shape.mesh.material_ids[f];
        }
    }

    glEndList();

    return modelId;
}
