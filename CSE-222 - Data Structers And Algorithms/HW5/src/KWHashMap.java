/**
 * @author Erdi Bayır
 * @since 12.05.2021
 * KWHashMap Interface.
 * @param <K> Key Value of Entry
 * @param <V> Value of Entry
 */
public interface KWHashMap <K,V>{
    V get(Object key);
    boolean isEmpty();
    V put(K key , V value);
    V remove(Object key);
    int size();
}
