#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <ostream>
#include <vector>

#define POLY_SPLIT_EPS 1E-6

class Vector
{
public:
    double x, y, z;

    Vector(double x = 0.0f, double y = 0.0f, double z = 0.0f)
        : x(x), y(y), z(z) {}

    inline Vector operator-() const
    {
        return Vector(-x, -y, -z);
    }

    inline Vector &operator+=(const Vector &v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    inline Vector &operator-=(const Vector &v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    inline Vector &operator*=(double v)
    {
        x *= v;
        y *= v;
        z *= v;
        return *this;
    }

    inline Vector &operator/=(double v)
    {
        x /= v;
        y /= v;
        z /= v;
        return *this;
    }

    inline Vector operator-(const Vector &v) const
    {
        return Vector(x - v.x, y - v.y, z - v.z);
    }

    inline Vector operator+(const Vector &v) const
    {
        return Vector(x + v.x, y + v.y, z + v.z);
    }

    inline Vector operator*(const double v) const
    {
        return Vector(x * v, y * v, z * v);
    }

    inline Vector operator/(const double v) const
    {
        return Vector(x / v, y / v, z / v);
    }

    inline double dot(const Vector &v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }

    inline double length(void) const
    {
        return sqrt(x * x + y * y + z * z);
    }

    inline double squareLength(void) const
    {
        return x * x + y * y + z * z;
    }

    inline Vector norm(void) const
    {
        double l = length();
        if(l == 0)
            return Vector();
        else
            return Vector(x / l, y / l, z / l);
    }

    inline bool operator ==(const Vector &v) const
    {
        return x == v.x && y == v.y && z == v.z;
    }

    inline bool operator !=(const Vector &v) const
    {
        return fabs(x - v.x) >= POLY_SPLIT_EPS || fabs(y - v.y) >= POLY_SPLIT_EPS || fabs(z - v.z) >= POLY_SPLIT_EPS;
    }

    friend std::ostream& operator<< (std::ostream &out, const Vector &v)
    {
        out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return out;
    }

    /*Added the following angle() function to determine the angle for the polygon vertex.*/
    static double angle(const Vector &v2, const Vector &v1, const Vector &v3)
    {
        double dx21 = v2.x-v1.x;
        double dx31 = v3.x-v1.x;
        double dy21 = v2.y-v1.y;
        double dy31 = v3.y-v1.y;
        double m12 = sqrt( dx21*dx21 + dy21*dy21 );
        double m13 = sqrt( dx31*dx31 + dy31*dy31 );
        double theta = acos( (dx21*dx31 + dy21*dy31) / (m12 * m13) );
        return theta*180/M_PI;

    }
};

typedef std::vector<Vector> Vectors;
typedef std::vector<Vector>::iterator VectIter;
typedef std::vector<Vector>::const_iterator CVectIter;

#endif // VECTOR_H
