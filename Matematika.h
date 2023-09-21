#pragma once

#include <iostream>
#include <iomanip>

namespace mat
{
    float rad(float deg);
    namespace mat
    {
        class mat3
        {
        public:
            mat3();
            mat3(float f);
            mat3 &operator=(const mat3 &t_mat);
            float &DobiElement(int i, int j);
            mat3 operator*(const mat3 &t_mat) const;
            mat3 &operator*=(const mat3 &t_mat);
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
    }
    class vec3
    {
    public:
        float x;
        float y;
        float z;
        vec3(float t_x, float t_y, float t_z);
        vec3(const vec3 &t_vec);
        vec3();
        vec3 &operator=(const vec3 &t_vec);
        vec3 operator-(const vec3 &t_vec) const;
        vec3 operator+(const vec3 &t_vec) const;
        vec3 &operator*=(const mat::mat3 &t_mat);
        vec3 operator*(const mat::mat3 &t_mat) const;
        vec3 *Kazalec();
        // vec3 &operator*=(const mat::mat3 &t_mat);
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
        vec2(const vec2 &t_vec);
        vec2();
        vec2 &operator=(const vec2 &t_vec);
        vec2 operator-(const vec2 &t_vec) const;
        vec2 &operator-=(const vec2 &t_vec);
        vec2 operator+(const vec2 &t_vec) const;
        vec2 operator+=(const vec2 &t_vec);
        vec2 *Kazalec();
        friend std::ostream &operator<<(std::ostream &os, const vec2 &t_vec)
        {
            os << std::setw(6) << t_vec.x << " " << std::setw(6) << t_vec.y << '\n';
            return os;
        }
    };
    namespace mat
    {
        void Vrtilna(float kot, mat3 &temp);
        void velikostna(const vec2 &velikost, mat3 &temp);
        void Premik(const vec2 &premik, mat3 &temp);
        void Orto(float levo, float desno, float gor, float dol, mat3 &temp);
    }

    namespace fun
    {
        namespace lin
        {
            float X(float k, float n, float y);
            float Y(float k, float n, float x);
            float K(const vec2 &A, const vec2 &B);
            float K(const vec2 &A, float n);
            float K(const vec3 &A, const vec3 &B);
            float K(const vec3 &A, float n);
            float N(float k, const vec2 &A);
            float N(const vec2 &A, const vec2 &B);
            float N(float k, const vec3 &A);
            float N(const vec3 &A, const vec3 &B);

        }
    }

}
