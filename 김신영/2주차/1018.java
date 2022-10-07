import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    final static int MAX_X = 8;
    final static int MAX_Y = 8;

    public int solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int x = Integer.parseInt(input[0]);
        int y = Integer.parseInt(input[1]);

        char[][] board = new char[x][y];

        for (int i = 0; i < x; i++) {
            String inputByRow = br.readLine();
            for (int j = 0; j < y; j++) {
                board[i][j] = inputByRow.charAt(j);
            }
        }

        int xRange = x - 8;
        int yRange = y - 8;

        int answer = Integer.MAX_VALUE;

        for (int i = 0; i < xRange + 1; i++) {
            for (int j = 0; j < yRange + 1; j++) {
                char[][] subBoard = extractBoard(board, i, j);
                int diff = countDiff(subBoard);
                if (diff < answer) {
                    answer = diff;
                }
            }
        }

        return answer;
    }

    private int countDiff(char[][] subBoard) {
        char[] startWithW = new char[MAX_X];
        char[] startWithB = new char[MAX_X];

        for (int i = 0; i < MAX_X; i++) {
            if (i % 2 == 0) {
                startWithW[i] = 'W';
                startWithB[i] = 'B';
            } else {
                startWithW[i] = 'B';
                startWithB[i] = 'W';
            }
        }

        int diffNumWithW = 0;
        int diffNumWithB = 0;

        for (int i = 0; i < MAX_X; i++) {
            for (int j = 0; j < MAX_Y; j++) {
                if (i % 2 == 0) {
                    if (subBoard[i][j] != startWithW[j]) {
                        diffNumWithW++;
                    }
                    if (subBoard[i][j] != startWithB[j]) {
                        diffNumWithB++;
                    }
                }
                else {
                    if (subBoard[i][j] != startWithB[j]) {
                        diffNumWithW++;
                    }
                    if (subBoard[i][j] != startWithW[j]) {
                        diffNumWithB++;
                    }
                }
            }
        }

        return Math.min(diffNumWithB, diffNumWithW);
    }

    private char[][] extractBoard(char[][] board, int startX, int startY) {
        char[][] subBoard = new char[MAX_X][MAX_Y];

        for (int i = 0; i < MAX_X; i++) {
            for (int j = 0; j < MAX_Y; j++) {
                subBoard[i][j] = board[startX + i][startY + j];
            }
        }

        return subBoard;
    }

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        System.out.println(main.solution());
    }
}
