class ThisThread extends Thread
{ 
  public void run()
	
	{
    
		for(int i=0;i<10;i++)
		
		{
      
			System.out.println("Child Thread");
    
		}	  
  
	}

}

class ThreadDemo

{
	public static void main(String arg[])
	
	{
		
		ThisThread t=new ThisThread();
				
		t.start();
		
		for(int i=0;i<10;i++)
		
		{
      
			System.out.println("Main Thread");
    
		}
	
	}

}