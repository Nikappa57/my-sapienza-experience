import java.util.*;

public class GraphServices {

	public static <V> void bfs(Graph<V> g) {
		Queue<Node<V>> q = new LinkedList<>();

		for (Node<V> n: g.getNodes()) {
			n.state = Node.Status.UNEXPLORED;
			n.dist = Integer.MAX_VALUE;
		}

		for (Node<V> s: g.getNodes()) {
			if (s.state == Node.Status.UNEXPLORED) {
				s.state = Node.Status.EXPLORING;
				s.dist = 0;
				q.add(s);
				while (q.size() > 0) {
					Node<V> n = q.poll();

					for (Edge<V> c: g.getOutEdges(n)) {
						Node<V> out = c.getTarget();
						if (out.state == Node.Status.UNEXPLORED) {
							out.state = Node.Status.EXPLORING;
							out.dist = n.dist + 1;
							q.add(out);
						}
					}

					n.state = Node.Status.EXPLORED;
					System.out.print(n.getValue() + " (" + n.dist + ") ");
				}
			}
		}
		System.out.println();
	}

	public static <V> void sssp(Graph<V> g, Node<V> source) {
		MinHeap<Node<V>> q = new MinHeap<>();
		HashMap<Node<V>, HeapEntry<Node<V>>> h_elms = new HashMap<>();

		for (Node<V> n: g.getNodes()) {
			n.state = Node.Status.UNEXPLORED;
			n.dist = Integer.MAX_VALUE;
		}

		source.state =  Node.Status.EXPLORING;
		source.dist = 0;

		for (Node<V> n: g.getNodes())
			h_elms.put(n, q.insert(n.dist, n));

		while (q.size() > 0) {
			HeapEntry<Node<V>> elm = q.removeMin();
			Node<V> n = elm.getValue();
			
			for (Edge<V> e: g.getOutEdges(n)) {
				Node<V> out = e.getTarget();
				HeapEntry<Node<V>> h_out = h_elms.get(out);

				if (n.dist + e.getWeight() < h_out.getKey()) { // RELAX
					out.dist = n.dist + e.getWeight();
					q.replaceKey(h_out, out.dist);
				}
			}
			System.out.println(n.getValue() + " " + n.dist);
		}
	}
	
	public static <V> void mst(Graph<V> G) {
		int tot_weight = 0;
		int i = 0;
		for (Node<V> n: G.getNodes())
			n.map = i++;

		Partition<V> p = new Partition<>(G.getNodes());
		MinHeap<Edge<V>> q = new MinHeap<>();

		for (Edge<V> e: G.getEdges()) {
			q.insert(e.getWeight(), e);
		}

		while (q.size() > 0) {
			Edge<V> e = q.removeMin().getValue();
			Node<V> u = e.getSource();
			Node<V> v = e.getTarget();

			if (p.find(u.map) != p.find(v.map)) {
				p.union(u.map, v.map);
				System.out.println(u.getValue() + " - " + v.getValue() + " ");
				tot_weight += e.getWeight();
			}
		}
		System.out.println("Total weight: " + tot_weight);
	}
}
