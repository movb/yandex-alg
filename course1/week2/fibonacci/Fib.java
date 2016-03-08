import java.util.Scanner;

public class Fib {
  private static long calc_fib(int n) {
    if (n <= 1)
      return n;

    long prev1 = 1;
    long prev2 = 0;
    long fib = prev2 + prev1;
    for(int i=2;i<n;i++) {
        prev2 = prev1;
        prev1 = fib;
        fib = prev2 + prev1;
    }
    return fib;
  }

  public static void main(String args[]) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();

    System.out.println(calc_fib(n));
  }
}
