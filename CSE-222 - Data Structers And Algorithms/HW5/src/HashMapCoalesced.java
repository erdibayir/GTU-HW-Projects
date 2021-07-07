import java.util.Arrays;
import java.util.Iterator;

/**
 * @author Erdi Bayır
 * @since 12.05.2021
 * Coalesced Hash Map Class.
 * @param <K> Key Value of Entry
 * @param <V> Value of Entry
 */
public class    HashMapCoalesced<K extends Comparable<K>,V extends Comparable<V>>  implements KWHashMap<K,V>{
    private Entry<K, V>[] table;
    private static final int START_CAPACITY = 10;
    private double LOAD_THRESHOLD = 0.75;
    private int numKeys;
    private int numDeletes;
    private final Entry<K, V> DELETED = new Entry<>(null, null);
    // Constructor
    public HashMapCoalesced() {
        table = new Entry[START_CAPACITY];
    }

    /** Find target key for put element to table.
     @param key Key value of entry
     @return The position of the target or the first empty slot if
     the target is not in the table.
     */
    private int find(Object key) {
        int k = 1;
        int index = key.hashCode()% table.length;
        boolean loopCheck = false;
        if (index < 0)
            index += table.length;

        int orjIndex = index;
        while ((table[index] != null)
                && (!key.equals(table[index].getKey()))) {
            loopCheck = true;
            index = (index + k) % table.length;
            k += 2;
            if (index >= table.length)
                index = 0;
        }
        if (loopCheck){
            Entry<K,V> temp = table[orjIndex];
            while (temp.next != - 1){
                orjIndex = temp.next;
                temp = table[temp.next];
            }
            table[orjIndex].next = index;
        }
        return index;
    }

    /** Method get for class HashMapCoalesced.
     @param key Key value of entry
     @return the value associated with this key if found,otherwise, null
     */
    @Override
    public V get(Object key) {
        int index = find(key);
        if (table[index] != null)
            return table[index].getValue();
        else
            return null; // key not found.
    }

    /**
     * @return true if table has not any element.
     */
    @Override
    public boolean isEmpty() {
        return numKeys == 0;
    }

    /** Method put for class HashMapCoalesced.Put the key to table.
     @param key The key of item being inserted
     @param value The value for this key
     @return Old value associated with this key if found,otherwise, null
     */
    @Override
    public V put(K key, V value) {
        int index = find(key);
        if (table[index] == null) {
            table[index] = new Entry<>(key, value);
            numKeys++;
            double loadFactor = (double) (numKeys + numDeletes) / table.length;
            if (loadFactor > LOAD_THRESHOLD)
                rehash();
            return null;
        }
        V oldVal = table[index].getValue();
        table[index].setValue(value);
        return oldVal;
    }

    /**
     * Expands table size when loadFactor exceeds LOAD_THRESHOLD
     */
    private void rehash() {
        Entry<K, V>[] oldTable = table;
        table = new Entry[2 * oldTable.length + 1];
        numKeys = 0;
        numDeletes = 0;
        for (int i = 0; i < oldTable.length; i++) {
            if ((oldTable[i] != null) && (oldTable[i] != DELETED)) {
                put(oldTable[i].getKey(), oldTable[i].getValue());
            }
        }
    }

    /**
     * Find index for remove method
     * @param key Key of the search element
     * @return Return founded index ,otherwise -1
     */
    private int findForRemove(Object key){
        for(int i = 0 ; i < table.length ; i++){
            if( table[i] != null && key.equals(table[i].getKey()))
                return i;
        }
        return -1;
    }

    /**
     * This function removes the element from table
     * @param key of removed element
     * @return if element is in the table , returns removed element data
     */
    @Override
    public V remove(Object key) {
        int index = findForRemove(key);
        if(index == -1 || table[index] == null){
            return null;
        }
        V temp = table[index].getValue();
        Entry<K,V> tempH = table[index];
        int lastIndex = index;
        while (tempH.next != -1){
            table[lastIndex] = table[tempH.next];
            table[lastIndex].next = table[tempH.next].next;
            lastIndex = tempH.next;
            tempH = table[lastIndex];
        }
        table[lastIndex] = DELETED;
        numDeletes++;
        numKeys--;
        return temp;
    }

    /**
     * @return size of table
     */
    @Override
    public int size() {
        return numKeys;
    }

    /**
     * toString method override
     * @return Return table elements string.
     */
    @Override
    public String toString() {
        return Arrays.toString(table);
    }

