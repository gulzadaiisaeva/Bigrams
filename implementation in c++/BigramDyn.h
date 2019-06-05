/* HW :    7
 * File:   BigramDyn.h
 * Author: Gulzada IISAEVA
 * ID:     131044085
 * 
 * We have to derive 2 concrete classes from Bigram base class. This second class is BigramDyn which does not use
any STL classes or STL functions, it uses only old fashioned dynamic memory.
 */

#ifndef BIGRAMDYN_H
#define	BIGRAMDYN_H

#include "Bigram.h"
#include<algorithm>
using namespace std;
namespace myBigram {
template<class T>
class BigramDyn : public Bigram<T>,public exception {
public:
   BigramDyn(int dataType) : sizeOfArray(0),twoGramArray(NULL),dataType(dataType) {};
   BigramDyn ( const BigramDyn& copy);
   void readFile(const char* filename);
   int numGrams () const;
   int numOfGrams (const T first ,const T second) const;
   void helper_func(ostream& outStream) const ;
   pair <T, T> maxGrams() const ;
   
   void setsizeOfArray(const int size) ;
   int getsizeOfArray() const ;
    ~BigramDyn();
   void setDataType(const int dataType);
   int getDataType() const;
   int isANumber(string str);
private:
    T *twoGramArray;
    int sizeOfArray;
    int dataType;
};
}
#endif	/* BIGRAMDYN_H */
