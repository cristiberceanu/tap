import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;
class Main {
private static int n;
private static int c;
	public static void back(int pos, int[] vec, int[] st){
		boolean flag = true;
		if(pos==c+1)
		{
			for(int i=1;i<=c;i++)
				for(int j=i+1;j<=c;j++)
					if(st[i]>=st[j])
						flag = false;
			if (flag)
			{
				for(int i=1;i<=c;i++)
					System.out.print(st[i] + " ");
			System.out.print("\n");
			}
			return;
		}
		
		for(st[pos]=1;st[pos]<=n;++st[pos]){
			st[pos+1] = 1;
			back(pos+1, vec, st);
		}
	}
	public static void main(String[] args) throws FileNotFoundException
	{
		int[] vec = new int[49];
		int[] st = new int[49];
		Scanner in = new Scanner(new File("test.in"));
		n = in.nextInt();
		c = in.nextInt();
		for(int i=1;i<=n;i++)
			vec[i] = in.nextInt();
		back(1,vec,st);
		in.close();
	}
}
