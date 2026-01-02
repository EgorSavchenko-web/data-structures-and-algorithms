import java.util.Scanner;

public class SortingBubbleAlgorithm {
    public static void SortingBubbleAlgorithm (long[]  array ) {
        int pst = array.length;
boolean isswapped;
        do {
isswapped = false;
            for (int i = 1; i < pst; i++) {
                if (array[i - 1] > array[i]) {
                    long temp = array[i - 1];
                    array[i - 1] = array[i];
                    array[i] = temp;
                    isswapped = true;
                }
            }
            pst--;
} while (isswapped);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int pst = scanner.nextInt();
        if (pst == 0) {
            System.out.println();
            return;
        }

        long[] array = new long[pst];
        for (int i = 0; i < pst; i++) {
            array[i] = scanner.nextLong();
        }

        SortingBubbleAlgorithm(array);

        StringBuilder sb = new StringBuilder();
        for (long num : array) {
            sb.append(num).append(" ");
        }
        System.out.println(sb.toString().trim());
    }
}