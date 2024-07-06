
public class MatriceSparsa {

	private int getElemIndex(int i, int j) {
		return i * this.c + j;
	}

	private class Elem{
		int i;
		int j;
		int x;
		Elem next;
		
		Elem() {
			this.i = 0;
			this.j = 0;
			this.x = 0;
			this.next = null;
		}

		Elem(int i, int j, int x) {
			this.i = i;
			this.j = j;
			this.x = x;
			this.next = null;
		}

		Elem(int i, int j, int x, Elem next) {
			this.i = i;
			this.j = j;
			this.x = x;
			this.next = next;
		}

		public int index() {
			return getElemIndex(i, j);
		}
	}

	private int r;
	private int c;
	Elem head;


	public MatriceSparsa(int m, int n) {
		this.r = m;
		this.c = n;
		head = null;
	}

	public int getNumRow() {
		return r;
	}

	public int getNumCol() {
		return c;
	}

	public void set(int i, int j, int x) {
		int index = getElemIndex(i, j);

		if (this.head == null || this.head.index() > index) {
			if (x != 0)
				this.head = new Elem(i, j, x, this.head); // add
			return ;
		}

		for (Elem e = this.head; ; e = e.next) {
			if (e.i == i && e.j == j) {
				if (x == 0)
					e = e.next; // delete
				else
					e.x = x;	// update
				return ;
			}
			else if ((e.next == null) || (e.next.index() > index)) {
				if (x != 0)
					e.next = new Elem(i, j, x, e.next); // add
				return ;
			}
		}
	}

	public int get(int i, int j) {
		if (this.head == null)
			return (0);
		for (Elem e = this.head; e != null; e = e.next) {
			if (e.i == i && e.j == j)
				return e.x;
			if (e.index() > getElemIndex(i, j))
				return 0;
		}
		return 0;
	}

	public String toString() {
		String s = "";
		for (int i = 0; i < this.r; i++) {
			for (int j = 0; j < this.c; j++)
				s += this.get(i, j) + " ";
			s += "\n";
		}
		return s;
	}

	private Elem append(Elem curr, Elem e)
	{
		if (head == null)
			curr = head = e;
		else
			curr = curr.next = e;
		return curr;
	}

	public MatriceSparsa add(MatriceSparsa mat1, MatriceSparsa mat2) {
		if (mat1.c != mat2.c || mat1.r != mat2.r)
			return null;
		MatriceSparsa result = new MatriceSparsa(mat1.r, mat1.c);

		Elem e1 = mat1.head;
		Elem e2 = mat2.head;
		Elem curr = null;

		while ((e1 != null) && (e2 != null)) {
			if (e1.i == e2.i && e1.j == e2.j) {
				if (e1.x + e2.x != 0)
					curr = result.append(curr,
						new Elem(e1.i, e1.j, e1.x + e2.x));
				e1 = e1.next;
				e2 = e2.next;
			}
			else if (e1.index() < e2.index()) {
				curr = result.append(curr, new Elem(e1.i, e1.j, e1.x));
				e1 = e1.next;
			}
			else {
				curr = result.append(curr, new Elem(e2.i, e2.j, e2.x));
				e2 = e2.next;
			}
		}
		while (e1 != null) {
			curr = result.append(curr, new Elem(e1.i, e1.j, e1.x)); 
			e1 = e1.next;
		}
		while (e2 != null) {
			curr = result.append(curr, new Elem(e2.i, e2.j, e2.x)); 
			e2 = e2.next;
		}

		return result;
	}

	public MatriceSparsa tra(MatriceSparsa mat) {
		MatriceSparsa result = new MatriceSparsa(mat.c, mat.r);
		
		for (Elem e = result.head; e != null; e = e.next)
			result.set(e.j, e.i, e.x);

		return result;
	}

	public MatriceSparsa mul(MatriceSparsa mat1, MatriceSparsa mat2) {
		MatriceSparsa result = new MatriceSparsa(mat1.r, mat2.c);
		if (mat1.c != mat2.r)
			return null;
		for (int i = 0; i < mat1.r; i++) {
			for (int j = 0; j < mat2.c; j++) {
				int sum = 0;
				for (int k = 0; k < mat1.c; k++)
					sum += mat1.get(i, k) * mat2.get(k, j);
				result.set(i, j, sum);
			}
		}
		return result;
	}
}
