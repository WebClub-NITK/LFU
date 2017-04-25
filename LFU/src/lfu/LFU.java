package lfu;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.HashMap;

/**
 * @author salman
 * @param <T>
 */
public class LFU<T> {

        private int MAX_SIZE = 2;
    
	private LinkedList< FrequencyList<T> > lfuList;
	private HashMap<T, Pair<Integer, ListIterator<T> > > nodeFrequencyMap;
	private HashMap<Integer, ListIterator< FrequencyList<T> > > frequencyMap;
	private int count = 0;

        public void init() {
            lfuList = new LinkedList< FrequencyList<T> >();
            nodeFrequencyMap = new HashMap<T, Pair<Integer, ListIterator<T> > >();
            frequencyMap = new HashMap<Integer, ListIterator< FrequencyList<T> > >();
            count = 0;
        }
        
        LFU(){
            init();
        }
        
        LFU(int size){
            MAX_SIZE = size;
            init();
        }
        
	public void insert(T item){
                if(count >= MAX_SIZE)
                    delete();
		// If frequencyList is empty
		if(!frequencyMap.containsKey(1)){
			lfuList.listIterator(0).add(new FrequencyList(1));
			frequencyMap.put(1, lfuList.listIterator(0));
		}
                ListIterator< FrequencyList<T> > fListIt = frequencyMap.get(1);
                FrequencyList<T> frequencyList = fListIt.next();
                fListIt.previous();
                frequencyList.listIterator(frequencyList.size()).add(item);

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
		int frequency          = nodeFrequencyMap.get(item).first;
		ListIterator<T> nodeIt = nodeFrequencyMap.get(item).second;
		ListIterator< FrequencyList<T> > fListIt = frequencyMap.get(frequency);
		FrequencyList<T> frequencyList = fListIt.next();
                fListIt.previous();
                System.out.println(item + " " + frequency + " " + frequencyList.getFrequency() + " " + fListIt);
		// Remove Item from current frequencyList
		nodeIt.next();
                nodeIt.previous();
		nodeIt.remove();
		// Check if frequencyList is empty
		if(frequencyList.size() == 0){
			// Clean Up
			frequencyMap.remove(frequencyList.getFrequency());
			fListIt.remove();
		}
		// Add item to list frequency + 1
		frequency++;
		// If frequencyList is empty
		if(!frequencyMap.containsKey(frequency)){
			fListIt.add(new FrequencyList(frequency));
                        fListIt.previous();
			frequencyMap.put(frequency, fListIt);
		}
		frequencyList = fListIt.next();
                fListIt.previous();
		frequencyList.listIterator(frequencyList.size()).add(item);
		// Update item frequency
		nodeIt = frequencyList.listIterator(frequencyList.size() - 1);
		nodeFrequencyMap.put(item, new Pair(frequency, nodeIt));
                return true;
	}

	public T delete(){
		ListIterator< FrequencyList<T> > fListIt = lfuList.listIterator(0);
		FrequencyList<T> frequencyList = fListIt.next();
                fListIt.previous();
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
                System.out.println("Deleted "+item);
		return item;
	}
        
        public static void main(String args[]) {
            LFU<Integer> freqlfu = new LFU();
            freqlfu.insert(10);
            System.out.println(freqlfu.lookup(10));
            System.out.println(freqlfu.lookup(10));
            System.out.println(freqlfu.lookup(20));
//            System.out.println(freqlfu.lookup(20));
            System.out.flush();
            System.out.println(freqlfu.lookup(10));
        }
}
