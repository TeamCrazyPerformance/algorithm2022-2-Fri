import java.io.*;
import java.util.*;

public class Boj9663 {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(input.readLine());
        input.close();
        int[] queenColumnNum = new int[n];
        boolean[] isUsed = new boolean[n];
        Arrays.fill(queenColumnNum, -1);

        output.write(backTracking(n, 0, queenColumnNum, 0, isUsed) + "");
        output.flush();
        output.close();
    }

    public static boolean checkPlace(int row, int col, int[] arr) {
        for (int i = 1; i <= row; i++) {
            if (col + i == arr[row - i] || col - i == arr[row - i])
                return false;
        }
        return true;
    }

    public static int backTracking(int n, int m, int[] arr, int count, boolean[] check) {
        for (int i = 0; i < arr.length; i++) {
            if (check[i] == false && checkPlace(m, i, arr)) {         // 중복 선택 방지
                arr[m] = i;                                           // m번째 행의 열 번호 선택
                check[i] = true;
                /*
                for (int j = 0; j < arr.length; j++)
                    System.out.print(arr[j] + " ");
                System.out.println();
                */
                if (m == n - 1)
                    count++;
                else
                    count = backTracking(n, m + 1, arr, count, check);
                check[i] = false; 
            }
            
        }
        return count;
    }
}
