public class MaxGap {

    public static int maxGap(int[] array, int start, int end) {
        int len = end - start;
        if (len == 2)
            return array[end - 1] - array[start];
        else if (len < 2)
            return 0;
        return Math.max(
            maxGap(array, start, start + len / 2),
            maxGap(array, start + len / 2, end));
    }
}
