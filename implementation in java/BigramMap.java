/* HW :    8
 * File:   BigramMap.java
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

public class BigramMap<T> implements Bigram<T> {

	private Map<Integer, ArrayList<Object>> map = new HashMap<Integer, ArrayList<Object>>();
	private Map<Integer,Object> myMap = new HashMap<Integer, Object>();
	private int dataType=0;
    private int sizeOfPairs=0;
    private int stringSize=0;

	public BigramMap(int data)
    {
      dataType=data;
    }

    /*takes a filename as a string parameter, reads the file, calculates all the bigrams.*/
    public void readFile (String filename) throws Exception
    {
    		ArrayList<Object> arrList = new ArrayList<Object>();

			Scanner input = new Scanner(new File(filename));
			String temp;
			int size = 0;
			while(input.hasNext())
				{
					temp= input.next();
				    size++;
				}
			setStringSize(size);
			input.close();
			Scanner input2 = new Scanner(new File(filename));
			
			int j = 0;

			if(getDataType()==1)
			{
				while(input2.hasNextInt())
				{
				 
				   myMap.put(j,input2.nextInt());
				    //System.out.println(array[j]);
				   j++;
				    setSizeOfPairs(j);
				
					   /*arrList.add(j,scanner2.nextInt());
					   //map.put(j,arrList);
					   j++;
					
					//System.out.print(myMap);
					   setSizeOfPairs(j);
				 }
					for (int i=0; i< getSizeOfPairs()-1;i++)
					 {
					 map.put(i,arrList[i];	
					 }

				 System.out.print(arrList);*/

				}
			}	
			else if(getDataType()==2)
			{
				while(input2.hasNext())
				{
				   myMap.put(j,input2.next());
				    //System.out.println(array[j]);
				   j++;
				    setSizeOfPairs(j);
				}
				/*for(Map.Entry m:myMap.entrySet()){  
					   System.out.println(m.getValue());  
					  }*/
				  
		    }
			else if(getDataType()==3)
			{
				while(input2.hasNextDouble())
					{
				   myMap.put(j, input2.nextDouble());
				   //System.out.println(array[j]);
				   j++;
				    setSizeOfPairs(j);
					}
					/*for(Map.Entry m:myMap.entrySet()){  
					   System.out.println(m.getValue());  
					  }*/
			}
			input2.close();
			if(getSizeOfPairs()!=getStringSize())
				throw new Exception("Wrong input (BAD DATA)");
			if(getStringSize()==0)
				throw new Exception("Empty File!!!!!!!");
			
    
    }
    public int numOfGrams (T p1 , T p2) 
	{
		 int num=0;
		 boolean val, val2;

		 for (int i=0; i< getSizeOfPairs()-1;i++)
		 {
		 		val=p1.equals(myMap.get(i));
		 		val2=p2.equals(myMap.get(i+1));
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
    public int numGrams ()
	{
		return getSizeOfPairs()-1;
	}
	@Override public String toString()
	{ 
		String str="";
		for (int i = 0; i < getSizeOfPairs()-1; i++)
	    {
	    	str+=myMap.get(i) + " " + myMap.get(i+1) + " = " + myNumOfGrams(myMap.get(i),myMap.get(i+1) ) + "\n";
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

   
    public void setSizeOfPairs(int size1) {
        this.sizeOfPairs = size1;
    }
 	public int getStringSize() {
        return stringSize;
    }

    public void setStringSize(int stringSize1) {
        this.stringSize = stringSize1;
    }
    public int myNumOfGrams (Object p1 , Object p2)  
 	{
 		int num=0;
		 boolean val, val2;

		 for (int i=0; i< getSizeOfPairs()-1;i++)
		 {
		 		val=p1.equals(myMap.get(i));
		 		val2=p2.equals(myMap.get(i+1));
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

}
