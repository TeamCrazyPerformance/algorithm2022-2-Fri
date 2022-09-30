import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static int recursionNumber = 0;
    public String solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Integer n = Integer.valueOf(br.readLine());

        recursionNumber = n;
        start();
        recursion(1);
        System.out.println("라고 답변하였지.");
        return null;
    }

    public void start() {
        System.out.println("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n" +
                "\"재귀함수가 뭔가요?\"\n" +
                "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n" +
                "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n" +
                "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"");
    }

    public void recursion(int number) {
        String space = "";
        for (int i = 0; i < number; i++) {
            space += "____";
        }
        String[] stringsNormal = {"\"재귀함수가 뭔가요?\"", "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.",
                "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.",
                "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\""
        };

        String[] stringsLast = {"\"재귀함수가 뭔가요?\"", "\"재귀함수는 자기 자신을 호출하는 함수라네\""};

        String finalString = "라고 답변하였지.";

        if (recursionNumber == number) {
            for (int i = 0; i < stringsLast.length; i++) {
                System.out.println(space + stringsLast[i]);
            }
        } else {
            for (int i = 0; i < stringsNormal.length; i++) {
                System.out.println(space + stringsNormal[i]);
            }
            recursion(number + 1);
        }
        System.out.println(space + finalString);
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
