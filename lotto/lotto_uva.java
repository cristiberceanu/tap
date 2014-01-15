import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;
class Main {
private static int n;
private static int c;
	public static void back(int pos, int[] vec, int[] st){
		boolean flag = true;
		if(pos==7)
		{
			for(int i=1;i<=6;i++)
				for(int j=i+1;j<=6;j++)
					if(st[i]>=st[j])
						flag = false;
			System.out.print();
			if (flag)
			{
				for(int i=1;i<=6;i++)
					if(i!=6)
					System.out.print(vec[st[i]] + " ");
					else
					System.out.print(vec[st[i]]);
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
		Scanner in = new Scanner(System.in);
		while(in.hasNextInt()){
		n = in.nextInt();
		
		if(n!=0)
		for(int i=1; i<=n; i++){
			vec[i] = in.nextInt();
			
		}
		back(1,vec,st);
		System.out.print("\n");
		}
		
		in.close();
	}
}
