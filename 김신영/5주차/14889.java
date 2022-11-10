import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    int answer;
    int n;
    int[][] abilityArray;
    int arraySum = 0;
    int halfN;

    public int solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());

        n = Integer.parseInt(stringTokenizer.nextToken());
        halfN = n / 2;
        abilityArray = new int[n][n];

        for (int i = 0; i < n; i++) {
            stringTokenizer = new StringTokenizer(br.readLine());
            for (int j = 0; i < n; j++) {
                if (stringTokenizer.hasMoreTokens()) {
                    int temp = Integer.parseInt(stringTokenizer.nextToken());
                    abilityArray[i][j] = temp;
                    arraySum += temp;
                } else {
                    break;
                }
                //여기 왜 이래
            }
        }

        answer = arraySum;
        boolean[] visited = new boolean[n];
        visited[0] = true;
        combination(1, visited, 1);

        return answer;
    }

    private void combination(int depth, boolean[] visited, int index) {
        if (depth == halfN) {
            int start = 0;
            int link = 0;

            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int ij = abilityArray[i][j];
                    int ji = abilityArray[j][i];
                    if (!visited[i] && !visited[j]) {
                        link += ji + ij;
                    } else if (visited[i] && visited[j]) {
                        start += ji + ij;
                    }
                }
            }
            int diff = Math.abs(start - link);
            answer = Math.min(answer, diff);

            return;
        }

        for (int i = index; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                depth += 1;
                index = i;
                combination(depth, visited, index);
                visited[i] = false;
                depth -= 1;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        Main startAndLink = new Main();
        System.out.println(startAndLink.solution());
    }
}
