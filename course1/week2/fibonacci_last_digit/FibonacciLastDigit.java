import java.util.*;

public class FibonacciLastDigit {
    private static int getFibonacciLastDigit(int n) {
        if (n <= 1)
            return n;

        int prev1 = 1;
        int prev2 = 0;
        int fib = prev2 + prev1;
        for(int i=2;i<n;i++) {
            prev2 = prev1;
            prev1 = fib;
            fib = (prev2 + prev1) % 10;
        }
        return fib;
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int c = getFibonacciLastDigit(n);
        System.out.println(c);
    }
}

