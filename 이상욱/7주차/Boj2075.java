import java.io.*;
import java.util.*;

public class Boj2075 {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(input.readLine());
        PriorityQueue<Integer> q = new PriorityQueue<>(Collections.reverseOrder());

        for (int i = 0; i < n; i++) {
            StringTokenizer split = new StringTokenizer(input.readLine());
            for (int j = 0; j < n; j++)
                q.add(Integer.parseInt(split.nextToken()));
        }
        input.close();

        for (int i = 0; i < n - 1; i++)
            q.remove();
        
        output.write(q.poll() + "");
        output.flush();
        output.close();
    }
}