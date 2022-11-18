import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer split = new StringTokenizer(input.readLine());

        int n = Integer.parseInt(split.nextToken());
        int m = Integer.parseInt(split.nextToken());
        int[] arr = new int[m];
        backTracking(n, m, arr, output);

        output.flush();
        output.close();
    }

    public static void backTracking(int n, int m, int[] arr, BufferedWriter output) throws IOException {
        if (m == 0) {
            for (int i = 0; i < arr.length; i++)
                output.write(arr[i] + " ");
            output.write("\n");
        }
        else {
            for (int i = 1; i <= n; i++) {
                arr[arr.length - m] = i;
                backTracking(n, m - 1, arr, output);
            }
        }
    }
}
