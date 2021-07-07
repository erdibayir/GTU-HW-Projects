package SBST;

/**
 * Search Interface for Search Tree.
 * @param <E> The element type
 */
public interface SearchTree<E>{
    /**
     * Add new element to binary tree
     * @param item new item to be inserted
     * @return  Return true
     */
    boolean add(E item);

    /**
     * Determine find operation successfully done or not
     * @param target Target to be searched
     * @return Return true if search tree contains target otherwise false
     */
    boolean contains(E target);

    /**
     * Find target element in search tree and return
     * @param target Target to be searched
     * @return Return founded element or null
     */
    E find(E target);

    /**
     * ind target element from search tree
     * @param target Target to be removed
     * @return Return True if target removed otherwise false
     */
    boolean remove(E target);
}