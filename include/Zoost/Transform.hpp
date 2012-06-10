////////////////////////////////////////////////////////////
//
// Zoost C++ library
// Copyright (C) 2011-2012 ZinLibs (zinlibs@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef ZOOST_TRANSFORM_HPP
#define ZOOST_TRANSFORM_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <array>
#include <Zoost/Vector2.hpp>
#include <Zoost/Config.hpp>

namespace zin
{
    
typedef unsigned int Indice;

class ZOOST_API Transform
{
public:

    ////////////////////////////////////////////////////////////
    // Default constructor
    ////////////////////////////////////////////////////////////
    Transform();

    ////////////////////////////////////////////////////////////
    // Constructor
    ////////////////////////////////////////////////////////////
    Transform(double value);
    
    ////////////////////////////////////////////////////////////
    // Constructor
    ////////////////////////////////////////////////////////////
    Transform(const std::array<double, 9>& values);
    
    ////////////////////////////////////////////////////////////
    // Init the transformation
    ////////////////////////////////////////////////////////////
    void init();

    ////////////////////////////////////////////////////////////
    // Multiply a vector by the transform
    ////////////////////////////////////////////////////////////    
    Vector2d operator*(const Vector2d& vector);

    ////////////////////////////////////////////////////////////
    // Get the multiplication by the vector result
    ////////////////////////////////////////////////////////////    
    Vector2d getMultiplication(const Vector2d& vector);

    ////////////////////////////////////////////////////////////
    // Get the multiplication by the given transformation
    ////////////////////////////////////////////////////////////    
    Transform operator*(const Transform& transformation);

    ////////////////////////////////////////////////////////////
    // Get the multiplication by the given transformation
    ////////////////////////////////////////////////////////////    
    Transform getMultiplication(const Transform& transformation);
 
    ////////////////////////////////////////////////////////////
    // Multiply the current transform by another transform
    ////////////////////////////////////////////////////////////   
    Transform& operator*=(const Transform& transformation);

    ////////////////////////////////////////////////////////////
    // Multiply the current transform by another transform
    ////////////////////////////////////////////////////////////    
    Transform& multiply(const Transform& transformation);

    ////////////////////////////////////////////////////////////
    // Assign operator
    ////////////////////////////////////////////////////////////    
    Transform& operator=(const Transform& transformation);

    ////////////////////////////////////////////////////////////
    // Return true if the two transformations are equal
    ////////////////////////////////////////////////////////////    
    bool operator==(const Transform& transformation);

    ////////////////////////////////////////////////////////////
    // Return true if the two transformations are inequal
    ////////////////////////////////////////////////////////////    
    bool operator!=(const Transform& transformation);
 
    ////////////////////////////////////////////////////////////
    // Get the value of the matrix matching to the given indice
    ////////////////////////////////////////////////////////////   
    double& operator[](Indice indice) const;
 
    ////////////////////////////////////////////////////////////
    // Get the inverse transform
    ////////////////////////////////////////////////////////////   
    Transform getInverse();
  
    ////////////////////////////////////////////////////////////
    // Get the matrix values
    ////////////////////////////////////////////////////////////  
    double* getValues();
 
    ////////////////////////////////////////////////////////////
    // Get the determinant
    ////////////////////////////////////////////////////////////   
    double getDeterminant();
    
    ////////////////////////////////////////////////////////////
    // Get a translation matrix
    ////////////////////////////////////////////////////////////
    static Transform translation(double shiftX, double shiftY);
    
    ////////////////////////////////////////////////////////////
    // Get a translation matrix
    ////////////////////////////////////////////////////////////
    static Transform translation(const Vector2d& shift);
    
    ////////////////////////////////////////////////////////////
    // Get a rotation matrix
    ////////////////////////////////////////////////////////////
    static Transform rotation(double angle, const Vector2d& origin = Vector2d(0, 0));
    
    ////////////////////////////////////////////////////////////
    // Get a scaling matrix
    ////////////////////////////////////////////////////////////
    static Transform scaling(double factorX, double factorY, const Vector2d& origin = Vector2d(0, 0));
    
    ////////////////////////////////////////////////////////////
    // Get a scaling matrix
    ////////////////////////////////////////////////////////////
    static Transform scaling(const Vector2d& factors, const Vector2d& origin = Vector2d(0, 0));
    
    ////////////////////////////////////////////////////////////
    // Get a reflection matrix
    ////////////////////////////////////////////////////////////
    static Transform reflection(bool axisX, bool axisY);
    
    ////////////////////////////////////////////////////////////
    // Get a shearing matrix
    ////////////////////////////////////////////////////////////
    static Transform shearing(double factorX, double factorY);
    
    ////////////////////////////////////////////////////////////
    // Get a shearing matrix
    ////////////////////////////////////////////////////////////
    static Transform shearing(const Vector2d& factors);
    
    ////////////////////////////////////////////////////////////
    // Apply a translation to the current transform
    ////////////////////////////////////////////////////////////
    void translate(double shiftX, double shiftY);
    
    ////////////////////////////////////////////////////////////
    // Apply a translation to the current transform
    ////////////////////////////////////////////////////////////
    void translate(const Vector2d& shift);
    
    ////////////////////////////////////////////////////////////
    // Apply a rotation to the current transform
    ////////////////////////////////////////////////////////////
    void rotate(double angle, const Vector2d& origin = Vector2d(0, 0));
    
    ////////////////////////////////////////////////////////////
    // Apply a scaling to the current transform
    ////////////////////////////////////////////////////////////
    void scale(double factorX, double factorY, const Vector2d& origin = Vector2d(0, 0));
    
    ////////////////////////////////////////////////////////////
    // Apply a scaling to the current transform
    ////////////////////////////////////////////////////////////
    void scale(const Vector2d& factor, const Vector2d& origin = Vector2d(0, 0));
    
    ////////////////////////////////////////////////////////////
    // Apply a reflection to the current transform
    ////////////////////////////////////////////////////////////
    void reflect(bool axisX, bool axisY);
    
    ////////////////////////////////////////////////////////////
    // Apply a shearing to the current transform
    ////////////////////////////////////////////////////////////
    void shear(double factorX, double factorY);
    
    ////////////////////////////////////////////////////////////
    // Apply a shearing to the current transform
    ////////////////////////////////////////////////////////////
    void shear(const Vector2d& factors);
    
private:

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////   
    mutable std::array<double, 9> m_values;
};

}

#endif // ZOOST_TRANSFORM_HPP
