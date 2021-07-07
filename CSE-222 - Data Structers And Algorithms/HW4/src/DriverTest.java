public class DriverTest {
    public static void main(String[] args) {
        System.out.println();
        System.out.println("--- All Prints during the tests are Pre Order Traverse Form----");
        System.out.println("PART 1 ");
        System.out.println();
        System.out.println("Heap object Created...");
        HeapClass<Integer> heap1 = new HeapClass<>();
        HeapClass<Integer> heap2 = new HeapClass<>();
        System.out.println("Added some variables ...");
        heap1.add(7);
        heap1.add(15);
        heap1.add(3);
        heap1.add(4);
        heap1.add(12);
        heap1.add(19);
        heap1.add(1);
        heap1.add(6);
        heap1.add(56);

        heap2.add(23);
        heap2.add(12);
        heap2.add(4);
        heap2.add(19);
        heap2.add(15);
        heap2.add(34);
        heap2.add(66);

        System.out.println("Heap 1:" + heap1);
        System.out.println("Heap 2:" + heap2);
        System.out.println("Set the next value with 23!");
        heap1.setNextValue(23);
        System.out.println("After setNextValue  Heap 1:" + heap1);
        System.out.println("Remove 4 from Heap 1 is " + heap1.remove(4));
        System.out.println("After remove call Heap 1:" + heap1);
        System.out.println("Remove 34 from Heap 1 is " + heap1.remove(34));
        System.out.println("After remove call Heap 1:" + heap1);
        System.out.println("Remove 4'th largest element in Heap 1!");
        heap1.removingLargestI(4);
        System.out.println("After remove 4'th largest element Heap 1:" + heap1);
        System.out.println("Search 56 in Heap 1 = "  + heap1.search(56));
        System.out.println("Search 2 in Heap 1 = "  + heap1.search(2));
        System.out.println("Search 19 in Heap 1 = "  + heap1.search(19));
        System.out.println("Merge Heap 1 with Heap 2");
        heap1.merge(heap2);
        System.out.println("After merge operation Heap 1:" + heap1);

        System.out.println("PART 2 ");
        System.out.println("Binary Search Tree Object Created...");
        BinarySearchTree<Integer> bst1 = new BinarySearchTree<>();
        BinarySearchTree<Integer> bst2 = new BinarySearchTree<>();
        for(int i = 0 ; i < 75 ; i++){

            int randomNumber = (int) (Math.random() * (20 - 1) + 1);
            bst1.add(randomNumber);
        }
        System.out.println("Added some variables to BST 1...");
        System.out.println("Each line represents a bst node (heap)");
        System.out.println(bst1.toString());
        bst2.add(5);
        bst2.add(7);
        bst2.add(8);
        bst2.add(9);
        bst2.add(6);
        bst2.add(1);
        bst2.add(2);
        bst2.add(3);
        bst2.add(5);
        bst2.add(7);
        bst2.add(8);
        bst2.add(9);
        System.out.println("BST 2 after add some elements ");
        System.out.println(bst2.toString());
        System.out.println("Find 6 in BST = " + bst2.find(6));
        System.out.println("Find 3 in BST = " + bst2.find(3));
        System.out.println("Find 14 in BST = " + bst2.find(14));
        bst2.delete(5);
        bst2.delete(7);
        bst2.delete(8);
        System.out.println("Deleted Some Elements");
        System.out.println(bst2.toString());
        bst2.delete(9);
        bst2.delete(6);
        bst2.delete(1);
        System.out.println("Last Element In Node");
        System.out.println(bst2.toString());
        bst2.delete(2);
        System.out.println("Node Removed...");
        System.out.println(bst2.toString());






    }
}
