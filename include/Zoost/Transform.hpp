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
    // 
    ////////////////////////////////////////////////////////////
    Transform();

    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////
    Transform(double value);
    
    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////
    Transform(const std::array<double, 9>& values);
    
    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////
    void init();

    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////    
    Vector2d operator*(const Vector2d& vector);

    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////    
    Vector2d getMultiplication(const Vector2d& vector);

    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////    
    Transform operator*(const Transform& transformation);

    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////    
    Transform getMultiplication(const Transform& transformation);
 
    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////   
    Transform& operator*=(const Transform& transformation);

    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////    
    Transform& multiply(const Transform& transformation);

    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////    
    Transform& operator=(const Transform& transformation);

    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////    
    bool operator==(const Transform& transformation);

    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////    
    bool operator!=(const Transform& transformation);
 
    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////   
    double& operator[](Indice indice) const;
 
    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////   
    Transform getInverse();
  
    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////  
    double* getValues();
 
    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////   
    double getDeterminant();
    
    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////
    static Transform translation(double shiftX, double shiftY);
    
    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////
    static Transform translation(const Vector2d& shift);
    
    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////
    static Transform rotation(double angle, const Vector2d& origin = Vector2d(0, 0));
    
    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////
    static Transform scaling(double factorX, double factorY, const Vector2d& origin = Vector2d(0, 0));
    
    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////
    static Transform scaling(const Vector2d& factors, const Vector2d& origin = Vector2d(0, 0));
    
    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////
    static Transform reflection(bool axisX, bool axisY);
    
    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////
    static Transform shearing(double factorX, double factorY);
    
    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////
    static Transform shearing(const Vector2d& factors);
    
    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////
    void translate(double shiftX, double shiftY);
    
    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////
    void translate(const Vector2d& shift);
    
    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////
    void rotate(double angle, const Vector2d& origin = Vector2d(0, 0));
    
    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////
    void scale(double factorX, double factorY, const Vector2d& origin = Vector2d(0, 0));
    
    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////
    void scale(const Vector2d& factor, const Vector2d& origin = Vector2d(0, 0));
    
    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////
    void reflect(bool axisX, bool axisY);
    
    ////////////////////////////////////////////////////////////
    // 
    ////////////////////////////////////////////////////////////
    void shear(double factorX, double factorY);
    
    ////////////////////////////////////////////////////////////
    // 
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
