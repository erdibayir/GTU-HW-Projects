import java.io.Serializable;
import java.util.HashMap;

/**
 * Node Class for generic keep data.Implements Serializable Interface.
 * @param <E> The type of elements held in Node.
 */
public class Node<E> implements Serializable {
    /**
     * The information stored in this node.
     */
    protected E data;
    protected int hmAdded;
    /**
     * Reference to the left child.
     */
    protected Node<E> left;
    /**
     * Reference to the right child.
     */
    protected Node<E> right;

    /**
     * Default Constructor to make hmAdded 0
     */
    public Node(){
        hmAdded = 0;
    }
    /**
     * Construct a node with given data and no children.
     *
     * @param data The data to store in this node.
     */

    public Node(E data) {
        this.data = data;
        left = null;
        right = null;
        hmAdded = 1;
    }
    /**
     * Return a string representation of the node.
     *
     * @return A string representation of the data fields.
     */
    public String toString() {
        return data.toString();
    }
}
