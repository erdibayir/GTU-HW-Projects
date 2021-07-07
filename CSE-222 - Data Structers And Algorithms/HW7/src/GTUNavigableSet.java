import java.util.Iterator;
/**
 * Navigable Set Interface Implementation.
 * @param <K> The element type
 */
public interface GTUNavigableSet<K> {
    /**
     * Descending Iterator For Navigable Set
     * @return Return Descending iterator
     */
    Iterator<K> descendingIterator();

    /**
     * Insert a key to Navigable Set
     * @param key c
     * @return Return true if the item inserted otherwise false
     */
    boolean insert(K key);

    /**
     * Delete a key from Navigable Set
     * @param o The object to be deleted
     * @return Return true if the item deleted otherwise false
     */
    boolean delete(Object o);

    /**
     * Determine head set of the Navigable Set
     * @param toElement parameter for determine final head set element
     * @param inclusive parameter for toElement is inclusive or not
     * @return Return head set for Navigable Set
     */
    GTUNavigableSet<K> headSet(K toElement, boolean inclusive);

    /**
     * Determine head set of the Navigable Set
     * @param fromElement parameter for determine first element for tail set
     * @param inclusive parameter for fromElement is inclusive or not
     * @return Return tail set for Navigable Set
     */
    GTUNavigableSet<K> tailSet(K fromElement, boolean inclusive);

    /**
     * Create iterator for Navigable set
     * @return Return iterator
     */
    Iterator<K> iterator();
}
