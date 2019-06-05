/* HW :    8
 * File:   Bigram.java
 * Author: Gulzada IISAEVA
 * ID:     131044085
 * 
 * A class hierarchy for bigrams (2-Gram). A bigram is a specialization of N-Gram which
“is a contiguous sequence of N items from a given data sequence”. For the bigram we take N=2. For
example if we have a sequence of integers {1 4 6 3 7 1 4 7 2} then the number of {1 4} bigrams is 2,
the number of {4 6} bigrams is 1, and the number of {3 4} bigrams is 0. Similarly, if the sequence is
{qwe asd fgh sdf sdf} then the number of {qwe asd} bigrams is 1.
*
*
The java interface Bigram which will have the following methods. This class will not have any data
fields.
• readFile: takes a filename as a string parameter, reads the file, calculates all the bigrams.
Throws exceptions if there are problems with opening and reading the file.
• numGrams: returns the total number of bigrams calculated so far. For example, if we read
an integer sequence file that contains {1 234 346 343 7234 341 434 72 234}, then
numGrams() returns 8.
• numOfGrams: takes two elements as bigrams and returns the number of that bigram read so
far. For example, if we read an integer sequence file that contains {1 4 6 3 7 1 4 7 2}, then
numOfGrams(1,4) returns 2.
• toString prints all the bigrams and their occurences in decreasing occurency order.
 */

import java.lang.*;
import java.util.*;
import java.io.*;


public interface Bigram<T> {

    
    public void readFile (String filename)throws Exception;
	public int numGrams ();
    public int numOfGrams (T p1 , T p2) ;
	@Override public String toString();
  
    
}
