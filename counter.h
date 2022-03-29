//          using templates
template<class variableType>
class counter
{
    public : counter(variableType N=0) {data=N;}
             void increament () { data++;}
             variableType getValue() {return data;}
    private : variableType data;
};

// usinginheritance properties
 template<class type>   // here type is use like a parameter
 class general_counter : public counters<type>
 {
     public: general_counter(type N=0) : counters(N) {}
             void setcounter(type N=0) {data = N;}
             void decreament () {data --;}
 };
