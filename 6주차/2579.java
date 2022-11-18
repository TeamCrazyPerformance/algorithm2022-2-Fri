import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int n = Integer.parseInt(input.readLine());
        int[] stair = new int[n + 1];
        int[] oneStep = new int[n + 1];     // 한 칸 올라갈 떄 점수를 담은 배열
        int[] twoStep = new int[n + 1];     // 두 칸 올라갈 때 점수를 담은 배열
        for (int i = 1; i < stair.length; i++)
            stair[i] = Integer.parseInt(input.readLine());
        input.close();

        twoStep[1] = stair[1];
        for (int i = 2; i < stair.length; i++) {
            // 한 칸을 두 번 올라갈 수 없으므로 이전에 두 칸씩 올라갔을 경우의 점수에 현재 점수를 더함
            oneStep[i] = twoStep[i - 1] + stair[i];
            // 두 칸 이전까지 더한 점수의 최대값에 현재 칸의 점수를 더함
            twoStep[i] = Math.max(oneStep[i - 2], twoStep[i - 2]) + stair[i];
        }

        output.write(Math.max(oneStep[n], twoStep[n]) + "");
        output.flush();
        output.close();
    }
}
