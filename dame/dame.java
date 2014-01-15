import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
class dame
{
	private static int N;
	public static boolean verifica(int pos, int st[])
	{
		
		for(int i=1;i< N; i++)
			for(int j=i+1;j<=N;j++)
				if(st[i]==st[j] || Math.abs(st[j]-st[i])== Math.abs(i-j))
					return false;
		return true;
	}
	public static void back(int pos, int vec[], int st[])
	{
		if(pos==N+1)
		{

			if(verifica(pos,st))
			{
				for(int i=1;i<=N;++i)
					System.out.print(st[i] + " ");
				System.out.print("\n");
				
			}
				
			return;
		}
		
		for(;st[pos]<=N;++st[pos])
		{
			st[pos+1] = 1;
			back(pos+1, vec,st);
		}
	}
	public static void main(String[] args) throws FileNotFoundException
	{
		int[] vec = new int[20];
		int[] st  = new int[20];
		Scanner in = new Scanner(new File("test.in"));
		N = in.nextInt();
		for(int i=1;i<=N;++i)
			vec[i] = in.nextInt();
		
		st[1] = 1;
		back(1,vec,st);
		in.close();
	}
}