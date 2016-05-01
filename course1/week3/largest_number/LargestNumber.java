import java.util.*;

public class LargestNumber {
    static class StrComparator implements Comparator<String>
    {
        public int compare(String s1, String s2)
        {
            int min_len = Math.min(s1.length(), s2.length());
            for(int i=0;i<min_len;++i) {
                if(s1.charAt(i)<s2.charAt(i))
                    return 1;
                else if(s2.charAt(i)<s1.charAt(i))
                    return -1;
            }
            if (s1.length()<s2.length())
                return s2.charAt(min_len) - s2.charAt(min_len-1);
            else if (s2.length()<s1.length())
                return s1.charAt(min_len) - s1.charAt(min_len-1);;
            return 0;
        }
    }

    private static String largestNumber(String[] a) {
        Arrays.sort(a, new StrComparator());
        
        String result = "";
        for (int i = 0; i < a.length; i++) {
            result += a[i];
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String[] a = new String[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.next();
        }
        System.out.println(largestNumber(a));
    }
}

