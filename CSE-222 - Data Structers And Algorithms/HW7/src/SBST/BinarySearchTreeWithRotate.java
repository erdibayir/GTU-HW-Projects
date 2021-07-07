package SBST;

/**
 * Binary Search Tree With Rotate Implementation.It extends Comparable and Binary Search Tree Class.
 * @param <E> The element type
 */
public class BinarySearchTreeWithRotate<E extends Comparable<E>> extends BinarySearchTree<E> {

    /** Method to perform a right rotation.
     * root.right.right is raised one level,
     * root.right.left does not change levels,
     * root.left is lowered one level,
     * the new root is returned.
     * @param root The root of the binary tree to be rotated
     * @return The new root of the rotated tree
     */
    protected Node<E> rotateRight( Node<E> root ) {
        if( root == null || root.left == null ) {
            return null;
        }

        Node<E> tempNode = root.left;
        root.left = tempNode.right;
        tempNode.right = root;
        return tempNode;

    }

    /** Method to perform a left rotation.
     * root.left.left is raised one level,
     * root.left.righ does not change levels,
     * root.right is lowered one level,
     * the new root is returned.
     * @param root The root of the binary tree to be rotated
     * @return The new root of the rotated tree
     */
    protected Node<E> rotateLeft( Node<E> root ) {

        if( root == null || root.right == null) {
            return null;
        }

        Node<E> tempNode = root.right;
        root.right = tempNode.left;
        tempNode.left = root;
        return tempNode;
    }
}