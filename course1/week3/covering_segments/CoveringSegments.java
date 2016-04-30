import java.util.*;

public class CoveringSegments {

    private static int[] optimalPoints(Segment[] segments) {
        int[] points = new int[segments.length];
        
        Arrays.sort(segments);
        int cur_index = 0;
        int max_point = Integer.MIN_VALUE;
        
        for(Segment segment: segments) {
            if(segment.start > max_point) {
                points[cur_index] = segment.end;
                max_point = segment.end;
                ++cur_index;
            }
        }
        int[] new_points = new int[cur_index];
        System.arraycopy(points, 0, new_points, 0, cur_index);
        
        return new_points;
    }

    private static class Segment implements Comparable {
        int start, end;

        Segment(int start, int end) {
            this.start = start;
            this.end = end;
        }
        
        public int compareTo(Object other)
        {
            Segment o = (Segment)other;
            return(end - o.end);
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Segment[] segments = new Segment[n];
        for (int i = 0; i < n; i++) {
            int start, end;
            start = scanner.nextInt();
            end = scanner.nextInt();
            segments[i] = new Segment(start, end);
        }
        int[] points = optimalPoints(segments);
        System.out.println(points.length);
        for (int point : points) {
            System.out.print(point + " ");
        }
    }
}
 
