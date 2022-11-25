import java.io.*;
import java.util.*;

public class Boj1715 {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(input.readLine());
        PriorityQueue<Integer> q = new PriorityQueue<>();
        int sum = 0;

        for (int i = 0; i < n; i++)
            q.add(Integer.parseInt(input.readLine()));
        input.close();
        
        if (n > 1) {
            while (q.size() > 2) {
                int a = q.remove();
                int b = q.remove();
                sum += a + b;
                q.add(a + b); // 두 카드를 비교한 횟수가 다른 조합보다 클 수도 있으니 다시 큐에 집어넣는다...
            }
            sum += q.remove() + q.remove();
        } else
            sum = 0;

        output.write(sum + "");
        output.flush();
        output.close();
    }
}