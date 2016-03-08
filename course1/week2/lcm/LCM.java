import java.util.*;

public class LCM {
  private static int gcd(int a, int b) {
    if (b==0)
        return a;
    else {
        if (b>a)
            return gcd(b,a);
        else
            return gcd(b, a % b);
    }
  }
  
  private static long lcm(int a, int b) {
    if (a == 0 || b == 0)
        return 0;
    
    int gcd = gcd(a,b);
    return (Long.valueOf(a) / gcd)*Long.valueOf(b);
  }

  public static void main(String args[]) {
    Scanner scanner = new Scanner(System.in);
    int a = scanner.nextInt();
    int b = scanner.nextInt();

    System.out.println(lcm(a, b));
  }
}
