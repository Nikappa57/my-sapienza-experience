import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

@SuppressWarnings("unchecked")
public class Graph<V> {
	/*
	 *	...
	*/

	private void dfs(Node<V> s) {
		if (s.state != Node.Status.UNEXPLORED)
			return ;
		s.state = Node.Status.EXPLORING;

		for (Node<V> e: s.outEdges)
			dfs(e);
		
		s.state = Node.Status.EXPLORED;
	}

	public int nConComp() {
		int n = 0;

		for (Node<V> e: nodes)
			e.state = Node.Status.UNEXPLORED;

		for (Node<V> e: nodes) {
			if (e.state == Node.Status.UNEXPLORED) {
				dfs(e);
				n++;
			}
		}
		return (n);
	}

	private void createGraphComp(Graph<V> g, Node<V> s) {
		if (s.state != Node.Status.UNEXPLORED)
			return ;

		s.state = Node.Status.EXPLORING;

		for (Node<V> e: s.outEdges)
			createGraphComp(g, e);
		
		s.state = Node.Status.EXPLORED;
		g.addNode(s.value);
	}

	public List<Graph<V>> getConComp() {
		List<Graph<V>> result = new LinkedList<Graph<V>>();
		for (Node<V> e: nodes)
			e.state = Node.Status.UNEXPLORED;

		for (Node<V> e: nodes) {
			if (e.state == Node.Status.UNEXPLORED) {
				Graph<V> g = new Graph<V>();
				createGraphComp(g, e);
				result.add(g);
			}
		}
		return result;
	}

	/* Classe interna che descrive il generico nodo del grafo */
	public static class Node<V> implements Cloneable {
		public enum Status {UNEXPLORED, EXPLORED, EXPLORING}

		protected V value;
		protected LinkedList<Node<V>> outEdges;

		protected Status state; // tiene traccia dello stato di esplorazione

		@Override
		public String toString() {
			return "Node [value=" + value + ", state=" + state + "]";
		}

		@Override
		protected Object clone() throws CloneNotSupportedException {
			return super.clone();
		}
	}
}
