import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    int mapLength;
    int inventory;
    int time;
    int leastNum;

    public int[] solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        inventory = Integer.parseInt(input[2]);
        time = 0;

        int[] map = new int[n * m];

        for (int i = 0; i < n; i++) {
            String[] temp = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                map[i * m + j] = Integer.parseInt(temp[j]);
            }
        }

        Arrays.sort(map);

        leastNum = map[0];

        mapLength = map.length;
        for (int i = 0; i < mapLength; i++) {
            map[i] -= leastNum;
        }
        while(map[mapLength - 1] != 0) {
            int zeroNum = findZero(map);

            if (zeroNum <= 2 * (mapLength - zeroNum)) {
                if (inventory >= zeroNum) {
                    addLand(map);
                } else {
                    cutOut(map);
                }
            } else {
                if (zeroNum <= 2 * Arrays.stream(map).sum()) {
                    time += 2 * Arrays.stream(map).sum();
                    break;
                } else {
                    cutOut(map);
                }
            }
        }
        int[] answer = {time, leastNum};
        return answer;
    }

    void cutOut(int[] map) {
        for (int i = 0; i < mapLength; i++) {
            if (map[i] == map[mapLength - 1]) {
                map[i] -= 1;
                time += 2;
                inventory++;
            }
        }
    }

    void addLand(int[] map) {
        leastNum++;
        int tempTime = 0;
        for (int i = 0; i < mapLength; i++) {
            if (map[i] != 0) {
                map[i] -= 1;
                tempTime++;
            }
        }
        time += mapLength - tempTime;
        inventory -= mapLength - tempTime;
    }

    int findZero(int[] map) {
        int zeroNum = 0;
        for (int i = 0; i < mapLength; i++) {
            if (map[i] == 0) {
                zeroNum++;
            }
        }
        return zeroNum;
    }

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        int[] answer = main.solution();
        System.out.println(answer[0] + " " + answer[1]);
    }
}
