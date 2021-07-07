/**
 * @author Erdi Bayır
 * @since 04.05.2021
 * Search Tree Interface implementation.
 * @param <E> The type of elements held in Search Tree.
 */
public interface SearchTree <E>{
    boolean add(E item);
    E find(E target);
    E delete(E target);
}