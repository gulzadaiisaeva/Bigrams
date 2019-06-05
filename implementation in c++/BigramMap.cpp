/* HW :    7
 * File:   BigramMap.cpp
 * Author: Gulzada IISAEVA
 * ID:     131044085
 * 
 *  This file contains implementations of BigramMap class
 */

#include "BigramMap.h"

namespace myBigram {
/*takes a filename as a string parameter, reads the file, calculates all the bigrams.*/
template<class T>
void BigramMap<T>::readFile(const char* filename)
{   
   
    fstream inStream; //dosya acip kapatmak icin
    inStream.open(filename);
    T input,input2, temp; //dosyadan okumak icin degiskenler
    string check;
    int flagInt=0,flagDouble=0,flagEmpty=0; //exception icin
    int i=0;
    
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
    inStream >> input ;
    v.push_back(input);
    i++;
    temp=input;
  
    while (inStream >> input2)
	{
        twoGramMap[i]=make_pair(temp,input2);  //okudugum inputlari map of paire atama
        v.push_back(input2);
        temp=input2;
        i++;
	}
   if(getDataType()==1 || getDataType()==3)   //exception firlatma
    {
        if(flagInt==-1 || flagDouble==-1)
        {
           throw DerrivedException("Wrong Input");
        }
    }
    inStream.close();
   
    setNumberOfPairs(twoGramMap.size());
   

    
    
}
/*returns the total number of bigrams calculated so far.*/
template<class T>
int BigramMap<T>::numGrams() const
{
    return getNumberOfPairs();
}
 /*takes two elements as bigrams and returns the number of that bigram read so far.*/
template <class T>
int BigramMap<T>::numOfGrams (const T first ,const T second) const
{
    int num=0;
    
    	auto it = twoGramMap.cbegin();
		while(it!=twoGramMap.cend())
		{
                        if (first==(it->second).first && second ==(it->second).second)
                            num++;
			++it;
		}
    return num;
      
}

/*prints all the bigrams and their occurences in decreasing occurent order.<< operator cant be 
 inherited so I use another helper function*/
template <class T>
void BigramMap<T>::helper_func(ostream& outStream) const 
{
        map<pair<T,T> ,int> number;
        map<int ,int> temp;
        int count=1;
        pair<T,T> p1;
        
        	for (int i = 0; i < v.size()-1; ++i)
	{
		
		p1=make_pair(v[i],v[i+1]);
		if(number.find(p1) == number.end())
		{
			number[p1]=1;
			
		}
		else
		{
			number[p1]++;
		}
	}
	for (auto &t : number)  //artan sekilde siralayarak ekrana yazar
    {
        outStream <<"(" << t.first.first << " , " << t.first.second << ") = " << t.second<<endl;
    }
        //pair tekrarlanmasina gore siralamaya calismistim
        
      /*  typename map<pair<T,T> ,int> :: iterator it;
        typename map<pair<T,T> ,int> :: iterator it2;
        int k=0;
        for (it=number.begin();it!=number.end();it++){
            //it2=number.begin();
        for(it2=number.begin();it2!=number.end();it2++){
            if(it->second < it2->second)
            {
                temp.insert(make_pair(k,it2->second));
                //outStream <<"(" << it2->first.first<< " , " << it2->first.second << ") = " << it2->second<<endl;
            }
            else
            {
                
            }
            
        }
         temp.insert(make_pair(k,it->second));
        k++;
            
        }
        typename map<int ,int> :: iterator it3;
        for (it3=temp.begin();it3!=temp.end();it3++){
            outStream <<"(" << it3->first<< " , " << it3->second << ") = " <<endl;
            
        }
            
        */
        
}
/*returns the bigram that has occurred most frequently*/
template <class T>
pair <T, T> BigramMap<T>:: maxGrams() const 
{
    int maxcount=0, index=-1;   
    pair<T,T> p1;
    for (int i = 0; i < v.size(); i++)
    {
        int count=0;
        for (int j = i+1; j < v.size()-1; j++)
            if (v[i] == v[j] && v[i+1]== v[j+1])
            {
                count++;
            }
        if (maxcount < count)
        {
            maxcount = count;
           
            index = i;  //en cok tekrarlanin indexsini dondurur
        }
    }
    if (index >= 0){   
        p1=make_pair(v[index],v[index+1]);
    }
    else{
      
        cout  << "No repeating pair" << endl;
    }
    
    return p1;
   
}
template<class T>
void BigramMap<T>::setNumberOfPairs(const int numberOfPairs) {
    this->numberOfPairs = numberOfPairs;
}

template<class T>
int BigramMap<T>::getNumberOfPairs() const {
    return numberOfPairs;
}

//dosyadan okurken gelen inputun string mi bakiyor "exception icin" kullandim
template<class T>
int BigramMap<T>::isANumber(string str){  //stringin sayi olup olmadigini control ediyor
    
  for (int i=0; i<str.size(); i++)
  {
    if((str[i] <'0') || (str[i] > '9'))
    return -1;
  }
    return 1;
}
template<class T>
void BigramMap<T>::setDataType(const int dataType) {
    this->dataType = dataType;
}
template<class T>
int BigramMap<T>::getDataType() const {
    return dataType;
}
}