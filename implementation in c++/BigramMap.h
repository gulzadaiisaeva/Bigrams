/* HW :    7
 * File:   BigramMap.h
 * Author: Gulzada IISAEVA
 * ID:     131044085
 * 
 * We have to derive 2 concrete classes from Bigram base class. This first class is BigramMap, which uses STL
 * Map class to implement all the functions in Bigram.h
 * Aciklama string icin bad data yapilmadi. Ne girerse girsin string olarak okuyabilir ona gore yaptim 1 2.2 onlari da string 
 * olarak kabul ettim
 */

#ifndef BIGRAMMAP_H
#define	BIGRAMMAP_H
#include<algorithm>
#include "Bigram.h"
using namespace std;

namespace myBigram {
template<class T>
class BigramMap : public Bigram<T>{
public:
   BigramMap(int dataType) : numberOfPairs(0),dataType(dataType) {};
   void readFile(const char* filename);
   int numGrams () const;
   int numOfGrams (const T first ,const T second) const;
   void helper_func(ostream& outStream) const ;
   pair <T, T> maxGrams() const ;
   
   void setNumberOfPairs(const int numberOfPairs) ;
   int getNumberOfPairs() const ;
   int isANumber(string str);
   void setDataType(const int dataType);
   int getDataType() const;
   
private:
    map<int,pair<T,T> > twoGramMap;
    int numberOfPairs;
    vector<T> v;
    int dataType;
    
    
};
}
#endif	/* BIGRAMMAP_H */
