#include "_duty.h"

QString char2hex(char c, bool toUpper, bool add0x)
{
    QString s = "";
    int d = 0;
    memcpy(&d, &c, 1);

    s.setNum(d, 16);
    if(s.length() == 1) s = '0' + s;

    return (add0x ? "0x" : "") + (toUpper ? s.toUpper() : s) + " ";

}
