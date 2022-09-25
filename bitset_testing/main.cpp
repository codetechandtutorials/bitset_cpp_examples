// testing out using std::bitset

#ifdef WIN32
#include <bitset>
#elif   // linux and macos
#include <bits/stdc++.h>
#endif

#include <string>
#include <iostream>

#define _log std::cout
#define _endlog std::endl

typedef  std::bitset<32> _32bits;
typedef  std::bitset<16> _16bits;
typedef  std::bitset<8>  _8bits;
typedef  std::string     _string;

int main() {

  // Converting decimal number to binary by using bitset
  int num = 0;
  _log << "show INTEGER number: " << num << " as 8 BIT BINARY equivalent: " << _8bits(num) << _endlog;
  num += 128;
  _log << "show INTEGER number: " << num << " as 8 BIT BINARY equivalent: " << _8bits(num) << _endlog;
  num += 64;
  _log << "show INTEGER number: " << num << " as 8 BIT BINARY equivalent: " << _8bits(num) << _endlog;
  num += 63;
  _log << "show INTEGER number: " << num << " as 8 BIT BINARY equivalent: " << _8bits(num) << _endlog;
  num += 1;
  _log << "show INTEGER number: " << num << " as 8 BIT BINARY equivalent: " << _8bits(num) << _endlog;
  _log << "show INTEGER number: " << num << " as 16 BIT BINARY equivalent: " << _16bits(num) << _endlog;
  num -= 134;
  _log << "show INTEGER number: " << num << " as 8 BIT BINARY equivalent: " << _8bits(num) << _endlog;
  num -= 10;
  _log << "show INTEGER number: " << num << " as 8 BIT BINARY equivalent: " << _8bits(num) << _endlog;
  num -= 30;
  _log << "show INTEGER number: " << num << " as 8 BIT BINARY equivalent: " << _8bits(num) << _endlog;
  _log << _endlog;


  // lets play around with some 32bit bitset variables and their operations

  _32bits set1;  // inits to all 0's
  _log << "set1: " << set1 << _endlog;
  _log << "set1: any() check: " << std::boolalpha << set1.any() << _endlog;
  _log << "set1: none() check: " << std::boolalpha << set1.none() << _endlog;
  _log << "set1: count() check: " << set1.count() << _endlog;
  _log << "set1: size()-count() (how many 0's) check: " << set1.size() - set1.count() << _endlog;
  _log << _endlog;


  _32bits set2(21);  // init to the bits to represet the value 20 -> this will set the digits to == 20 (should be 10101 at end)
  _log << "set2: " << set2 << _endlog;
  _log << "set2: any() check: " << std::boolalpha << set2.any() << _endlog;
  _log << "set2: none() check: " << std::boolalpha << set2.none() << _endlog;
  _log << "set2: count() check: " << set2.count() << _endlog;
  _log << "set2: size()-count() (how many 0's) check: " << set2.size() - set2.count() << _endlog;
  _log << _endlog;


  _32bits set3(_string("1100"));  // should be 1100 at the end
  _log << "set3: " << set3 << _endlog;
  _log << "set3: any() check: " << std::boolalpha << set3.any() << _endlog;
  _log << "set3: none() check: " << std::boolalpha << set3.none() << _endlog;
  _log << "set3: count() check: " << set3.count() << _endlog;
  _log << "set3: size()-count() (how many 0's) check: " << set3.size() - set3.count() << _endlog;
  _log << _endlog;

  // and now an 8bit bitset vairable

  _8bits an_8bit_set; //  inits to 0's
  an_8bit_set[1] = 1; //  change index 1: 00000010
  an_8bit_set[4] = an_8bit_set[1]; // change index 4: 00010010
  _log << "an_8bit_set: " << an_8bit_set << _endlog;
  _log << "an_8bit_set: any() check: " << std::boolalpha << an_8bit_set.any() << _endlog;
  _log << "an_8bit_set: none() check: " << std::boolalpha << an_8bit_set.none() << _endlog;
  _log << "an_8bit_set: count() check: " << an_8bit_set.count() << _endlog;
  _log << "an_8bit_set: size()-count() (how many 0's) check: " << an_8bit_set.size() - an_8bit_set.count() << _endlog;

  // more various oprations to test

  _log << "bool representation of " << an_8bit_set << " : ";
  for (int i = static_cast<int>(an_8bit_set.size() - 1); i >= 0; i--) {  // reverse ordered
    _log << std::boolalpha << an_8bit_set.test(i) << " ";
  }
  _log << _endlog;

  _log << "set() all the bits" << _endlog;
  // set all bits, returns a reference to the bits after setting
  _log << an_8bit_set.set() << _endlog;

  _log << "set bit 4 to 0" << _endlog;
  // set position 4 to a 0 (bitset should be 11101111)
  _log << an_8bit_set.set(4, 0) << _endlog;

  _log << "set bit 4 to default" << _endlog;
  // set position 4 to default (1) (bitset should be all 1's)
  _log << an_8bit_set.set(4) << _endlog;

  // reset function is like set except the default is 0
  _log << "reset bit 2 to default" << _endlog;
  // bitset should be 11111011 after this operation
  _log << an_8bit_set.reset(2) << _endlog;
  _log << "reset all bits to default" << _endlog;
  // bitset should be all 0's after this operation
  _log << an_8bit_set.reset() << _endlog;

  // flip toggles the bit to the opposite of whatever it was 0/1
  _log << "flip bit at position 2" << _endlog;
  // flips position 2 -> should be 00000100
  _log << an_8bit_set.flip(2) << _endlog;
  _log << "flip all the bits" << _endlog;
  // flip all the bits, should be all 11111011
  _log << an_8bit_set.flip() << _endlog;

  // lets test out some operations

  // left and right shift
  _log << "left shift 2" << _endlog;
  an_8bit_set <<= 0b10;  // multiplication hacks : this 0b10 is the binary rep for value "2"
  _log << an_8bit_set << _endlog;
  _log << "right shift 1" << _endlog;
  an_8bit_set >>= 0b1;   // div 2 hacks : 0b1 is binary for "1"
  _log << an_8bit_set << _endlog;

  // vars to compare with
  const _8bits _ones = 255;
  const _8bits _zeros = 0;

  // or
  _log << an_8bit_set << " OR with " << _ones << " = " << (an_8bit_set | _ones) << _endlog;
  _log << an_8bit_set << " OR with " << _zeros << " = " << (an_8bit_set | _zeros) << _endlog;

  // and
  _log << an_8bit_set << " AND with " << _ones << " = " << (an_8bit_set & _ones) << _endlog;
  _log << an_8bit_set << " AND with " << _zeros << " = " << (an_8bit_set & _zeros) << _endlog;

  // xor
  _log << an_8bit_set << " XOR with " << _ones << " = " << (an_8bit_set ^ _ones) << _endlog;
  _log << an_8bit_set << " XOR with " << _zeros << " = " << (an_8bit_set ^ _zeros) << _endlog;

  // lets talk about left shifting to multiply

  an_8bit_set.set();   // max value, same effect as = 255 for 8 bit
  _log << an_8bit_set << " is " << an_8bit_set.to_ulong() << _endlog;

  an_8bit_set <<= 1;   // times 2 if the value was under half -> check the leftmost bit first if you are intended on making this a multiplication
  _log << an_8bit_set << " is " << an_8bit_set.to_ulong() << _endlog;  // as you can see this didn't x2, but rather appears to have subtracted 1

  an_8bit_set = 123;
  _log << an_8bit_set << " is " << an_8bit_set.to_ulong() << _endlog;
  an_8bit_set <<= 1;   // times 2 if the value was under half
  _log << an_8bit_set << " is " << an_8bit_set.to_ulong() << _endlog;  // as you can see this DID x2

  an_8bit_set >>= 1;  // div 2
  _log << an_8bit_set << " is " << an_8bit_set.to_ulong() << _endlog;

  an_8bit_set >>= 1;  // div 2 again, notice the round down
  _log << an_8bit_set << " is " << an_8bit_set.to_ulong() << _endlog;

  an_8bit_set >>= 1;  // div 2 again, notice the round down
  _log << an_8bit_set << " is " << an_8bit_set.to_ulong() << _endlog;

  return 0;
}
