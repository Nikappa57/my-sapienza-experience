
public class Heap {

	public enum HEAP_TYPE {MAX_HEAP, MIN_HEAP};

	static class HeapEntry {
		private int key;
		private int position; // Indice della posizione dell'array in cui si trova l'elemento

		public HeapEntry(int key, int position) {
			this.key = key;
			this.position = position;
		}
	}

	private HeapEntry[] heap;
	private int n;	// dim max dell'arr
	private int heapSize;	// n elem presenti
	private HEAP_TYPE type;

	public Heap(HEAP_TYPE type, int capacity) {
		n = capacity;
		heapSize = 0;
		this.type = type;
		heap = new HeapEntry[n];
	}

	public HEAP_TYPE getType() {
		return type;
	}

	public int peek() {
		if (heapSize < 1)
			throw new IllegalStateException("Heap is empty");

		return heap[0].key;
	}

	private HeapEntry getEntry(int pos) {
		return heap[pos];
	}

	private int parent(int pos) {
		if (pos == 0)
			return 0;
		return (pos - 1) / 2;
	}

	private HeapEntry parent(HeapEntry e) {
		return heap[parent(e.position)];
	}

	private int left(int pos) {
		return 2 * pos + 1;
	}

	private HeapEntry left(HeapEntry e) {
		return getEntry(left(e.position));
	}

	private int right(int pos) {
		return 2 * pos + 2;
	}

	private HeapEntry right(HeapEntry e) {
		return getEntry(right(e.position));
	}

	private void swap(int pos1, int pos2) {
		HeapEntry tmp = heap[pos1];
		heap[pos1] = heap[pos2];
		heap[pos2] = tmp;
		heap[pos1].position = pos1;
		heap[pos2].position = pos2;
	}

	private boolean cmp(int e1, int e2) {
		if (type == HEAP_TYPE.MAX_HEAP)
			return e1 > e2;
		else
			return e1 < e2;
	}

	private boolean cmp(HeapEntry e1, HeapEntry e2) {
		return cmp(e1.key, e2.key);
	}


	private void heapify(int pos) {
		int elem = pos;
		int l = left(pos);
		int r = right(pos);

		if (l < heapSize && cmp(getEntry(l), getEntry(elem)))
			elem = l;
		if (r < heapSize && cmp(getEntry(r), getEntry(elem)))
			elem = r;
		if (elem != pos) {
			swap(elem, pos);
			heapify(elem);
		}
	}

	public HeapEntry add(int key) {
		if (heapSize >= n)
			throw new IllegalStateException("Heap is full");
		heapSize++;
		HeapEntry entry = new HeapEntry(
			type == HEAP_TYPE.MAX_HEAP ? Integer.MIN_VALUE : Integer.MAX_VALUE,
			heapSize - 1);
		heap[heapSize - 1] = entry;
		updateEntryKey(entry, key);
		return entry;
	}

	public int getEntryKey(HeapEntry e) {
		return e.key;
	}

	private int getKey(int pos) {
		return getEntryKey(getEntry(pos));
	}

	public int size() {
		return heapSize;
	}

	public int poll() {
		int result = peek();
		swap(0, heapSize - 1);
		heapSize--;
		heapify(0);
		return result;
	}

	public static Heap array2heap(int[] array, HEAP_TYPE type) {
		Heap h = new Heap(type, array.length);
		for (int i = 0; i < array.length; i++) {
			h.add(array[i]);
		}
		return h;
	}

	public void print() {
		
		for (int i = 0; i < heapSize; i++) {
			System.out.print(heap[i].key + " ");
		}
		System.out.println();

		// ad albero
		int i = 0;
		int j = 1;
		while (i < heapSize) {
			for (int k = 0; k < j && i < heapSize; k++) {
				System.out.print(heap[i].key + " ");
				i++;
			}
			System.out.println();
			j *= 2;
		}
	}

	public static void heapSort(int[] array) {
		Heap h = array2heap(array, HEAP_TYPE.MIN_HEAP);

		for (int i = 0; i < array.length; i++) {
			array[i] = h.poll();
		}
	}

	public void updateEntryKey(HeapEntry e, int key) {
		if (e.key == key)
			return ;
		if (cmp(e.key, key))
		{
			e.key = key;
			heapify(e.position);
		}
		else
		{
			e.key = key;
			int i = e.position;
			while (i > 0 && cmp(e, parent(e))) {
				swap(i, parent(i));
				i = parent(i);
			}
		}
		
	}

}
