#ifndef _BLOOM_H
#define _BLOOM_H
#include <stddef.h>
#include <stdbool.h>
#include <string>
#include <functional>
#include <iostream>
#include "smhasher-master/src/MurmurHash3.h"
#include "smhasher-master/src/MurmurHash2.h"
#include "smhasher-master/src/MurmurHash1.h"
#include "smhasher-master/src/sha1.h"

class Bloom
{
  private:
    int size;
    bool *table;
    bool *table2;

    std::hash<std::string> hash_fn;
    int seed;

  public:
    Bloom(int amount);
    ~Bloom();
    void add(std::string item);
    void add2(std::string item);
    bool check(std::string item, bool add);
    bool check2(std::string item, bool add);
};

#endif