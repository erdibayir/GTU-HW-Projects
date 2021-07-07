import java.io.Serializable;

/**
 * @author Erdi Bayır
 * @since 04.05.2021
 * Binary Tree Class implementation.It implements Serializable class.
 * @param <E> The type of elements held in Binary Tree.
 */
public class BinaryTree<E> implements Serializable {
    /**
     * Keep each node as Heap.
     */
    protected Node<HeapClass<E>> root;

    /**
     * Default Constructor.It makes root null.
     */
    public BinaryTree() {
        root = null;
    }

    /**
     *Create new Heap with parameter root.
     * @param root The new root to add binary tree
     */
    protected BinaryTree(Node<HeapClass<E>> root) {
        this.root = root;
    }

    /**
     * Get left sub tree of binary tree.
     * @return Return left sub tree if left sub tree is not null.
     */
    public BinaryTree<E> getLeftSubtree() {

        if (root != null && root.left != null) {
            return new BinaryTree<>(root.left);
        } else {
            return null;
        }
    }

    /**
     * Get right sub tree of binary tree.
     * @return Return right sub tree if right sub tree is not null.
     */
    public BinaryTree<E> getRightSubtree() {
        if (root != null && root.right != null) {
            return new BinaryTree<>(root.right);
        } else {
            return null;
        }
    }

    /**
     * Chech node is leaf or not.
     * @return Return tree if node is leaf.
     */
    public boolean isLeaf() {
        return (root.left == null && root.right == null);
    }

    /**
     * toString method return Binary Tree as a string
     * @return Return string builder
     */
    public String toString() {
        StringBuilder sb = new StringBuilder();
        toString(root, sb);
        return sb.toString();
    }

    /**
     * Pre-Order Traverse of Binary tree
     * @param root Root of the Binary Tree
     * @param sb String Builder Parameter
     */
    private void toString(Node<HeapClass<E>> root,StringBuilder sb) {
        if (root != null) {
            sb.append(root.data.toString());
            sb.append("\n");
            toString(root.left,sb);
            toString(root.right,sb);
        }
    }
}
