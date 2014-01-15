import java.util.Scanner;

public class Main
{
	
	static char[][] matrix = new char[6][6];
	static int n = 0;
	static int max_rooks = -1;
	
	public static int verify_configuration(int configuration)
	{
		boolean s = false;
		int num_rooks = 0;
		
		for (int j = 0;j<n*n;j++)
			if (((1 << j) & configuration) != 0) 
			{
				num_rooks ++;
			}
		
		for (int j = 0;j<n;j++){
			s = false;
			for (int k = 0;k<n;k++){
				int position = j * n + k;
				
				if (((1 << position) & configuration) != 0 && !s)
				{
					s = true;
				}					
				else if (((1 << position) & configuration) != 0 && s)
				{
					return -1;
				}
				
				if (matrix[j][k] == 'X' && ((1 << position) & configuration) != 0)
				{
					return -1;
				}
				if (matrix[j][k] == 'X' && s)
				{
					s = false;
				}
			}
		}

		
		for (int j = 0;j<n;j++){
			s = false;
			for (int k = 0;k<n;k++){
				int position = k * n + j;
				
				if (((1 << position) & configuration) != 0 && !s)
				{
					s = true;
				}					
				else if (((1 << position) & configuration) != 0 && s)
				{
					return -1;
				}
				
				if (matrix[k][j] == 'X' && ((1 << position) & configuration) != 0)
				{
					return -1;
				}
				if (matrix[k][j] == 'X' && s)
				{
					s = false;
				}
			}
		}
		return num_rooks;
	}
	
	public static void solve()
	{
		max_rooks = -1;
		int value = (1 << (n * n + 1));
		for (int i = 0;i<value;i++)
		{
			int posibility = verify_configuration(i);
			if (posibility != -1 && max_rooks < posibility)
				max_rooks = posibility;
				
		}
	}
	
	public static void main(String[] args)
	{
		Scanner inputScanner = new Scanner(System.in);
		n = inputScanner.nextInt();
		while (n != 0)
		{
			for (int i = 0;i<n;i++)
					matrix[i] = inputScanner.next().toCharArray();
			solve();
			System.out.println(max_rooks);
			n = inputScanner.nextInt();
			
		}
		inputScanner.close();
	}

}
