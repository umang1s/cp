/// this is escape sequence
#include<iostream>
using namespace std;
int main()
{
    cout<<"Alert(BEL)        (\\a)(07) zz\ayy\n";
    cout<<"Backspace         (\\b)(08) zz\byy\n";
    cout<<"Horizontal tab    (\\t)(09) zz\tyy\n";
    cout<<"Line feed         (\\n)(10) zz\nyy\n";
    cout<<"Vertical tab      (\\v)(11) zz\vyy\n";
    cout<<"Form feed         (\\f)(12) zz\fyy\n";
    cout<<"Carriage return   (\\r)(13) zz\ryy\n";
    cout<<"Double quote      (\")(34) zz\"yy\n";
    cout<<"singel quote      (\\')(39) zz\'yy\n";
    cout<<"question mark     (\\?)(63) zz\?yy\n";
    cout<<"back slash        (\\)(92) zz\\yy\n";
    cout<<"string terminating character (\\0)(0) zz\0yy\n";
    cout<<"octal             (\\ooo) zz\123yy\n";
    cout<<"hexa              (\\xhh) zz\xffyy\n";

}
