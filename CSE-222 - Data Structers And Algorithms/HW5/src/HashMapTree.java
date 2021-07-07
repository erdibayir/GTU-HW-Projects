import java.util.Arrays;
import java.util.TreeSet;

/**
 * @author Erdi Bayır
 * @since 12.05.2021
 * Hash Map Class using Tree Set to chain items.
 * @param <K> Key Value of Entry
 * @param <V> Value of Entry
 */
public class HashMapTree<K extends Comparable<K>, V extends Comparable<V>> implements KWHashMap<K, V> {
    private TreeSet<Entry<K, V>>[] table;
    private int numKeys;
    private static final int CAPACITY = 10;
    private static final double LOAD_THRESHOLD = 3.0;

    /**
     * Zero parameter constructor.It creates table.
     */
    public HashMapTree() {
        table = new TreeSet[CAPACITY];
    }

    /** Get method for class HashtableTree.
     @param key The key
     @return The value associated with this key if found,otherwise, null
     */
    @Override
    public V get(Object key) {
        int index = key.hashCode() % table.length;

        if (index < 0)
            index += table.length;
        if (table[index] == null)
            return null;
        for (Entry<K, V> nextItem : table[index]) {
            if (nextItem.getKey().equals(key))
                return nextItem.getValue();
        }
        return null;
    }
    /**
     * @return true if table is empty
     */
    @Override
    public boolean isEmpty() {
        return size()==0;
    }

    /** Put method for class HashtableTree.
     @param key The key of item being inserted
     @param value The value for this key
     @return The old value associated with this key if found,otherwise, null
     */
    @Override
    public V put(K key, V value) {
        int index = key.hashCode() % table.length;
        if (index < 0)
            index += table.length;
        if (table[index] == null) {
            table[index] = new TreeSet<>();
        }
        for (Entry<K, V> nextItem : table[index]) {
            if (nextItem.getKey().equals(key)) {
                V oldVal = nextItem.getValue();
                nextItem.setValue(value);
                return oldVal;
            }
        }
        table[index].add(new Entry<>(key, value));
        numKeys++;
        if (numKeys > (LOAD_THRESHOLD * table.length))
            rehash();
        return null;
    }

    /**
     * Rehash method for class HashtableChain.
     * It extend table if the desired conditions occur
     */
    private void rehash() {
        TreeSet<Entry<K, V>>[] oldTable = table;
        table = new TreeSet[(CAPACITY *2) +1];
        numKeys = 0;
        for (int i = 0; i < oldTable.length; i++) {
            if ((oldTable[i] != null)) {
                table[i].addAll(oldTable[i]);
            }
        }
    }
    /**
     * Removes element from table
     * @param key removed element
     * @return If element is in the table ,it returns value of element, otherwise null.
     */
    @Override
    public V remove(Object key) {
        int index = key.hashCode() % table.length;
        if(index<0){
            index += table.length;
        }
        if (table[index] == null){
            return null;
        }

        for (Entry<K, V> nextItem : table[index]) {
            if (nextItem.getKey().equals(key)) {
                V oldVal = nextItem.getValue();
                table[index].remove(nextItem);
                if(table[index].size() == 0) {
                    table[index] = null;
                }
                return oldVal;
            }
        }

        return null;
    }
    /**
     * toString method override
     * @return return table toString
     */
    @Override
    public String toString() {
        return Arrays.toString(table);
    }

    /**
     * @return size of table.
     */
    @Override
    public int size() {
        return table.length;
    }

    /**
     * Entry class for keep key and value for hash map.
     * @param <K> key value of Entry
     * @param <V> value of Entry
     */
    private static class Entry<K extends Comparable<K>,V extends Comparable<V>> implements Comparable<Entry<K,V>>  {

        private final K key;
        private V value;
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
            inTable = true;
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

        /**
         * toString method override for return Entry
         * @return Return Entry info with string
         */
        @Override
        public String toString() {
            return "Entry{" +
                    "key=" + key +
                    ", value=" + value +
                    '}';
        }
    }
}
