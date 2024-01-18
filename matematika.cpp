#include "matematika.h"
#include <cmath>

float mat::rad(float deg)
{
    return (deg * 3.14) / 180;
}

mat::mat::mat3::mat3()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            m_mat[i][j] = 0;
    }
}
mat::mat::mat3::mat3(float f)
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
mat::mat::mat3 &mat::mat::mat3::operator=(const mat::mat3 &t_mat)
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

float &mat::mat::mat3::DobiElement(int i, int j)
{
    return m_mat[i][j];
}
mat::mat::mat3 mat::mat::mat3::operator*(const mat3 &t_mat) const
{
    mat3 produkt;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                produkt.m_mat[i][j] += m_mat[i][k] * t_mat.m_mat[k][j];
            }
        }
    }
    return produkt;
}
mat::mat::mat3 &mat::mat::mat3::operator*=(const mat3 &t_mat)
{
    mat3 produkt;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                produkt.m_mat[i][j] += m_mat[i][k] * t_mat.m_mat[k][j];
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            m_mat[i][j] = produkt.m_mat[i][j];
        }
    }
    return *this;
}
mat::vec3::vec3(float t_x, float t_y, float t_z)
{
    x = t_x;
    y = t_y;
    z = t_z;
}
mat::vec3::vec3(const vec3 &t_vec)
{
    x = t_vec.x;
    y = t_vec.y;
    z = t_vec.z;
}
mat::vec3::vec3()
{
    x = 0;
    y = 0;
    z = 0;
}
mat::vec3 &mat::vec3::operator=(const vec3 &t_vec)
{
    x = t_vec.x;
    y = t_vec.y;
    z = t_vec.z;
    return *this;
}
mat::vec3 mat::vec3::operator-(const vec3 &t_vec) const
{
    vec3 t(x - t_vec.x, y - t_vec.y, z - t_vec.z);
    return t;
}
mat::vec3 mat::vec3::operator+(const vec3 &t_vec) const
{
    vec3 t(x + t_vec.x, y + t_vec.y, z + t_vec.z);
    return t;
}
mat::vec3 *mat::vec3::Kazalec()
{
    return this;
}

mat::vec3 &mat::vec3::operator*=(const mat::mat3 &t_mat)
{
    vec3 produkt(0, 0, 0);
    produkt.x = x * t_mat.m_mat[0][0] + y * t_mat.m_mat[0][1] + z * t_mat.m_mat[0][2];
    produkt.y = x * t_mat.m_mat[1][0] + y * t_mat.m_mat[1][1] + z * t_mat.m_mat[1][2];
    produkt.z = x * t_mat.m_mat[2][0] + y * t_mat.m_mat[2][1] + z * t_mat.m_mat[2][2];
    x = produkt.x;
    y = produkt.y;
    z = produkt.z;
    return *this;
}
mat::vec3 mat::vec3::operator*(const mat::mat3 &t_mat) const
{
    vec3 produkt(0, 0, 0);
    produkt.x = x * t_mat.m_mat[0][0] + y * t_mat.m_mat[0][1] + z * t_mat.m_mat[0][2];
    produkt.y = x * t_mat.m_mat[1][0] + y * t_mat.m_mat[1][1] + z * t_mat.m_mat[1][2];
    produkt.z = x * t_mat.m_mat[2][0] + y * t_mat.m_mat[2][1] + z * t_mat.m_mat[2][2];
    return produkt;
}

mat::vec2::vec2(float t_x, float t_y)
{
    x = t_x;
    y = t_y;
}
mat::vec2::vec2(const vec2 &t_vec)
{
    x = t_vec.x;
    y = t_vec.y;
}
mat::vec2::vec2()
{
    x = 0;
    y = 0;
}
mat::vec2 &mat::vec2::operator=(const vec2 &t_vec)
{
    this->x = t_vec.x;
    this->y = t_vec.y;
    return *this;
}
mat::vec2 mat::vec2::operator-(const vec2 &t_vec) const
{
    vec2 t;
    t.x = x - t_vec.x;
    t.y = y - t_vec.y;
    return t;
}
mat::vec2 &mat::vec2::operator-=(const vec2 &t_vec)
{
    x -= t_vec.x;
    y -= t_vec.y;
    return *this;
}
mat::vec2 mat::vec2::operator+(const vec2 &t_vec) const
{
    vec2 t(x + t_vec.x, y + t_vec.y);
    return t;
}
mat::vec2 *mat::vec2::Kazalec()
{
    return this;
}

void mat::mat::Vrtilna(float kot, mat::mat3 &temp)
{
    // mat3 temp(1);
    temp.m_mat[0][0] = cos(kot);
    temp.m_mat[0][1] = -sin(kot);
    temp.m_mat[1][0] = sin(kot);
    temp.m_mat[1][1] = cos(kot);

    // return temp;
}
void mat::mat::velikostna(const vec2 &velikost, mat::mat3 &temp)
{
    // mat3 temp(1);
    temp.m_mat[0][0] = velikost.x;
    temp.m_mat[1][1] = velikost.y;
    // temp.m_mat[2][2] = velikost.z;
    temp.m_mat[2][2] = 1;
    // return temp;
}
void mat::mat::Premik(const vec2 &premik, mat::mat3 &temp)
{

    temp.m_mat[0][2] = premik.x;
    temp.m_mat[1][2] = premik.y;
    // temp.m_mat[2][2] = premik.z;

    // return temp;
}
void mat::mat::Orto(float levo, float desno, float gor, float dol, mat::mat3 &temp)
{

    temp.m_mat[0][0] = 2 / (desno - levo);
    temp.m_mat[1][1] = 2 / (gor - dol);
    temp.m_mat[0][2] = -(desno + levo) / (desno - levo);
    temp.m_mat[1][2] = -(gor + dol) / (gor - dol);
}
float mat::fun::lin::X(float k, float n, float y)
{
    return (y - n) / k;
}
float mat::fun::lin::Y(float k, float n, float x)
{
    return k * x + n;
}
float mat::fun::lin::K(const vec2 &A, const vec2 &B)
{
    // vec2 C = A - B;
    vec2 C;
    C = A - B;
    return C.y / C.x;
}
float mat::fun::lin::K(const vec2 &A, float n)
{
    return (A.y - n) / A.x;
}
float mat::fun::lin::K(const vec3 &A, const vec3 &B)
{
    // vec2 C = A - B;
    vec3 C;
    C = A - B;
    return C.y / C.x;
}
float mat::fun::lin::K(const vec3 &A, float n)
{
    return (A.y - n) / A.x;
}
float mat::fun::lin::N(float k, const vec2 &A)
{
    return A.y - k * A.x;
}
float mat::fun::lin::N(const vec2 &A, const vec2 &B)
{
    float k = fun::lin::K(A, B);
    return fun::lin::N(k, A);
}
float mat::fun::lin::N(float k, const vec3 &A)
{
    return A.y - k * A.x;
}
float mat::fun::lin::N(const vec3 &A, const vec3 &B)
{
    float k = fun::lin::K(A, B);
    return fun::lin::N(k, A);
}