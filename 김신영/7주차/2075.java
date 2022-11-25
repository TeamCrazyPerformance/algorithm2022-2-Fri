import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    public int solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(stringTokenizer.nextToken());
        int[][] numArray = new int[n][n];
        int[] indexArray = new int[n];

        for (int i = 0; i < n; i++) {
            stringTokenizer = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                numArray[i][j] = Integer.parseInt(stringTokenizer.nextToken());
            }
            indexArray[i] = n - 1;
        }

        int answer = numArray[n - 1][0];

        for (int i = 0; i < n; i++) {
            int index = 0;
            answer = numArray[indexArray[index]][index];
            for (int j = 0; j < n; j++) {
                if (numArray[indexArray[index]][index] < numArray[indexArray[j]][j]) {
                    index = j;
                    answer = numArray[indexArray[j]][j];
                }
            }
            indexArray[index] -= 1;
        }

        return answer;
    }

    public static void main(String[] args) throws IOException {
        Main nthBigNum = new Main();
        System.out.println(nthBigNum.solution());
    }
}
