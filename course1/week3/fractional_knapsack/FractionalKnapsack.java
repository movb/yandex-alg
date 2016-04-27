import java.util.Scanner;
import java.util.*;

public class FractionalKnapsack {
    private static double getOptimalValue(int capacity, int[] values, int[] weights) {
        double value = 0;
        
        double[] price = new double[values.length];
        Integer[] indexes = new Integer[values.length];
        
        for(int i=0;i<values.length;++i)
        {
            price[i] = values[i]/(double)weights[i];
            indexes[i] = i;
        }
        
        Arrays.sort(indexes, Collections.reverseOrder(Comparator.comparing((ind) -> price[ind])));
        
        for(int i=0;i<values.length;++i)
        {
            int ind = indexes[i];
            if(weights[ind]<capacity) {
                value += values[ind];
                capacity-=weights[ind];
            } else {
                value += (capacity/(double)weights[ind]) * values[ind];
                break;
            }
        }

        return value;
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int capacity = scanner.nextInt();
        int[] values = new int[n];
        int[] weights = new int[n];
        for (int i = 0; i < n; i++) {
            values[i] = scanner.nextInt();
            weights[i] = scanner.nextInt();
        }
        System.out.println(getOptimalValue(capacity, values, weights));
    }
} 
