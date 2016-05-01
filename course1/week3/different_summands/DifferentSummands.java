import java.util.*;

public class DifferentSummands {
    private static List<Integer> optimalSummands(int n) {
        List<Integer> summands = new ArrayList<Integer>();
        
        int max_k = (int)Math.floor((Math.sqrt(1+8*(long)n) - 1)/2);
        int sum = 0;
        for(int i=1;i<max_k;++i) {
            summands.add(i);
            sum+=i;
        }
        
        summands.add(n-sum);
        
        return summands;
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> summands = optimalSummands(n);
        System.out.println(summands.size());
        for (Integer summand : summands) {
            System.out.print(summand + " ");
        }
    }
}

