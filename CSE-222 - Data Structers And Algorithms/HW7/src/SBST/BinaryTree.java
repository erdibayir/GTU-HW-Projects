package SBST;
import java.io.Serializable;
/**
 * Class for a binary tree that stores type E objects
 * @param <E> The type of data to be stored
 */

public class BinaryTree<E> implements Serializable{
    /** Class for a binary tree that stores type E objects */
    protected Node<E> root;

    /**
     * Default Binary Tree constructor for assign root to null
     */
    public BinaryTree(){ root = null;
    }
    protected BinaryTree(Node<E> root){ this.root = root; }

    /**
     *  Constructs a new binary tree with data in its root, leftTree as its left subtree, and rightTree as its right subtree
     * @param data The data of the root node
     * @param leftTree The left subtree
     * @param rightTree The right subtree
     */
    public BinaryTree(E data, BinaryTree<E> leftTree, BinaryTree<E> rightTree){
        root = new Node<>(data);

        if(leftTree != null)
            root.left = leftTree.root;
        else
            root.left = null;

        if(rightTree != null)
            root.right = rightTree.root;
        else
            root.right = null;
    }

    /**
     * Determine root of Binary tree
     * @return Return root of Binary tree
     */
    public Node<E> getRoot() {
        return root;
    }

    /**
     * Determine the left subtree of Binary Tree
     * @return Return left tree if is not , otherwise null
     */
    public BinaryTree<E> getLeftSubtree(){
        if(root != null && root.left != null)
            return new BinaryTree<>(root.left);
        else
            return new BinaryTree<>(null);
    }
    /**
     * Determine the right subtree of Binary Tree
     * @return Return right tree if is not , otherwise null
     */
    public BinaryTree<E> getRightSubtree(){
        if(root != null && root.right != null)
            return new BinaryTree<>(root.right);
        else
            return new BinaryTree<> (null);
    }

    /**
     * Determine root is leaf or not
     * @return Return true if the root is leaf otherwise false
     */
    public boolean isLeaf(){
        return root == null || (root.left == null && root.right == null);
    }

    /**
     * toString override method
     * @return Return string builder for binary tree
     */
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        preOrderTraverse(root, 1, sb);
        return sb.toString();
    }

    /**
     * Perform a preorder traversal
     * @param node The local root
     * @param depth The depth
     * @param sb The string buffer to save the output
     */
    private void preOrderTraverse(Node<E> node, int depth, StringBuilder sb){
        for(int i = 1; i < depth; i++){
            sb.append("  ");
        }
        if(node == null)
            sb.append("-\n");
        else{
            sb.append(node.toString());
            sb.append("\n");
            preOrderTraverse(node.left, depth + 1, sb);
            preOrderTraverse(node.right, depth + 1, sb);
        }
    }

    /**
     * Perform a preorder traversal, returning the tree as one line
     * @param node The local root
     * @param sb The string bufer to save the output
     */
    private void preOrderTraverseOneLine(Node<E> node, StringBuilder sb){
        if(node == null)
            return;

        sb.append(node.toString());
        sb.append(" ");
        preOrderTraverseOneLine(node.left, sb);
        preOrderTraverseOneLine(node.right, sb);
    }

    protected static class Node<E> implements Serializable{

        /** The information stored in this node */
        protected E data;
        /** Reference to the left child */
        public Node<E> left;
        /** Reference to the right child */
        protected Node<E> right;

        /**
         * Construct a node with given data and no children
         * @param data The data to store in this node
         */
        public Node(E data){
            this.data = data;
            left = null;
            right = null;
        }

        /**
         * Determine left node
         * @return Return left node
         */
        public Node<E> getLeft() {
            return left;
        }

        /**
         * Determine right node
         * @return Return right node
         */
        public Node<E> getRight() {
            return right;
        }

        /**
         * Determine data of node
         * @return Return data of node
         */
        public E getData() {
            return data;
        }

        /**
         * Return a string representation of the node
         * @return A string representation of the data fields
         */
        public String toString(){ return data.toString(); }
    }
}