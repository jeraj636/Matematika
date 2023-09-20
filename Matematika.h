#pragma once

#include <iostream>
#include <iomanip>

namespace mat
{
    float rad(float deg);
    class mat3
    {
    public:
        mat3();
        mat3(float f);
        mat3 &operator=(mat3 &t_mat);
        mat3 &operator=(mat3 t_mat);
        float &DobiElement(int i, int j);
        mat3 operator*(mat3 &t_mat);
        mat3 operator*(float f);
        mat3 &operator*=(mat3 &t_mat);
        mat3 &operator*=(float f);
        friend std::ostream &operator<<(std::ostream &os, const mat3 &t_mat)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    os << std::setw(5) << t_mat.m_mat[i][j] << "   ";
                }
                os << '\n';
            }
            return os;
        }
        float m_mat[3][3];
    };
    class vec3
    {
    public:
        float x;
        float y;
        float z;
        vec3(float t_x, float t_y, float t_z);
        vec3(vec3 &t_vec);
        vec3(float t_x);
        vec3();
        vec3 &operator=(vec3 &t_vec);
        vec3 &operator=(float t_x);
        vec3 operator-(float t_x);
        vec3 operator-(vec3 &t_vec);
        vec3 operator+(float t_x);
        vec3 operator+(vec3 &t_vec);
        vec3 *Kazalec();
        vec3 &operator*=(mat3 t_mat);
        friend std::ostream &operator<<(std::ostream &os, const vec3 &t_vec)
        {
            os << std::setw(6) << t_vec.x << " " << std::setw(6) << t_vec.y << " " << std::setw(6) << t_vec.z << '\n';
            return os;
        }
    };
    class vec2
    {
    public:
        float x;
        float y;
        vec2(float t_x, float t_y);
        vec2(vec2 &t_vec);
        vec2();
        vec2 &operator=(vec2 t_vec);
        vec2 operator-(vec2 &t_vec);
        vec2 operator+(vec2 &t_vec);
        vec2 *Kazalec();
        friend std::ostream &operator<<(std::ostream &os, const vec2 &t_vec)
        {
            os << std::setw(6) << t_vec.x << " " << std::setw(6) << t_vec.y << '\n';
            return os;
        }
    };
    mat3 Vrtilna(float kot);
    mat3 velikostna(vec2 velikost);
    mat3 Premik(vec2 premik);
    mat3 Orto(float levo, float desno, float gor, float dol);

    namespace fun
    {
        namespace lin
        {
            float X(float k, float n, float y);
            float Y(float k, float n, float x);
            float K(vec2 A, vec2 B);
            float K(vec2 A, float n);

        }
    }

}
