package grafuri;

import java.util.ArrayList;
import java.util.Scanner;

public class colorare {
	
	private static int noduri;
	private static int muchii;
	private static int[] color = new int[100];
	private static int  colormin;
	private static int[][] matrix = new int[100][100];
	private static boolean  ok;

	private static int solve(){
		
		color[0] = 1; 
		for (int k = 1; k<noduri; k++){
			int c =1 ; 
			do{
				ok = true; 
				for (int j =0; j<=k-1; j++)	 
					if (matrix[k][j]==1 && color[j]==c) ok =false; 
				if (ok == false) c++; 

				color[k] = c;

				if (color[k] > colormin) colormin = color[k];
			}
			return colormin;
		}

		public static void main(String[] args){
			Scanner in = new Scanner(System.in);

			noduri = in.nextInt();
			muchii = in.nextInt();

			for (int i = 0; i< muchii;i++){

				int nod1 = in.nextInt();
				int nod2 = in.nextInt();

				matrix[nod1][nod2] = 1;
				matrix[nod2][nod1] = 1;

			}

			System.out.println(solve());
		}
	}
