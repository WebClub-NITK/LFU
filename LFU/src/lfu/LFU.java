package lfu;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.HashMap;

/**
 * @author salman
 * @param <T>
 */
public class LFU<T> {

	private LinkedList< FrequencyList<T> > lfuList;
	private HashMap<T, Pair<Integer, ListIterator<T> > > nodeFrequencyMap;
	private HashMap<Integer, ListIterator< FrequencyList<T> > > frequencyMap;
	private int count = 0;

        LFU() {
            lfuList = new LinkedList< FrequencyList<T> >();
            nodeFrequencyMap = new HashMap<T, Pair<Integer, ListIterator<T> > >();
            frequencyMap = new HashMap<Integer, ListIterator< FrequencyList<T> > >();
            count = 0;
        }
        
	public void insert(T item){
		// If frequencyList is empty
		if(!frequencyMap.containsKey(1)){
			lfuList.addFirst(new FrequencyList(1));
			frequencyMap.put(1, lfuList.listIterator(0));
		}
		FrequencyList<T> frequencyList = frequencyMap.get(1).next();
		frequencyList.add(item);
		// Update item frequency
		nodeFrequencyMap.put(item, new Pair(1, frequencyList.listIterator(frequencyList.size() - 1)));
		// Update Count
		count++;
	}

	public boolean lookup(T item){
		// If item does not exist
		if(!nodeFrequencyMap.containsKey(item)){
			insert(item);
			return false;
		}
		// If item exists
		// Get FrequencyList of item
		int frequency       = nodeFrequencyMap.get(item).first;
		ListIterator nodeIt = nodeFrequencyMap.get(item).second;
		ListIterator< FrequencyList<T> > fListIt = frequencyMap.get(frequency);
		FrequencyList<T> frequencyList = fListIt.next();
		// Remove Item from current frequencyList and nodeFrequencyMap
		nodeIt.next();
		nodeIt.remove();
		// Check if frequencyList is empty
		if(frequencyList.size() == 0){
			// Clean Up
			frequencyMap.remove(frequencyList.getFrequency());
			fListIt.remove();
			// lfuList.remove(frequencyList);
		}
		// Add item to list frequency + 1
		frequency++;
		// If frequencyList is empty
		if(!frequencyMap.containsKey(frequency)){
			fListIt.add(new FrequencyList(frequency));
			frequencyMap.put(frequency, fListIt);
		}
		frequencyList = fListIt.next();
		frequencyList.add(item);
		// Update item frequency
		nodeIt = frequencyList.listIterator(frequencyList.size() - 1);
		nodeFrequencyMap.put(item, new Pair(frequency, nodeIt));
                return true;
	}

	public T delete(){
		ListIterator< FrequencyList<T> > fListIt = lfuList.listIterator(0);
		FrequencyList<T> frequencyList = fListIt.next();
		T item = frequencyList.get(0);
		ListIterator<T> nodeIt = nodeFrequencyMap.get(item).second;
		nodeIt.next();
		nodeIt.remove();
		nodeFrequencyMap.remove(item);
		if(frequencyList.size() == 0){
			// Clean Up
			frequencyMap.remove(frequencyList.getFrequency());
			fListIt.remove();
		}
		// Update Count
		count--;
		return item;
	}
        
        public static void main(String args[]) {
            LFU<Integer> freqlfu = new LFU();
            freqlfu.insert(10);
            System.out.println(freqlfu.lookup(10));
            
            System.out.println(freqlfu.lookup(20));
        }
}
