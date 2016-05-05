import java.util.*;

public class PrimitiveCalculator {
    private static List<Integer> optimal_sequence(int n) {
        List<Integer> sequence = new ArrayList<Integer>();
        int[] a = new int[n];
        
        a[0] = 0;
        for(int i=1;i<=n;++i) {
            if(i>1)
                a[i-1] = a[i-2] + 1;
                
            if (i % 3 == 0) {
                int min_steps = a[i/3 - 1] + 1;
                if (a[i-1] > min_steps) a[i-1] = min_steps;
            } else if (i % 2 == 0) {
                int min_steps = a[i/2 - 1] + 1;
                if (a[i-1] > min_steps) a[i-1] = min_steps;
            }
        }
        
        int i=n;
        while(i>0) {
            sequence.add(i);
            int next_i = i-1;
            if (i%3 == 0 && a[i-1] == (a[i/3 -1] + 1))
                next_i = i/3;
            if (i%2 == 0 && a[i-1] == (a[i/2 -1] + 1))
                next_i = i/2;
            i = next_i;
        }
        
        Collections.reverse(sequence);
        return sequence;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> sequence = optimal_sequence(n);
        System.out.println(sequence.size() - 1);
        for (Integer x : sequence) {
            System.out.print(x + " ");
        }
    }
}

