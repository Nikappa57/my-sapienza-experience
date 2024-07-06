public class Labirinto {

    private static enum Cella { VUOTA, PIENA };

    private int n;
    private Cella m[][];
    private boolean marcata[][];

    public Labirinto(int n) {
        this.n = n;
        this.m = new Cella[n][n];
        this.marcata = new boolean[n][n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                m[i][j] = Cella.VUOTA;
                marcata[i][j] = false;
            }
    }

    public void setPiena(int r, int c) {
        m[r][c] = Cella.PIENA;
    }

    private boolean uscita(int r, int c) {
        return ((r == n - 1) && (c == n - 1));
    }

    public boolean percorribile(int r, int c) {
        return ((r >= 0) && (r < n) && (c >= 0) && (c < n)
            && (marcata[r][c] == false) && (m[r][c] == Cella.VUOTA));
    }

    private boolean uscitaRaggiungibileDa(int r, int c) {
        if (!percorribile(r, c))
        {
            System.out.println("Non percorribile: " + r + " " + c);
            return (false);
        }

        marcata[r][c] = true;

        if (uscita(r, c))
            return (true);

        if (uscitaRaggiungibileDa(r - 1, c)
            || uscitaRaggiungibileDa(r + 1, c)
            || uscitaRaggiungibileDa(r, c - 1)
            || uscitaRaggiungibileDa(r, c + 1)) {
                return true;
            }
        marcata[r][c] = false;
        return false;
    }

    public boolean risolvibile() {
        return uscitaRaggiungibileDa(0, 0);
    }

    public String toString() {
        String s = "";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (m[i][j] == Cella.PIENA)
                    s += "#";
                else if (marcata[i][j])
                    s += "+";
                else
                    s += ".";
            }
            s += "\n";
        }
        return (s);
    }
}
