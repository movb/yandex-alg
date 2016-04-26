import java.util.Scanner;

public class Change {
    private static int getChange(int m) {
        int[] a = new int[m+1];
        int[] coins = new int[3];
        coins[0] = 1;
        coins[1] = 5;
        coins[2] = 10;
        
        for(int i=1;i<=m;++i)
        {
            for(int j=0;j<coins.length;j++)
            {
                if(i>=coins[j]) {
                    if(a[i-coins[j]]+1 < a[i] || a[i] == 0)
                        a[i] = a[i-coins[j]]+1;
                }
            }
        }
        
        return a[m];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        System.out.println(getChange(m));
    }
}
