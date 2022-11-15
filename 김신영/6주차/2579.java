import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    int answer = 0;
    public int solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());
        int number = Integer.parseInt(stringTokenizer.nextToken());
        int[] array = new int[number];
        for (int i = 0; i < number; i++) {
            stringTokenizer = new StringTokenizer(br.readLine());
            int value = Integer.parseInt(stringTokenizer.nextToken());
            array[i] = value;
        }
        int[] sum = new int[number];
        /*
        sum[0] = array[0]; //0
        sum[1] = array[1] + array[0]; //10
        sum[2] = Math.max(array[1], array[0]) + array[2]; //02/12
        sum[3] = Math.max(sum[1], sum[2]) + array[3]; //310/320 -> 2 + sum[0] / sum[1]
        sum[4] = //4310/421/420 -> 3 + sum[1] / sum[2]
        sum[5] = //5421/5420/5320/5310 -> 4 + sum[2] / sum[3]
        sum[6] = //65310/65320/64310/6421/6420 -> 5 + sum[3] / sum[4]

         */

        for (int i = 0; i < number; i++) {
            if (i == 0) {
                sum[0] = array[0];
            } else if (i == 1) {
                sum[1] = array[1] + array[0];
            } else if (i == 2) {
                sum[2] = Math.max(array[1], array[0]) + array[2];
            } else {
                sum[i] = array[i] + Math.max(array[i - 1] + sum[i - 3], sum[i - 2]);
            }
        }

        return sum[number - 1];
    }

    public static void main(String[] args) throws Exception {
        Main stepUpRetry = new Main();
        System.out.println(stepUpRetry.solution());
    }
}
