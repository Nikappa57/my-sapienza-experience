import java.util.LinkedList;
import java.util.List;

public class GraphServices<V> {
	private static int time;

	private static <V> void sweep_dfs(Graph.Node<V> u, Graph.Node<V> v) {
		if (u != null) {
			System.out.print(u.value + " -> " + v.value + " : ");
		
			if (v.state == Graph.Node.Status.UNEXPLORED)
				System.out.println("TREE");
			else if (v.state == Graph.Node.Status.EXPLORING)
				System.out.println("BACK");
			else if (v.state == Graph.Node.Status.EXPLORED)
			{
				if (u == null || v.timestamp >= u.timestamp)     // u < v
					System.out.println("FORWARD");
				else                                // u > v
					System.out.println("CROSS");
			}
		}

		if (v.state != Graph.Node.Status.UNEXPLORED)
			return ;

		v.timestamp = ++time;
		v.state = Graph.Node.Status.EXPLORING;
		for (Graph.Node<V> n: v.outEdges)
			sweep_dfs(v, n);
		v.state = Graph.Node.Status.EXPLORED;
	}

	public static <V> void sweep(Graph<V> g) {
		g.resetStatus();
		time = 0;

		for (Graph.Node<V> n: g.getNodes()) {
			sweep_dfs(null, n);
		}
	}
	
	private static <V> int dfs_top_sort(Graph.Node<V> s, LinkedList<Graph.Node<V>> l) {
		int result = 0;
		if (s.state == Graph.Node.Status.EXPLORING)
			return 1; // circle
			if (s.state == Graph.Node.Status.EXPLORED)
			return 0; // circle
		s.state =  Graph.Node.Status.EXPLORING;
		for (Graph.Node<V> n: s.outEdges) {
			result |= dfs_top_sort(n, l); // no return for be reusable
		}
		s.state = Graph.Node.Status.EXPLORED;
		s.timestamp = ++time;
		l.addFirst(s);
		return result;
	}

	public static <V> void topologicalSort(Graph<V> g) {
		LinkedList<Graph.Node<V>> list = new LinkedList<Graph.Node<V>>();

		g.resetStatus();
		for (Graph.Node<V> n: g.getNodes()) {
			if (n.state == Graph.Node.Status.UNEXPLORED) {
				if (dfs_top_sort(n, list) == 1) {
					System.out.println("Graph has a cycle");
					return ;
				}
			}
		}
		for (Graph.Node<V> n: list)
			System.out.print(n.value);
	}
	
	public static <V> void transposedNodes(Graph<V> g, LinkedList<Graph.Node<V>> list) {
		for (Graph.Node<V> n: list) {
			n.timestamp = 0;
			n.state = Graph.Node.Status.UNEXPLORED;
			for (Graph.Node<V> out: g.getOutNeighbors(n)) {
				g.removeEdge(n, out);
				g.addEdge(out, n);
			}
		}
	}

	public static <V> void strongConnectedComponents(Graph<V> g) {
		LinkedList<Graph.Node<V>> list = new LinkedList<Graph.Node<V>>();
		LinkedList<Graph.Node<V>> comps;

		g.resetStatus();
		for (Graph.Node<V> n: g.getNodes()) {
			if (n.state == Graph.Node.Status.UNEXPLORED) {
				dfs_top_sort(n, list);
			}
		}
		transposedNodes(g, list);
		System.out.println();
		for (Graph.Node<V> n: list) {
			if (n.state == Graph.Node.Status.UNEXPLORED) {
				comps = new LinkedList<Graph.Node<V>>();
				dfs_top_sort(n, comps);

				System.out.println("Strong connected component: ");
				for (Graph.Node<V> m: comps) {
					if (m.state == Graph.Node.Status.EXPLORED)
						System.out.print(m.value + " ");
				}
				System.out.println();
			}
		}
	}
}
