import java.io.*;
import java.util.StringTokenizer;

public class Boj14889 {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int n = Integer.parseInt(input.readLine());
        int[][] power = new int[n + 1][n + 1];         // 플레이어의 능력치 저장할 배열
        for (int i = 1; i < power.length; i++) {
            StringTokenizer split = new StringTokenizer(input.readLine());
            for (int j = 1; j < power[i].length; j++)
                power[i][j] = Integer.parseInt(split.nextToken());
        }
    
        long a = 1;
        long b = 1;
        for (int i = 0; i < n / 2; i++) {               // 팀을 만들 수 있는 경우의 수 구하기
            a *= n - i;
            b *= i + 1;
        }
        int[] sumPower = new int[(int)(a / b) + 1];     // 플레이어의 능력치 합을 저장할 배열, 마지막 칸은 능력치의 합을 저장해야할 index 저장
                                                        // Call by value로는 재귀함수에서 값 넘겨주기가 불가능하기 때문
        int[] arr = new int[n / 2];                     // 현재 한 팀에 있는 플레이어를 저장할 배열
        backTracking(n, n / 2, arr, power, sumPower);   // 백트래킹 시작

        // 팀 능력치 차이의 최솟값 찾기
        int min = 100000000;
        for (int i = 0; i < (sumPower.length - 1) / 2; i++)
            min = Math.min(min, Math.abs(sumPower[i] - sumPower[sumPower.length - 2 - i]));     // i팀 vs (팀을 만들 수 있는 경우의 수 - i)팀
        
        output.write(min + "");
        output.flush();
        output.close();
    }

    public static void backTracking(int n, int m, int[] arr, final int[][] power, int[] sumPower) {
        // 팀이 완성되었을 경우
        if (m == 0) {
            for (int i = 0; i < arr.length; i++)
                for (int j = 0; j < arr.length; j++)
                    sumPower[sumPower[sumPower.length - 1]] += power[arr[i]][arr[j]]; // 배열 끝에 저장된 index번째 칸에 선수 능력치들의 합 저장
            sumPower[sumPower.length - 1]++;                                          // index 증가
        }
        // 팀이 완성되지 않았을 경우
        else {
            for (int i = 1; i <= n; i++) {
                if (m < arr.length && arr[arr.length - m - 1] >= i)                   // 팀 순서가 오름차순이 아닐 경우 건너뜀(중복되는 경우의 수 제거)
                    continue;
                arr[arr.length - m] = i;                                              // 팀의 k번째 칸에 플레이어 번호 저장 후
                backTracking(n, m - 1, arr, power, sumPower);                         // (k + 1)번쨰 칸에 저장할 플레이어 번호를 찾으러 함수 재귀호출
            }
        }
    }
}
