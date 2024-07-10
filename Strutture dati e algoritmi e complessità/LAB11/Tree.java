import org.w3c.dom.Node;

public class Tree {

	private int key;
	private Tree left;
	private Tree right;

	public Tree(int key) {
		this.key = key;
	}

	public static Tree build_1() {
		Tree n6 = new Tree(6);
		Tree n3 = new Tree(3);
		Tree n12 = new Tree(12);
		Tree n1 = new Tree(1);
		Tree n5 = new Tree(5);
		Tree n7 = new Tree(7);
		Tree n15 = new Tree(15);

		n6.left = n3;
		n6.right = n12;

		n3.left = n1;
		n3.right = n5;

		n12.left = n7;
		n12.right = n15;

		return n6;
	}

	public static Tree build_2() {
		Tree n6 = new Tree(6);
		Tree n3 = new Tree(3);
		Tree n12 = new Tree(12);
		Tree n1 = new Tree(1);
		Tree n5 = new Tree(5);
		Tree n7 = new Tree(7);
		Tree n15 = new Tree(15);

		n6.right = n3;
		n6.left = n12;

		n3.left = n1;
		n3.right = n5;

		n12.left = n7;
		n12.right = n15;

		return n6;
	}

	public static Tree build_3() {
		Tree n6 = new Tree(6);
		Tree n3 = new Tree(3);
		Tree n12 = new Tree(12);
		Tree n1 = new Tree(1);
		Tree n5 = new Tree(5);

		n6.left = n3;

		n3.left = n1;
		n3.right = n5;

		n5.right = n12;

		return n6;
	}

	public boolean isBST() {
		return isBST_aux(this);
	}

	public boolean isBalanced() {
		return isBalanced_aux(this);
	}

	public boolean isAVL() {
		return isAVL_aux(this);
	}

	private boolean isAVL_aux(Tree t) {
		if (t == null)
			return true;
		if (((t.left != null) && (t.left.key > t.key))
			|| ((t.right != null) && (t.right.key < t.key)))
			return false;
		
		int h1 = height(t.left);
		int h2 = height(t.right);

		return (Math.abs(h1 - h2) < 1
			&& isAVL_aux(t.left)
			&& isAVL_aux(t.right));
	}


	private boolean isBST_aux(Tree t) {
		if (t.left == null && t.right == null)
			return true;
		if (((t.left != null) && (t.left.key > t.key))
			|| ((t.right != null) && (t.right.key < t.key)))
			return false;
		return (isBST_aux(t.left) || isBST_aux(t.right));
	}

	private int height(Tree t) {
		if (t == null)
			return 0;
		return 1 + Math.max(height(t.left), height(t.right));
	}

	private boolean isBalanced_aux(Tree t) {
		if (t == null)
			return true;

		int h1 = height(t.left);
		int h2 = height(t.right);

		return (Math.abs(h1 - h2) < 1
			&& isBalanced_aux(t.left)
			&& isBalanced_aux(t.right));
	}

}
