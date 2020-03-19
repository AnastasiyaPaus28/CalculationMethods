package gaus;

public class MethodGaus {

	private double Array[][] ;
	private double X[] = new double [4];
	
	public static void main(String[] args) {
		
		MethodGaus method = new MethodGaus();
		method.outputArray();
		method.calculation();
		method.findingArrayX();
		method.outputX();
	}

	MethodGaus()
	{
		System.out.println("Инициализация массива: ");
	    double temporaryArray[][] =
	    	 {
	    	{3.8, 14.2, 6.3, -15.5, 2.8},
            {8.3, -6.6, 5.8, 12.2, -4.7},
            {6.4, -8.5, -4.3, 8.8, 7.7},
            {17.1, -8.3, 14.4, -7.2, 13.5}
            };
		
	    Array = temporaryArray;
	}
	
	void calculation()
	{
		double p;
        for (int k=0;k<4;k++) {
            System.out.println( "Делим "+
             (k+1)+
              "строку на " +
              Math.round( Array[k][k] * 1000.0 ) / 1000.0 );

            for (int j = k + 1; j < 5; j++) {
                Array[k][j] /= Array[k][k];
            }

            Array[k][k] = 1;
            outputArray();
            
            for (int i = k + 1; i < 4; i++) {
                p = Array[i][k];
                System.out.println( "Умножаем " + (k+1)+ " строку на " + 
                (Math.round( p * 1000.0 ) / 1000.0) + 
                " и отнимаем от " + (i + 1) + " строки" );
                
                for (int j = k; j < 5; j++) 
                    Array[i][j] -= (Array[k][j] * p);
                outputArray();
               
            }
        }
	}
	
	void outputArray()
	{
		for (int i = 0; i < 4; i++) {
            for (int m = 0; m < 5; m++) {
                System.out.print( (Math.round( Array[i][m] * 1000.0 ) / 1000.0) + "   " );
            }
            System.out.println();
        }
		System.out.println();	
	}
	
	void findingArrayX()
	{
		X[3]=Array[3][4];
        X[3]=Math.round(X[3]*1000.0)/1000.0;
        
        for(int i=2;i>=0;i--){
            X[i]=Array[i][4];
            for(int j=3;j>=i+1;j--){
                X[i]-=Array[i][j]*X[j];
            }
            X[i]=Math.round(X[i]*1000.0)/1000.0;
        }
	}
	
	void outputX() {
		
		System.out.println("Корни уравнения:");
		for(int i=0;i<4;i++)
			System.out.println(X[i]);
			
	}
}
