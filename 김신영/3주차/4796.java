import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    int caseNumber = 0;
    public void solution(int l, int p, int v) throws Exception {
        caseNumber += 1;
        int answer;
        if (v % p > l) {
            answer = v / p * l + l;
        } else {
            answer = v / p * l + v % p;
        }
        System.out.println("Case " + caseNumber + ": " + answer);
    }

    public void getInput() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true) {
            String string[] = br.readLine().split(" ");

            int l = Integer.parseInt(string[0]);
            int p = Integer.parseInt(string[1]);
            int v = Integer.parseInt(string[2]);

            if (l == 0) {
                break;
            }
            solution(l, p, v);
        }
    }

    public static void main(String[] args) throws Exception {
        Main camping = new Main();
        camping.getInput();
    }
}
