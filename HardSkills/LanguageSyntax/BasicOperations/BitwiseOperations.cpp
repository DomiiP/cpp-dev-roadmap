// https://en.cppreference.com/w/cpp/language/operator_arithmetic

// NOT ~
// AND &
// OR |
// XOR ^
// left shift <<
// right shift >>

#include <iostream>
#include <bitset>


int main()
{
    std::cout<<"Bitwise Operations\n";

    uint8_t mask = 0b00000101; // 0b from C++14
    std::cout<<"mask: "<<mask<<"\n";
    // It displays:
    // > mask:
    // Value 5 is non-printable ASCII sign.
    // To display numeric value it has to be casted to int.
    std::cout<<"mask: "<<static_cast<int>(mask)<<"\n";
    // > mask: 5
    std::cout<<"trick to display mask: "<<+mask<<"\n";
    // > trick to display mask: 5
    
    // source: https://stackoverflow.com/questions/19562103/uint8-t-cant-be-printed-with-cout


                       // mask: 00 00 01 01
    uint8_t x0 = 0b00000110; // 00 00 01 10
    uint8_t x1 = x0 | mask;  // 00 00 01 11
    uint8_t x2 = x0 & mask;  // 00 00 01 00
    uint8_t x3 = x0 ^ mask;  // 00 00 00 11
    uint8_t x4 = ~x0;        // 11 11 10 01
    uint8_t x5 = x0 << 2;    // 00 01 10 00
    uint8_t x6 = x0 >> 1;    // 00 00 00 11

    std::cout<<"mask:           "<<std::bitset<8>(mask)<<"\n";
    std::cout<<"x1 = x0 | mask: "<<std::bitset<8>(x1)<<"\n";
    std::cout<<"x2 = x0 & mask: "<<std::bitset<8>(x2)<<"\n";
    std::cout<<"x3 = x0 ^ mask: "<<std::bitset<8>(x3)<<"\n";
    std::cout<<"x4 = ~x0:       "<<std::bitset<8>(x4)<<"\n";
    std::cout<<"x5 = x0 << 2:   "<<std::bitset<8>(x5)<<"\n";
    std::cout<<"x6 = x0 >> 1:   "<<std::bitset<8>(x6)<<"\n";


    // std::bitset
    // The class template bitset represents a fixed-size sequence of N bits.
    // https://en.cppreference.com/w/cpp/utility/bitset

    std::bitset<8> bmask{0b00000101};
    std::bitset<8> b0{"00000110"};

    using bst8 = std::bitset<8>;
    bst8 b1 = b0 | bmask; // 00 00 01 11
    bst8 b2 = b0 & bmask; // 00 00 01 00
    bst8 b3 = b0 ^ bmask; // 00 00 00 11
    bst8 b4 = ~b0;        // 11 11 10 01
    bst8 b5 = b0 << 2;    // 00 01 10 00
    bst8 b6 = b0 >> 1;    // 00 00 00 11

    std::cout<<"bmask:           "<<bmask<<"\n";
    std::cout<<"b1 = b0 | bmask: "<<b1<<"\n";
    std::cout<<"b2 = b0 & bmask: "<<b2<<"\n";
    std::cout<<"b3 = b0 ^ bmask: "<<b3<<"\n";
    std::cout<<"b4 = ~b0:        "<<b4<<"\n";
    std::cout<<"b5 = b0 << 2:    "<<b5<<"\n";
    std::cout<<"b6 = b0 >> 1:    "<<b6<<"\n";

    // operations on the whole set
    b0.flip();  // 11 11 10 01
    std::cout<<"b0.flip():       "<<b0<<"\n";
    b0.reset(); // 00 00 00 00
    std::cout<<"b0.reset():      "<<b0<<"\n";
    b0.set();   // 11 11 11 11
    std::cout<<"b0.set():        "<<b0<<"\n";

    // operations on individual bits
    b0.set(0,false); /* 11 11 11 10 */    std::cout<<"b0.set(0, false):        "<<b0<<"\n";
    b0.flip(1);      /* 11 11 11 00 */    std::cout<<"b0.flip(1):              "<<b0<<"\n";
    b0.reset(2);     /* 11 11 10 00 */    std::cout<<"b0.resret(2):            "<<b0<<"\n";

    b0[3]=false;     /* 11 11 00 00 */    std::cout<<"b0[3]=false:             "<<b0<<"\n";

    std::cout<<b0.count()<<"\n"; // 4
    std::cout<<b0.size()<<"\n";  // 8
    unsigned long long a = b0.to_ullong();
    std::string str = b0.to_string();
}