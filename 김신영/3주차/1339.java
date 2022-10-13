import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public int solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] strings = new String[n];
        int answer = 0;

        HashMap<Character, Integer> hash = new HashMap<>();

        for (int i = 0; i < n; i++) {
            strings[i] = br.readLine();
        }

        for (int i = 0; i < n; i++) {
            String current = strings[i];
            for (int j = current.length() - 1; j > -1; j--) {
                Character curChar = current.charAt(j);
                int number;
                if (hash.containsKey(curChar)) {
                    number = (int) (hash.get(curChar) + Math.pow(10, current.length() - j - 1));
                    hash.replace(curChar, number);
                } else {
                    number = (int) Math.pow(10, current.length() - j - 1);
                    hash.put(curChar, number);
                }
            }
        }

        List<Integer> hashList = new ArrayList<>(hash.values());
        Collections.sort(hashList, Collections.reverseOrder());

        int hashListSize = hashList.size();
        for (int i = 0; i < hashListSize; i++) {
            answer += hashList.get(i) * (9 - i);
        }

        return answer;
    }

    public static void main(String[] args) throws Exception {
        Main termMath = new Main();
        System.out.println(termMath.solution());
    }
}
