import java.util.*;

public class FibonacciHuge {
    private static long fib(long n, long m) {
        if (n <= 1)
          return n;

        long prev1 = 1;
        long prev2 = 0;
        long fib = prev2 + prev1;
        for(long i=2;i<n;i++) {
            prev2 = prev1;
            prev1 = fib;
            fib = (prev2 + prev1) % m;
        }
        return fib;
  }
  
    private static long getFibonacciHuge(long n, long m) {
        long prev1 = 1;
        long prev2 = 0;
        long fib = prev2 + prev1;
        long period = m;
        //System.out.format("0 1 ");
        for(long i=2;i<n;++i) {
            prev2 = prev1;
            prev1 = fib;
            fib = (prev2 + prev1) % m;
            //System.out.format("%d ", prev1);
            if (fib == 1 && prev1 == 0) {
                period = i;
                break;
            }
        }
        //System.out.println();
        //System.out.format("Period: %d%n", period);
        
        return fib(n % period, m);
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long m = scanner.nextLong();
        System.out.println(getFibonacciHuge(n, m));
    }
}

