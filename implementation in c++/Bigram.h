/* HW :    7
 * File:   Bigram.h
 * Author: Gulzada IISAEVA
 * ID:     131044085
 * 
 * Description
 * A class hierarchy for bigrams (2-Gram). A bigram is a specialization of N-Gram which
 * “is a contiguous sequence of N items from a given data sequence”. For the bigram we take N=2. For
 * example if we have a sequence of integers {1 4 6 3 7 1 4 7 2} then the number of {1 4} bigrams is 2,
 * the number of {4 6} bigrams is 1, and the number of {3 4} bigrams is 0. Similarly, if the sequence is
 * {qwe asd fgh sdf sdf} then the number of {qwe asd} bigrams is 1.
 * The base class will be Bigram which will have only pure abstract functions and nothing else. This
 * class will not have any data members.
 */

#ifndef BIGRAM_H
#define	BIGRAM_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <map>
#include <vector>
#include "DerrivedException.h"
using namespace std;

namespace myBigram {
template<class T>
class Bigram {
public:
    /*takes a filename as a string parameter, reads the file, calculates all the bigrams.*/
    virtual void readFile (const char* filename)=0;
    /*returns the total number of bigrams calculated so far.*/
    virtual int numGrams () const =0;
    /*takes two elements as bigrams and returns the number of that bigram read so far.*/
    virtual int numOfGrams (const T first ,const T second) const =0;
    /*prints all the bigrams and their occurences in decreasing occurent order.<< operator cant be 
     inherited so I use another helper function*/
    virtual void helper_func(ostream& outStream)const = 0;
    friend ostream& operator << (ostream& outStream, Bigram& bg)
    {
        bg.helper_func(outStream);
        return (outStream);
    }
    /*returns the bigram that has occurred most frequently*/
    virtual pair <T, T> maxGrams() const =0;
};
}
#endif	/* BIGRAM_H */
