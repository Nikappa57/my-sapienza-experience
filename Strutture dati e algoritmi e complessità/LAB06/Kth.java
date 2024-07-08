public class Kth {
	int k;
	Heap left_heap;
	Heap right_heap;

	public Kth(int k) {
		this.k = k;
		left_heap = new Heap(Heap.HEAP_TYPE.MAX_HEAP, 100);
		right_heap = new Heap(Heap.HEAP_TYPE.MIN_HEAP, 100);
	}

	public void insert(int key) {
		if (left_heap.size() < k) {
			left_heap.add(key);
		} else {
			if (key >= get()) {
				right_heap.add(key);
			} else {
				int prev = left_heap.poll();
				left_heap.add(key);
				right_heap.add(prev);
			}
		}
	}

	public int get() {
		if (left_heap.size() < k)
			return -1;
		return left_heap.peek();
	}

	public void remove() {
		if (left_heap.size() < k)
			return ;
		left_heap.poll();
		if (right_heap.size() > 0) {
			left_heap.add(right_heap.poll());
		}
	}

}
