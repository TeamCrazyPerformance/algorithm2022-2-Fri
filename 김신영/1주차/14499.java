import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.util.*;

public class Main {
    public String solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] array = new int[5];
        String[] firstInputString = br.readLine().split(" ");

        for (int i = 0; i < 5; i++) {
            array[i] = Integer.parseInt(firstInputString[i]);
        }

        int n = array[0];
        int m = array[1];
        int x = array[2];
        int y = array[3];
        int k = array[4];

        int[][] map = new int[n][m];

        for (int i = 0; i < n; i++) {
            String[] mapInputString = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(mapInputString[j]);
            }
        }

        String[] moveString = br.readLine().split(" ");
        int[] moveArray = new int[k];

        for (int i = 0; i < k; i++) {
            moveArray[i] = Integer.parseInt(moveString[i]);
        }

        Dice dice = new Dice(x, y, n, m);
        for(int i = 0; i < k; i++) {
            dice.move(moveArray[i], map);
        }
        return null;
    }
    public static void main(String[] args) throws Exception {
        Main main = new Main();
        main.solution();
    }

    class Dice{
        int top = 0;
        int bottom = 0;
        int left = 0;
        int front = 0;
        int right = 0;
        int back = 0;

        int x;
        int y;

        int n;
        int m;

        Dice(int x, int y, int n, int m) {
            this.x = x;
            this.y = y;
            this.n = n;
            this.m = m;
        }

        public void move(int direction, int[][] map) {
            if(canMove(direction)) {
                int temp;
                switch (direction) {
                    case 1:
                        temp = left;
                        left = top;
                        top = right;
                        right = bottom;
                        bottom = temp;
                        break;
                    case 2:
                        temp = right;
                        right = top;
                        top = left;
                        left = bottom;
                        bottom = temp;
                        break;
                    case 3:
                        temp = back;
                        back = top;
                        top = front;
                        front = bottom;
                        bottom = temp;
                        break;
                    case 4:
                        temp = front;
                        front = top;
                        top = back;
                        back = bottom;
                        bottom = temp;
                        break;
                    default:
                        break;
                }
                if (map[x][y] == 0) {
                    map[x][y] = bottom;
                } else {
                    bottom = map[x][y];
                    map[x][y] = 0;
                }

                /*
                System.out.println("front : " + front + " top : " + top + " back : " + back + "bottom : " +
                        bottom + " left : " + left + " right : " + right);

                 */
                System.out.println(top);
            }

        }

        public boolean canMove(int direction) {
            int tempX = x;
            int tempY = y;
            switch (direction) {
                case 1:
                    tempY = tempY + 1;
                    break;
                case 2:
                    tempY = tempY - 1;
                    break;
                case 3:
                    tempX = tempX - 1;
                    break;
                case 4:
                    tempX = tempX + 1;
                    break;
                default:
                    break;
            }

            if (tempX < n && tempY < m && tempX > -1 && tempY > -1) {
                x = tempX;
                y = tempY;
                return true;
            }

            return false;
        }
    }
}
