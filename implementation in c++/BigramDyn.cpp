/* HW :    7
 * File:   BigramDyn.cpp
 * Author: Gulzada IISAEVA
 * ID:     131044085
 * 
 * This file contains implementations of BigramDyn class
 */

#include "BigramDyn.h"

namespace myBigram {

//pointer kullandigim  icin copy consctructor yazdim
template<class T>
BigramDyn<T>::BigramDyn ( const BigramDyn& copy) 
            :sizeOfArray(copy.sizeOfArray)
{
    twoGramArray= new string [sizeOfArray];
    for(int i=0; i< sizeOfArray; i++)
    {
        twoGramArray[i]=copy.twoGramArray[i];
    }
}
template<class T>
BigramDyn<T>::~BigramDyn() {
    delete [] twoGramArray;
    twoGramArray=NULL;
}
template<class T>
void BigramDyn<T>::setDataType(const int dataType) {
    this->dataType = dataType;
}
template<class T>
int BigramDyn<T>::getDataType() const {
    return dataType;
}

 /*takes a filename as a string parameter, reads the file, calculates all the bigrams.*/
template<class T>
void BigramDyn<T>::readFile(const char* filename)
{   
    T input;
    int count=0,i=0;
    string check; //dosyadan okumak icin degiskenler
    int flagInt=0,flagDouble=0,flagEmpty=0; //exception icin
    
    fstream inStream;  //dosya acip kapatmak icin
    inStream.open(filename);
    if (inStream.fail()) //check for file open failure
    {
    throw DerrivedException("Error opening file");
    }
    while (inStream>> check){
        flagEmpty++;
    }
    if(flagEmpty==0){
        throw DerrivedException("An Empty File");
    }
    inStream.close();
    inStream.open(filename);
    if(getDataType()==1 || getDataType()==3)  //int okurken string ya da double gelirse,tam tersi icin exception
    {
        while(inStream>> check)
        {
           if(getDataType()==1){
                if(isANumber(check)==-1)
                     flagInt=-1;}
           if(getDataType()==3){
                size_t found = check.find('.');  // double icin . varmi
                if(found ==-1)
                {
                    flagDouble=-1;
                }
           }
        }
        
    }
    inStream.close();
    
    inStream.open(filename);
    
    while (inStream >> input)
    {
        count++;
    }
   if(getDataType()==1 || getDataType()==3)
    {
        if(flagInt==-1 || flagDouble==-1)
        {
           throw DerrivedException("Wrong Input");
        }
    }
    setsizeOfArray(count);
   
            
        inStream.close();
    
    twoGramArray= new T[getsizeOfArray()];
    inStream.open(filename);
     while (inStream >> input)
    {
         twoGramArray[i]=input;
         i++;
    }
    inStream.close();
    
}  
/*returns the total number of bigrams calculated so far.*/
template<class T>
int BigramDyn<T>::numGrams() const
{
    return getsizeOfArray()-1;
}
/*takes two elements as bigrams and returns the number of that bigram read so far.*/
template <class T>
int BigramDyn<T>::numOfGrams (const T first ,const T second) const
{
  int num=0;
 for (int i=0; i< getsizeOfArray();i++)
    {
     
        if (first==twoGramArray[i] && second ==twoGramArray[i+1])
        {
            num++;
        }
    }
    return num;
      
}
/*prints all the bigrams and their occurences in decreasing occurent order.<< operator cant be 
     inherited so I use another helper function*/
template <class T>
void BigramDyn<T>::helper_func(ostream& outStream) const 
{
    pair<T,T> swap;
    pair<T,T> *temp=new pair<T,T>[getsizeOfArray()-1];
   
     for (int i=0 ; i < getsizeOfArray()-1 ;i++)
    {
         temp[i]=make_pair(twoGramArray[i],twoGramArray[i+1]);
       
    }
    
     for (int i=0 ; i < getsizeOfArray()-1 ;i++)
     {
         for (int j=0 ; j < getsizeOfArray()-1 ;j++)
         {
        
         if(numOfGrams(temp[i].first,temp[i].second) > numOfGrams(temp[j].first,temp[j].second))
         {
             swap.first=temp[i].first;
             swap.second=temp[i].second;
             temp[i].first=temp[j].first;
             temp[i].second=temp[j].second;
             temp[j].first=swap.first;
             temp[j].second=swap.second;
             
             
         }
         }
     }

    int count=0;
    for (int i=0 ; i < getsizeOfArray()-1 ;i++)
    {
        count=numOfGrams(temp[i].first,temp[i].second);
        i+=count-1;
        outStream <<"(" << temp[i].first <<" , "<<temp[i].second<< ") = " << count<<endl;
        
    }
}
 /*returns the bigram that has occurred most frequently*/
template <class T>
pair <T, T> BigramDyn<T>:: maxGrams() const 
{
    int maxcount=0, index=-1;
    pair<T,T> p1;
    for (int i = 0; i < getsizeOfArray(); i++)
    {
        int count=0;
        for (int j = i+1; j < getsizeOfArray()-1; j++)
            if (twoGramArray[i] == twoGramArray[j] && twoGramArray[i+1]== twoGramArray[j+1])
            {
                count++;
            }
        if (maxcount < count)
        {
            maxcount = count;
            index = i;
        }
    }

    if (index >= 0){
        p1=make_pair(twoGramArray[index],twoGramArray[index+1]);
    }
    else{
      
        cout  << "No repeating pair" << endl;
    }
    
    return p1;
   
}
template<class T>
void BigramDyn<T>::setsizeOfArray(const int size) {
    this->sizeOfArray = size;
}

template<class T>
int BigramDyn<T>::getsizeOfArray() const {
    return sizeOfArray;
}

//dosyadan okurken gelen inputun string mi bakiyor "exception icin" kullandim
template<class T>
int BigramDyn<T>::isANumber(string str){  //stringin sayi olup olmadigini control ediyor
    
  for (int i=0; i<str.size(); i++)
  {
    if((str[i] <'0') || (str[i] > '9'))
    return -1;
  }
    return 1;
}
}