/* HW :    8
 * File:   BigramDyn.java
 * Author: Gulzada IISAEVA
 * ID:     131044085
 * 
 * We will extend 2 concrete classes from this inteface class. The first class is BigramMap, which uses
Java Collections Map class to implement all the methods above. The second class is BigramDyn
which does not use any standard classes or methods, it uses only Java arrays.
 */

import java.util.*;
import java.io.*;
import java.lang.*;

public class BigramDyn<T> implements Bigram<T> {

	private  Object[] array;
	private int dataType=0;
    private int sizeOfPairs=0;
    private int stringSize=0;


    /*methods of class*/
    public BigramDyn(int data)
    {
      dataType=data;
    }
    /*takes a filename as a string parameter, reads the file, calculates all the bigrams.*/
    public void readFile (String filename) throws Exception
    {
    		
    		
			Scanner input = new Scanner(new File(filename));
			String temp;
			int size = 0;
			/*once size i belirlemek ve exception firlatmak icin 1 kere okuyorum*/
			while(input.hasNext())
				{
					temp= input.next();
				    size++;
				}
			setStringSize(size);
			input.close();
			Scanner input2 = new Scanner(new File(filename));
			array=new Object[size];
			int j = 0;
			/*data tipine gore olusturdugum Object e okuyorum*/
			if(getDataType()==1)
			{
			while(input2.hasNextInt())
				{
				   array[j] = input2.nextInt();
				    //System.out.println(array[j]);
				   j++;
				   setSizeOfPairs(j);
				}
			}
			else if(getDataType()==3)
			{
				while(input2.hasNextDouble())
					{
				   array[j] = input2.nextDouble();
				   //System.out.println(array[j]);
				   j++;
				   setSizeOfPairs(j);
					}
			}
			else if(getDataType()==2)
			{
				while(input2.hasNext())
				{
				   array[j] = input2.next();
				    //System.out.println(array[j]);
				   j++;
				   setSizeOfPairs(j);
				}
		    }
			input2.close();
			if(getSizeOfPairs()!=getStringSize())
				throw new Exception("Wrong input (BAD DATA)");
			if(getStringSize()==0)
				throw new Exception("Empty File!!!!!!!");
			
			
    
	}
	public int numGrams ()
	{
		return getSizeOfPairs()-1;
	}
	public int numOfGrams (T p1 , T p2) 
	{
		 int num=0;
		 boolean val, val2;

		 for (int i=0; i< getSizeOfPairs()-1;i++)
		 {
		 		val=p1.equals(array[i]);
		 		val2=p2.equals(array[i+1]);
	     		if( val ==true)
			     {
			     	if(val2 == true)
			     	{
			     		 num++;
			     	}
			      
			     }	
		 }

    	 return num;
      
	}
	@Override public String toString()
	{ 
		String str="";
		for (int i = 0; i < getSizeOfPairs()-1; i++)
	    {
	    	str+=array[i] + " " + array[i+1] + " = " + myNumOfGrams(array[i] ,array[i+1]) + "\n";
		}
		return str;

	}
    public int getDataType() {
        return dataType;
    }

    public void setDataType(int data) {
        this.dataType = data;
    }

    public int getSizeOfPairs() {
        return sizeOfPairs;
    }

   
    public void setSizeOfPairs(int size) {
        this.sizeOfPairs = size;
    }
   
 	public int getStringSize() {
        return stringSize;
    }

    public void setStringSize(int stringSize1) {
        this.stringSize = stringSize1;
    }
 
 	public int myNumOfGrams (Object p1 , Object p2)  
 	{
 		int count=0;
		for (int i = 0; i < getSizeOfPairs()-1; i++)
	    {
		    	if(p1.equals(array[i]) && p2.equals(array[i+1]))
			      {
			        count++;
			      }
	   	}
	   	return count;
	}
	/*public String maxGrams ()
	{
		String myStr=null;
		int max=0, temp=0;
		
	    for (int i = 0; i < getSizeOfPairs()-1; i++)
	    {
	        temp=numOfGrams((T)array[i],(T)array[i+1]);
	       

	        if(max<temp)
	        {
	        	max=temp;
	        	myStr=array[i]+ " " + array[i+1];

	        }
	     }
	    return myStr;
	}*/

}
