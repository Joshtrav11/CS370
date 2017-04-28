# Josh Matteson

To compile the code: run command "make"

To run the code: run command "./bloomFilter dictionary.txt input.txt output3.txt output5.txt"

a)
What hash functions did you choose and why (Hint: Cryptographic or non-cryptographic)?
What is the output range of the hash functions?
What is the size of the Bloom filter in each case?

I choose 4 non cryptographic hashes and 1 cryptographic (SHA1),
all from the "smhasher-master" github repo which has the famous hash "Murmur".
I used the built int c++ hasher from the "functional" library,
MurmurHash1, Sha1, MurmurHash2, and MurmurHash3. Most of these 
are 10 digit outputs, and the built in hash function from the c++ library
is 20 digits.

k = round(log(2.0) * m / n) --> 
For 5 hash functions, 680000 count, 0.0312 false positive rate = 4,907,430 bits
For 3 hash functions, 680000 count, 0.1245 false positive rate = 2,948,771 bits

b) How long does it take for your Bloom Filter to check 1 password in each case?
Why does one perform better than other?

It takes O(k) for 3 hash functions, and O(k) for 5 as well. Hash functions are 
supposably O(1), so it's that for k hash functions. Generally, having more 
hash functions performs better because there is a lesser false positive rate.

c) What is the probability of False Positive in your Bloom Filter in each case?
What is the probability of False Negative in your Bloom Filter?

Bloom Filter with 5 hash functions false positive rate: 3.12%
Bloom Filter with 3 hash functions false positive rate: 12.45%

Neither have false negatives.

d) How can you reduce the rate of False Positives?

Add more hash functions.