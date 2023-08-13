#ifndef MATEMATIKA_H
#define MATEMATIKA_H

#include "cmath"
#include <iostream>
#include <iomanip>

namespace mat
{
    float rad(float deg)
    {
        return (deg * 3.14) / 180;
    }
    class mat3
    {
    public:
        mat3()
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                    m_mat[i][j] = 0;
            }
        }
        mat3(float f)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                    m_mat[i][j] = 0;
            }
            for (int i = 0; i < 3; i++)
            {
                m_mat[i][i] = f;
            }
        }
        mat3 &operator=(mat3 &t_mat)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    m_mat[i][j] = t_mat.m_mat[i][j];
                }
            }
            return *this;
        }
        float &DobiElement(int i, int j)
        {
            return m_mat[i][j];
        }
        mat3 operator*(mat3 &t_mat)
        {
            mat3 produkt;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        produkt.m_mat[i][j] += this->m_mat[i][k] * t_mat.m_mat[k][j];
                    }
                }
            }
            return produkt;
        }
        mat3 operator*(float f)
        {
            mat3 produkt;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    produkt.m_mat[i][j] = this->m_mat[i][j] * f;
                }
            }
            return produkt;
        }
        mat3 &operator*=(mat3 &t_mat)
        {
            mat3 produkt;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        produkt.m_mat[i][j] += this->m_mat[i][k] * t_mat.m_mat[k][j];
                    }
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    this->m_mat[i][j] = produkt.m_mat[i][j];
                }
            }
            return *this;
        }
        mat3 &operator*=(float f)
        {
            mat3 produkt;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    produkt.m_mat[i][j] = this->m_mat[i][j] * f;
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    this->m_mat[i][j] = produkt.m_mat[i][j];
                }
            }
            return *this;
        }
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
        vec3(float t_x, float t_y, float t_z)
        {
            x = t_x;
            y = t_y;
            z = t_z;
        }
        vec3(vec3 &t_vec)
        {
            x = t_vec.x;
            y = t_vec.y;
            z = t_vec.z;
        }
        vec3(float t_x)
        {
            x = t_x;
            y = t_x;
            z = t_x;
        }
        vec3 &operator=(vec3 &t_vec)
        {
            this->x = t_vec.x;
            this->y = t_vec.y;
            this->z = t_vec.z;
            return *this;
        }
        vec3 &operator=(vec3 t_vec)
        {
            this->x = t_vec.x;
            this->y = t_vec.y;
            this->z = t_vec.z;
            return *this;
        }
        vec3 &operator=(float t_x)
        {
            this->x = t_x;
            this->y = t_x;
            this->z = t_x;
            return *this;
        }
        vec3 &operator-(float t_x)
        {
            this->x - t_x;
            this->y - t_x;
            this->z - t_x;
            return *this;
        }
        vec3 &operator-(vec3 &t_vec)
        {
            this->x - t_vec.x;
            this->y - t_vec.y;
            this->z - t_vec.z;
            return *this;
        }
        vec3 &operator+(float t_x)
        {
            this->x + t_x;
            this->y + t_x;
            this->z + t_x;
            return *this;
        }
        vec3 &operator+(vec3 &t_vec)
        {
            this->x + t_vec.x;
            this->y + t_vec.y;
            this->z + t_vec.z;
            return *this;
        }
        vec3 *Kazalec()
        {
            return this;
        }
        vec3 &operator*=(mat3 t_mat)
        {
            vec3 produkt(0);
            produkt.x = x * t_mat.DobiElement(0, 0) + y * t_mat.DobiElement(0, 1) + z * t_mat.DobiElement(0, 2);
            produkt.y = x * t_mat.DobiElement(1, 0) + y * t_mat.DobiElement(1, 1) + z * t_mat.DobiElement(1, 2);
            produkt.z = x * t_mat.DobiElement(2, 0) + y * t_mat.DobiElement(2, 1) + z * t_mat.DobiElement(2, 2);
            x = produkt.x;
            y = produkt.y;
            z = produkt.z;
            return *this;
        }
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
        vec2(float t_x, float t_y)
        {
            x = t_x;
            y = t_y;
        }
        vec2(vec2 &t_vec)
        {
            x = t_vec.x;
            y = t_vec.y;
        }
        vec2(float t_x)
        {
            x = t_x;
            y = t_x;
        }
        vec2 &operator=(vec2 &t_vec)
        {
            this->x = t_vec.x;
            this->y = t_vec.y;
            return *this;
        }
        vec2 &operator=(vec2 t_vec)
        {
            this->x = t_vec.x;
            this->y = t_vec.y;
            return *this;
        }
        vec2 &operator=(float t_x)
        {
            this->x = t_x;
            this->y = t_x;
            return *this;
        }
        vec2 &operator-(float t_x)
        {
            this->x - t_x;
            this->y - t_x;
            return *this;
        }
        vec2 &operator-(vec2 &t_vec)
        {
            this->x - t_vec.x;
            this->y - t_vec.y;
            return *this;
        }
        vec2 &operator+(float t_x)
        {
            this->x + t_x;
            this->y + t_x;
            return *this;
        }
        vec2 &operator+(vec2 &t_vec)
        {
            this->x + t_vec.x;
            this->y + t_vec.y;
            return *this;
        }
        vec2 *Kazalec()
        {
            return this;
        }
        friend std::ostream &operator<<(std::ostream &os, const vec2 &t_vec)
        {
            os << std::setw(6) << t_vec.x << " " << std::setw(6) << t_vec.y << '\n';
            return os;
        }
    };

    mat3 Vrtilna(float kot)
    {
        mat3 temp(1);
        temp.m_mat[0][0] = cos(kot);
        temp.m_mat[0][1] = -sin(kot);
        temp.m_mat[1][0] = sin(kot);
        temp.m_mat[1][1] = cos(kot);
        std::cout << "ROT:\n"
                  << temp;
        return temp;
    }
    mat3 velikostna(vec2 velikost)
    {
        mat3 temp(1);
        temp.m_mat[0][0] = velikost.x;
        temp.m_mat[1][1] = velikost.y;
        // temp.m_mat[2][2] = velikost.z;
        std::cout << "velikostna:\n"
                  << temp;
        return temp;
    }
    mat3 Premik(vec2 premik)
    {
        mat3 temp(1);
        temp.m_mat[0][2] = premik.x;
        temp.m_mat[1][2] = premik.y;
        // temp.m_mat[2][2] = premik.z;

        std::cout << "PREMIK:\n"
                  << temp;
        return temp;
    }
    mat3 Orto(float levo, float desno, float gor, float dol)
    {
        mat3 temp(1);
        temp.m_mat[0][0] = 2 / (desno - levo);
        temp.m_mat[1][1] = 2 / (gor - dol);
        temp.m_mat[0][2] = -(desno + levo) / (desno - levo);
        temp.m_mat[1][2] = -(gor + dol)(gor - dol);
        return temp;
    }
}
#endif