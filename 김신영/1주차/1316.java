import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.util.*;

public class Main {
    public int solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int number = Integer.parseInt(br.readLine());

        int solutionNumber = 0;

        for (int i = 0; i < number; i++) {
            String string = br.readLine();
            if (isGroupWord(string)) {
                solutionNumber++;
            }
        }

        return solutionNumber;
    }

    public boolean isGroupWord(String string) {
        int stringNumber = string.length();
        ArrayList<Character> charList = new ArrayList<>();
        for (int i = 0; i < stringNumber; i++) {
            if (charList.indexOf(string.charAt(i)) == -1) {
                charList.add(string.charAt(i));
            } else {
                if (string.charAt(i) != charList.get(charList.size() - 1)) {
                    return false;
                }
            }
        }
        return true;
    }

    public static void main(String[] args) throws Exception{
        Main main = new Main();
        System.out.println(main.solution());
    }
}
