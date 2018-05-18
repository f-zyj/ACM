#include <iostream>

int main()
{
    //华氏度 ＝＝ 摄氏度 ＊ 9.0 ／ 5.0 ＋ 32；
    const unsigned short ADD_SUBTRACT = 32;
    const double RATIO = 9.0 / 5.0;

    double tempIn, tempOut;
    char typeIn, typeOut;

    std::cout << "请输入一个摄氏度" << std::endl;
    std::cin >> tempIn >> typeIn;
    std::cin.ignore(10, '\n');
    //std::cout << "\n";

    int a = 5;
    int *p;
    *p = a;
    std::cout << "&a = " <<  &a << std::endl;
    std::cout << "p = " << p << std::endl;
    std::cout << "*p = " << *p << std::endl;
    switch(typeIn)
    {
        case 'C':
        case 'c':
            tempOut = tempIn * RATIO + ADD_SUBTRACT;
            typeOut = 'F';
            typeIn = 'C';
            break;
        case 'F':
        case 'f':
            tempOut = (tempIn - ADD_SUBTRACT) / RATIO;
            typeOut = 'C';
            typeIn = 'F';
            break;
        default:
            typeOut = 'E';
            break;
    }

    if (typeOut != 'E')
    {
        std::cout << tempIn << typeIn << "=" << tempOut << typeOut  << '\n';
    }
    else
    {
        std::cout << "错误的输入！" << std::endl;
    }

    return 0;
}
