import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    int height;
    int width;
    int currentX = 0;
    int currentY = 0;
    int answer = 1;

    public int solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] string = br.readLine().split(" ");
        height = Integer.parseInt(string[0]) - 1;
        width = Integer.parseInt(string[1]) - 1;

        boolean isMovePossible = false;

        if (width >= 6 && height >= 2) {
            currentX = width;
            answer += width - 2;
        } else if (canMove(width, height)) {
            isMovePossible = true;
        }

        if (isMovePossible) {
            return 4;
        }
        for (int i = 0; i < width; i++) {
            if (currentX == width) {
                break;
            }
            calAnswer();
        }

        return answer;
    }

    public boolean inRange(int x, int y) {
        if (x <= width && x >= 0 && y >= 0 && y <= height) {
            return true;
        }
        return false;
    }

    public boolean canMove(int x, int y) {
        if (x >= 4 && y >= 2) {
            return true;
        }
        if (x >= 8 && y >= 1) {
            return true;
        }
        return false;
    }

    public void calAnswer() {
        int diffX = width - currentX;
        int diffY = height - currentY;

        boolean caseOne = false;
        boolean caseTwo = false;
        boolean caseThree = false;
        boolean caseFour = false;

        if (diffX > 0 && diffY > 1 && inRange(currentX + 1, currentY + 2)) {
            int min = Math.min(diffX, diffY / 2);
            for (int i = min; i > -1; i--) {
                if (inRange(currentX + i, currentY + 2 * i)) {
                    currentX += i;
                    currentY += 2 * i;
                    answer += i;
                    diffX = width - currentX;
                    diffY = height - currentY;
                    caseOne = true;
                    break;
                }
            }
        }
        if (diffX > 0 && currentY > 1 && inRange(currentX + 1, currentY - 2)) {
            int min = Math.min(diffX, currentY / 2);
            for (int i = min; i > -1; i--) {
                if (inRange(currentX + i, currentY - 2 * i)){
                    currentX += i;
                    currentY -= 2 * i;
                    answer += i;
                    diffX = width - currentX;
                    diffY = height - currentY;
                    caseTwo = true;
                }
                break;
            }
        }
        if (diffX > 1 && diffY > 0 && inRange(currentX + 2, currentY + 1)) {
            int min = Math.min(diffX / 2, diffY);
            for (int i = min; i > -1; i--) {
                if (inRange(currentX + 2 * i, currentY + i)){
                    currentX += 2 * i;
                    currentY += i;
                    answer += i;
                    diffX = width - currentX;
                    diffY = height - currentY;
                    caseThree = true;
                    break;
                }
            }
        }
        if (diffX > 1 && currentY > 0 && inRange(currentX + 2, currentY - 1)) {
            int min = Math.min(diffX / 2, currentY);
            for (int i = min; i > -1; i--) {
                if (inRange(currentX + 2 * i, currentY - i)){
                    currentX += 2 * i;
                    currentY -= i;
                    answer += i;
                    diffX = width - currentX;
                    diffY = height - currentY;
                    caseFour = true;
                    break;
                }
            }
        }
        if (!caseOne && !caseTwo && !caseThree && !caseFour) {
            width = currentX;
        }
    }

    public static void main(String[] args) throws Exception {
        Main sickKnight = new Main();
        System.out.println(sickKnight.solution());
    }
}
