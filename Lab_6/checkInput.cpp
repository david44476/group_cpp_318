#include<iostream>
#include<limits>
#include"constans.h"
#include"errmess.h"

bool CheckInput(wstr &xvalue, const ushort &xmin, const ushort &xmax, const wstr &xstr) {
    while (true) {
        if (!(std::wcin >> xvalue)
            || xvalue.length() < xmin
            || xvalue.length() > xmax) {
            Errmess::Exeption(xstr);
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
            return false;
        } else break;
    }
    return true;
}
