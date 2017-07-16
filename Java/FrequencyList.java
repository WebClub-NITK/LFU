package lfu;
import java.util.LinkedList;
import java.util.ListIterator;

class FrequencyList<T> {
	int frequency;
	LinkedList<T> list;

	FrequencyList(){
		list = new LinkedList<T>();
	}
	FrequencyList(int f){
		list = new LinkedList<T>();
		frequency = f;
	}

	public void add(T t){
		list.add(t);
	}

	public void remove(T t){
		list.remove(t);
	}

	public ListIterator<T> listIterator(int index){
		return list.listIterator(index);
	}	

	public int size(){
		return list.size();
	}

	public T get(int index){
		return list.get(index);
	}

	public int getFrequency(){
		return frequency;
	}
}