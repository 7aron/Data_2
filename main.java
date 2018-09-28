//Ex 5 in Java
//already had this algorithms so decided not to do in C++

public class ex5 {
	public static void main(String[] args) {
		long startTime = System.nanoTime();
	    int[][] matrix = { { 2, 1, 4, 5 }, { 3, 9, 8, 43 } };

	    for (int i = 0; i < matrix.length; i++) {
	        
	        int maxInRow = matrix[i][0];
	        for (int j = 0; j < matrix[i].length; j++) {
	            

	            if (maxInRow < matrix[i][j]) {
	                maxInRow = matrix[i][j];
	            }
	        }
	        System.out.println("Maximum in row is " + maxInRow);

	        maxInRow = matrix[i][0];
	        long endTime   = System.nanoTime();
	        long totalTime = endTime - startTime;
	        System.out.println(totalTime);
	    }

	}
    
}
 
		 
		
	



 
 


	

  					
    		

    
    		