    /**
     * Print table to program terminal.
     */
    public void printTable(){
        System.out.format("%4s   %6s   %5s\n","Hash","Key","Next");
        String nextS = "";
        for (int i = 0 ; i < table.length;i++){
            if(table[i] == null || table[i].key == null)
            System.out.format("%4s   %6s   %5s\n",i,"","NULL");
            else {
                if (table[i].next == -1)
                    nextS = "NULL";
                else
                    nextS = String.valueOf(table[i].next);
                System.out.format("%4s   %6s   %5s\n", i, table[i].key, nextS);
            }
        }
        System.out.println();
    }

    /**
     * Create Map iterator method with zero parameter
     * @return Return new map iterator
     */
    public MapIterator iterator() {
        return new MapIterator<K>();
    }

    /**
     * Create Map iterator method with key parameter
     * @param key Key of the entry
     * @return Return new map iterator
     */
    public MapIterator iterator(K key) {
        return new MapIterator<K>(key);
    }

    /**
     * Custom iterator class for Hash map
     * @param <K> key of the entry
     */
    public class MapIterator<K> implements Iterator<K>{
        private K current;

        /**
         * Zero parameter constructor.It starts from any key in map
         */
        public MapIterator(){
            for (int i = 0 ; i < table.length;i++){
                if(table[i] != null) {
                    current = (K) table[i].key;
                    break;
                }
            }
        }

        /**
         * Key parameter constructor . Iterator start from the given key.
         * @param key Key of the Entry
         */
        public MapIterator(K key){
            int index = findForRemove(key);
            if(table[index] == null){
                new MapIterator();
            }
            current = key;
        }

        /**
         *
         * @return The method returns true if there are still not-iterated key/s in the Map, otherwise,returns False
         */
        @Override
        public boolean hasNext() {
            if (current == null)
                return false;
            if(numKeys > 1) {
                int index = findForRemove(current);
                for(int i = index + 1 ; i < table.length ; i++){
                    if(table[i] != null)
                        return true;
                }
            }
            return false;
        }

        /**
         * The iterator points to the previous key in the Map.
         * @return Return previous key
         */
        public K prev(){
            if (current == null)
                return null;
            int index = findForRemove(current);
            if(numKeys > 1) {
                for (int i = index - 1 ; i % table.length != index; i--){
                    if(i < 0){
                        i = table.length -1;
                    }
                    if (table[i] != null){
                        current = (K) table[i].key;
                        return current;
                    }
                }
            }
            return null;
        }

        /**
         * The iterator points to the next key in the Map.
         * @return It returns the next key in the Map
         */
        @Override
        public K next() {
            if (current == null)
                return null;
            if(hasNext()){
                int index = findForRemove(current);
                for(int i = index + 1 ; i % table.length != index ; i++){
                    if(table[i % table.length] != null) {
                        current = (K) table[i % table.length].key;
                        return (K) table[i % table.length].key;
                    }
                }
            }
            return null;
        }
    }

    /**
     * Entry class for keep key and value for hash map.
     * @param <K> key value of Entry
     * @param <V> value of Entry
     */
    static class Entry<K extends Comparable<K>,V extends Comparable<V>> implements Comparable<Entry<K,V>>  {

        private final K key;
        private V value;
        private int next;
        public boolean inTable;

        /**
         * @return Return true if inTable is true otherwise false
         */
        public boolean isInTable() {
            return inTable;
        }
        /**
         * Return key
         * @return Return key
         */
        public K getKey() {
            return key;
        }

        /**
         * Return value
         * @return Return value
         */
        public V getValue() {
            return value;
        }
        /**
         * Return next
         * @return Return next
         */
        public int getNext() {
            return next;
        }

        /**
         * Set next with new next
         * @param next new next parameter
         */
        public void setNext(int next) {
            this.next = next;
        }
        /**
         * Set value with new value
         * @param value new value parameter
         */
        public void setValue(V value) {
            this.value = value;
        }
        /**
         * Create new Entry with key and value
         * @param key key  of Entry
         * @param value value of Entry
         */
        public Entry(K key , V value){
            this.key = key;
            this.value = value;
            next = - 1;
            inTable = true;
        }

        /**
         * toString method override for return Entry
         * @return Return Entry info with string
         */
        @Override
        public String toString() {
            String all = "";
            all += "Entry{" + "key=" + key + ", value=" + value;
            if (next == -1)
                all += " next= null}";
            else
                all += " next= " + next;
            return all ;
        }
        /**
         * compareTo method override to compare Entries
         * @param o compare Entry object
         * @return Returns a negative,zero, or a positive integer as this object is less than, equal to, or greater.
         */
        @Override
        public int compareTo(Entry<K, V> o) {
            return this.key.compareTo(o.getKey());
        }
    }
}
