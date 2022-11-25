import java.io.*;
import java.util.*;

public class Boj11286 {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(input.readLine());
        PriorityQueue<Integer> q = new PriorityQueue<>((a, b) -> {
            if (Math.abs(a) == Math.abs(b))
                return a - b;
            else
                return Math.abs(a) - Math.abs(b);});

        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(input.readLine());
            if (num == 0) {
                if (q.isEmpty())
                    output.write("0\n");
                else
                    output.write(q.remove() + "\n");
            }
            else
                q.add(num);
        }
        input.close();
        
        output.flush();
        output.close();
    }
}