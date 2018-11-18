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

GLuint GameObject::load(const string & filename, Vec3d translate, Vec3d rotate, Vec3d scale) {
    tinyobj::attrib_t attrib;
    vector<tinyobj::shape_t> shapes;
    vector<tinyobj::material_t> materials;

    std::string err, warn;

    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, filename.c_str());

    if( !ret) {
        return 0;
    }

    bool hasNormals = !attrib.normals.empty();
    bool hasTextureCoordinates = !attrib.texcoords.empty();
    bool hasColors = !attrib.colors.empty();

    tinyobj::real_t
        vx, vy, vz,
        nx, ny, nz,
        tx, ty,
        red, green, blue;

    GLuint modelId = glGenLists(1);

    glNewList(modelId, GL_COMPILE);

    glDisable(GL_TEXTURE_2D);

    glTranslated(translate[0], translate[1], translate[2]);
    glRotated(1.0f, rotate[0], rotate[1], rotate[2]);
    glScaled(scale[0], scale[1], scale[2]);

    for (auto &shape : shapes) {
        size_t index_offset = 0;

        for (size_t f = 0; f < shape.mesh.num_face_vertices.size(); f++) {
            int fv = shape.mesh.num_face_vertices[f];

            glBegin(GL_TRIANGLES);

            for (size_t v = 0; v < fv; v++) {
                tinyobj::index_t idx = shape.mesh.indices[index_offset + v];

                if( hasNormals ) {
                    nx = attrib.normals[3 * idx.normal_index + 0];
                    ny = attrib.normals[3 * idx.normal_index + 1];
                    nz = attrib.normals[3 * idx.normal_index + 2];

                    glNormal3f(nx, ny, nz);
                }

                if( hasTextureCoordinates ) {
                    tx = attrib.texcoords[2 * idx.texcoord_index + 0];
                    ty = attrib.texcoords[2 * idx.texcoord_index + 1];

                    glTexCoord2f(tx, ty);
                }

                if( hasColors ) {
                    red = attrib.colors[3 * idx.vertex_index + 0];
                    green = attrib.colors[3 * idx.vertex_index + 1];
                    blue = attrib.colors[3 * idx.vertex_index + 2];

                    glColor3f(red, green, blue);
                }

                vx = attrib.vertices[3 * idx.vertex_index + 0];
                vy = attrib.vertices[3 * idx.vertex_index + 1];
                vz = attrib.vertices[3 * idx.vertex_index + 2];

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
