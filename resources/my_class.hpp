/**
 *  File        :   my_class.hpp
 *  Explain     :   Example resource file
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   26.10.2020
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/

#ifndef MYCLASS_HPP
#define MYCLASS_HPP

#include <iostream>

class MyClass
{
public:
    void hello();
};


void MyClass::hello() 
{
    std::cout << "Hello Everyone :)" << std::endl;
}



#endif //  MYCLASS_HPP