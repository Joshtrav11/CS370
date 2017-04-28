#include "bloom.h"

Bloom::Bloom(int amount) {
	table = new bool [amount];
	table2 = new bool [amount];
	seed = 0;
	size = amount;

	for(int i = 0; i < amount; i++) {
		table[i] = false;
		table2[i] = false;
	}
}

void Bloom::add(std::string item) {
	
	check(item, true);

}

void Bloom::add2(std::string item) {
	
	check2(item, true);

}

bool Bloom::check(std::string item, bool add) {
	item = item.substr(0,100);
	
	bool mainResult  = false;
	
	bool mainResult1 = false;
	bool mainResult2 = false;
	bool mainResult3 = false;
	bool mainResult4 = false;
	bool mainResult5 = false;

	unsigned int result1 = 0;
	unsigned int result2 = 0;
	unsigned int result2a = 0;
	unsigned int result3 = 0;
	unsigned int result4 = 0;
	unsigned int result5 = 0;
	
	result1 = hash_fn(item) % size;
	result2 = (MurmurHash1( &item, (uint32_t) item.length(), seed) % size);
    sha1_32a(&item, item.length(), seed, &result3);
	result3 = result3 % size;
    result4 = (MurmurHash2(&item, item.length(), seed) % size);
	MurmurHash3_x86_32( &item, item.length(), seed, &result5);
	result5 = result5 % size;

	if(table[result1] == true) {
		mainResult1 = true;
	}
	if(table[result2] == true) {
		mainResult2 = true;
	}
	if(table[result3] == true) {
		mainResult3 = true;
	}
	if(table[result4] == true) {
		mainResult4 = true;
	}
	if(table[result5] == true) {
		mainResult5 = true;
	}

	mainResult = mainResult1 && mainResult2 && mainResult3 && mainResult4 && mainResult5;

	if(!mainResult && add) {
		table[result1] = true;
		table[result2] = true;
		table[result3] = true;
		table[result4] = true;
		table[result5] = true;
	}
	
	return mainResult;
}

bool Bloom::check2(std::string item, bool add) {
	item = item.substr(0,100);
	
	bool mainResult  = false;
	
	bool mainResult1 = false;
	bool mainResult2 = false;
	bool mainResult3 = false;

	unsigned int result1 = 0;
	unsigned int result2 = 0;
	unsigned int result3 = 0;

	result1 = hash_fn(item) % size;
	result2 = (MurmurHash1( &item, (uint32_t) item.length(), seed) % size);
    sha1_32a(&item, item.length(), seed, &result3);
	result3 = result3 % size;

	if(table[result1] == true) {
		mainResult1 = true;
	}
	if(table[result2] == true) {
		mainResult2 = true;
	}
	if(table[result3] == true) {
		mainResult3 = true;
	}

	mainResult = mainResult1 && mainResult2 && mainResult3;

	if(!mainResult && add) {
		table[result1] = true;
		table[result2] = true;
		table[result3] = true;
	}
	
	return mainResult;
}

Bloom::~Bloom() {
	delete[] table;
	delete[] table2;
}
