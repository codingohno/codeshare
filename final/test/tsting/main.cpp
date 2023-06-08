#include <iostream>
#include <cmath>

template<typename T,class Func>
void ForEach(T _begin,T _end, Func _func){
    for(;_begin != _end;_begin++){
        _func(*_begin);
    }
};

struct Power {
    int exp=2;
    void operator() (int & base){
        base=std::pow(base,exp);
    }
};

int main(void){
    int A[]={1,2,3,4,5};
    ForEach(A,A+5,Power());
    for(int i=0;i<5;i++){
        std::cout<<A[i]<<std::endl;
    }
    return 0;
}
