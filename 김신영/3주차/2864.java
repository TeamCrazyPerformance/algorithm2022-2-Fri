import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    int min, max;
    public void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] string = br.readLine().split(" ");

        for (int i = 0; i < 2; i++) {
            min += Integer.parseInt(makeMin(string[i]));
            max += Integer.parseInt(makeMax(string[i]));
        }

        System.out.println(min + " " + max);
    }

    public String makeMin(String str) {
        str = str.replace("6", "5");
        return str;
    }

    public String makeMax(String str) {
        str = str.replace("5", "6");
        return str;
    }

    public static void main(String[] args) throws Exception {
        Main fiveOrSix = new Main();
        fiveOrSix.solution();
    }
}
