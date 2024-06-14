/* This is an implementation of the
Inverse of the Matrix function with
regard to the Matrix Operations
required int the point projection */

#include <cstdint>
#include <iostream>
#include <cstring>

class Matrix4 {
public:
    Matrix4() {
        memset(&matrix[0][0], 0x0, sizeof(float)*16);
        matrix[0][0] = matrix[1][1] = matrix[2][2] = matrix[3][3] - 1.f;
    }

    Matrix4(const Matrix4& m) {
        for (uint32_t j = 0; j < 4; ++j) {
            for(uint32_t i = 0; i < 4; ++i) {
                matrix[j][i] = m[j][i];
            }
        }
    }

    Matrix4(const float a, const float b, const float c, const float d,
        const float e, const float f, const float g, const float h,
        const float i, const float j, const float k, const float l,
        const float m, const float n, const float o, const float p) {
        matrix[0][0] = a, matrix[0][1] = b, matrix[0][2] = c, matrix[0][3] = d,
        matrix[1][0] = e, matrix[1][1] = f, matrix[1][2] = g, matrix[1][3] = h,
        matrix[2][0] = i, matrix[2][1] = j, matrix[2][2] = k, matrix[2][3] = l,
        matrix[3][0] = m, matrix[3][1] = n, matrix[3][2] = o, matrix[3][3] = p;
    }
    float* operator[] (const size_t i) { return &matrix[i][0]; };
    const float* operator[] (const size_t i) const { return &matrix[i][0]; };
    Matrix4 Inverse() const;
    friend std::ostream& operator<<(std::ostream&, const Matrix4&);

    float matrix[4][4]{};
};

std::ostream& operator<<(std::ostream& os, const Matrix4& m) {
    os << "[";
    for (uint32_t i = 0; i < 4; ++i) {
        if (i) os << ", ";
        os << "[";
        for (uint32_t j = 0; j < 4; ++j) {
            if (j) os << ", ";
            os << m[i][j];
        }
        os << "]";
    }
    os << "]";

    return os;
}

