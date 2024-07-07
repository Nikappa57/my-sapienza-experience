import java.util.*;

public class Algoritmi {
    
     
    private static void swap_array(float[] a, int i, int j){
        float tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    
    public static void permuta_negativi_positivi(float [] a){
        int n = -1, p = a.length;

        while (p - n > 1) {
            if (a[n + 1] < 0)
                n++;
            else {
                p--;
                swap_array(a, n + 1, p);
            }
        }
    }

    private static void swap_array(char[] a, int i, int j){
        char tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    /* bandiera */

    public static int sep(char[] a, int start, char first_elem){
        int n = start - 1, p = a.length;

        while (p - n > 1) {
            if (a[n + 1] == first_elem)
                n++;
            else {
                p--;
                swap_array(a, n + 1, p);
            }
        }
        return n + 1;
    }
    
    public static void bandiera(char[] a){
        int d1 = sep(a, 0, 'v');
        sep(a, d1, 'b');
    }
    
    /* isQuadratoLatino */

    private static void arr_bzero(int[] a){
        for (int i = 0; i < a.length; i++)
            a[i] = 0;
    }


    public static boolean isQuadratoLatino(int[][] m){
        int max = m[0][0];

        for (int i = 0; i < m.length; i++) {
            for (int j = 0; j < m.length; j++) {
                if (m[i][j] > max)
                    max = m[i][j];
            }
        }
        int check[] = new int[max + 1];

        for (int c = 0; c < m.length; c++) {
            arr_bzero(check);
            for (int r = 0; r < m.length; r++) {
                if (check[m[r][c]] != 0)
                    return false;
                check[m[r][c]] = 1;
            }
        }

        for (int r = 0; r < m.length; r++) {
            arr_bzero(check);
            for (int c = 0; c < m.length; c++) {
                if (check[m[r][c]] != 0)
                    return false;
                check[m[r][c]] = 1;
            }
        }

        return true;
    }
    
    private static int partition(float a[], int p, int r) {
        float pivot = a[r];
        int l = p - 1;

        for (int i = p; i < r; i++) {
            if (a[i] <= pivot) {
                l++;
                swap_array(a, l, i);
            }
        }
        swap_array(a, l + 1, r);
        return (l + 1);
    }

    private static float get_k_elem(float a[], int k, int p, int r) {
        if (p == r)
            return a[p];
        int pivot_i = partition(a, p, r);
        if (k == pivot_i)
            return a[pivot_i];
        if (k < pivot_i)
            return get_k_elem(a, k, p, pivot_i - 1);
        return get_k_elem(a, k, pivot_i + 1, r);
    }

    public static void primiKMin(float[] a, int k){
        for (int i = 0; i < k; i++) {
            System.out.println(get_k_elem(a, i, 0, a.length - 1));
        }
    }
    
}
