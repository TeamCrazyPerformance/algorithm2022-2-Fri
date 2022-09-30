import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {
    public static String solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String string = br.readLine();
        int[] alpaNumber = new int[26];
        String answer = "";

        HashMap<Character, Integer> map = new HashMap<>();
        String alphabet = "abcdefghijklmnopqrstuvwxyz";
        for (int i = 0; i < alphabet.length(); i++) {
            map.put(alphabet.charAt(i), i);
        }
        
        for (int i = 0; i < string.length(); i++) {
            alpaNumber[map.get(string.charAt(i))] += 1;
        }

        for (int i = 0; i < 25; i++) {
            answer += alpaNumber[i];
            answer += " ";
        }
        answer += alpaNumber[25];
        return answer;
    }

    public static void main(String[] args) throws Exception {
        System.out.println(new Main().solution());
    }
}
