// https://en.cppreference.com/w/cpp/language/sizeof

// sizeof returns object size in bytes.
// 1 byte = 8 bits (may be more, depends on architecture)



#include <iostream>
#include <memory>

class Empty{};
class Charr{char c;};
class Intt{int i;};
class CharInt{char c; int i;};
class CharIntVirt{char c; int i; virtual void foo()=0;};
class CharIntVirtVirt{char c; int i; virtual void foo()=0; virtual void bar()=0;};
class CharCharInt{char c1; char c2; int i;};
class CharIntChar{char c1; int i; char c2;};
class IntCharChar{int i; char c1; char c2;};

int main(){
    int t[10];
    int* p=t;
    Empty e;
    Charr c;
    Intt i;
    CharInt ci;
    std::unique_ptr<int> upi;
    std::shared_ptr<int> spi;
    
    
    std::cout<<"sizeof:\n"
    <<" 1. char:                    "<<sizeof(char)             <<"\n" // 1
    <<" 2. short int:               "<<sizeof(short)            <<"\n" // 2
    <<" 3. int:                     "<<sizeof(int)              <<"\n" // 4
    <<" 4. long int:                "<<sizeof(long)             <<"\n" // 8
    <<" 5. long long int:           "<<sizeof(long long)        <<"\n" // 8 -> to investigate 
    <<" 6. int64_t:                 "<<sizeof(int64_t)          <<"\n" // 8 -> to investigate
    <<" 7. double:                  "<<sizeof(double)           <<"\n" // 8
    <<" 8. pointer:                 "<<sizeof(p)                <<"\n" // 8
    <<" 9. class Empty:             "<<sizeof(e)                <<"\n" // 1
    <<"10. class Charr:             "<<sizeof(c)                <<"\n" // 1
    <<"11. class Intt:              "<<sizeof(i)                <<"\n" // 4
    <<"12. class CharInt:           "<<sizeof(ci)               <<"\n" // 8
    <<"13. class CharIntVirt:       "<<sizeof(CharIntVirt)      <<"\n" // 16
    <<"14. class CharIntVirtVirt:   "<<sizeof(CharIntVirtVirt)  <<"\n" // 16
    <<"15. std::unique_ptr<int>:    "<<sizeof(upi)              <<"\n" // 8
    <<"16. std::shared_ptr<int>:    "<<sizeof(spi)              <<"\n" // 16
    <<"17. CharCharInt:             "<<sizeof(CharCharInt)      <<"\n" // 8
    <<"18. IntCharChar:             "<<sizeof(IntCharChar)      <<"\n" // 8
    <<"19. CharIntChar:             "<<sizeof(CharIntChar)      <<"\n" // 12
    <<"20. bool:                    "<<sizeof(bool)             <<"\n" // 1
    <<"21: int t[10];               "<<sizeof(t)                <<"\n" // 40
    <<"22. t/t[0]:                  "<<sizeof(t)/sizeof(t[0])   <<"\n" // 10
    ;
}
