/**
 * @author Erdi Bayır
 * @since 12.05.2021
 * Driver function for test classes.s
 */
public class Driver {
    public static void main(String[] args) {
        long startTime = System.nanoTime();
        System.out.println();
        System.out.println("---------  Linked List Hash Map Test  ---------");
        HashMapList<Integer,String> newHll = new HashMapList<>();
        System.out.println("Hash Map Created....");
        newHll.put(5,"test1");
        newHll.put(3,"test2");
        newHll.put(15,"test3");
        newHll.put(12,"test4");
        newHll.put(2,"test5");
        newHll.put(277,"test6");
        newHll.put(53,"test7");
        newHll.put(232,"test7");
        newHll.put(1,"test7");
        newHll.put(65,"test7");
        newHll.put(1010,"test7");
        newHll.put(34,"test6");
        newHll.put(78,"test7");
        newHll.put(35888,"test7");
        System.out.println("Added some Entries...");
        System.out.println("Hash Map: " + newHll.toString());
        newHll.remove(2);
        System.out.println("Remove key 2....");
        System.out.println("Hash Map: " + newHll.toString());
        newHll.put(2,"test5");
        System.out.println("Key 2 added again...");
        System.out.println("Hash Map: " + newHll.toString());
        System.out.println("Test to remove non-existent");
        System.out.println("Remove key 25 : " + newHll.remove(25));
        System.out.println("Hash Map: " + newHll.toString());
        System.out.println("Some getter tests...");
        System.out.println("Value of key 12:" + newHll.get(12));
        System.out.println("Value of key 3:" + newHll.get(3));
        System.out.println("Value of key 27:" + newHll.get(277));
        System.out.println("Value of key 22:" + newHll.get(22));
        System.out.println("Is empty? : "  + newHll.isEmpty());

        long elapsedTime = System.nanoTime() - startTime;
        System.out.println("Total execution time : " + elapsedTime/1000000);

        startTime = System.nanoTime();
        System.out.println();
        System.out.println("---------  Tree Set Hash Map Test  ---------");
        HashMapTree<Integer,String> newHt = new HashMapTree<>();
        System.out.println("Tree hash Map Created....");
        newHt.put(5,"test1");
        newHt.put(3,"test2");
        newHt.put(15,"test3");
        newHt.put(12,"test4");
        newHt.put(2,"test5");
        newHt.put(277,"test6");
        newHt.put(53,"test7");
        newHt.put(232,"test7");
        newHt.put(1,"test7");
        newHt.put(65,"test7");
        newHt.put(1010,"test7");
        newHt.put(34,"test6");
        newHt.put(78,"test7");
        newHt.put(35888,"test7");
        System.out.println("Added some Entries...");
        System.out.println("Hash Map: " + newHt.toString());
        newHt.remove(2);
        System.out.println("Remove key 2....");
        System.out.println("Hash Map: " + newHt.toString());
        newHt.put(2,"test5");
        System.out.println("Key 2 added again...");
        System.out.println("Hash Map: " + newHt.toString());
        System.out.println("Test to remove non-existent");
        System.out.println("Remove key 25 : " + newHt.remove(25));
        System.out.println("Hash Map: " + newHt.toString());
        System.out.println("Some getter tests...");
        System.out.println("Value of key 12:" + newHt.get(12));
        System.out.println("Value of key 3:" + newHt.get(3));
        System.out.println("Value of key 27:" + newHt.get(277));
        System.out.println("Value of key 22:" + newHt.get(22));
        System.out.println("Is empty? : "  + newHt.isEmpty());

        elapsedTime = System.nanoTime() - startTime;
        System.out.println("Total execution time : " + elapsedTime/1000000);

        startTime = System.nanoTime();
        System.out.println();
        System.out.println("---------  Coalesced Hash Map Test  ---------");
        HashMapCoalesced<Integer,Integer> newHc = new HashMapCoalesced<Integer, Integer>();
        System.out.println("Coalesced  hash Map Created....");
        System.out.println("Some adding stages for Coalesced Hash Map:");
        newHc.printTable();
        newHc.put(3,3);
        newHc.put(12,12);
        newHc.printTable();
        newHc.put(13,13);
        newHc.printTable();
        newHc.put(25,25);
        newHc.put(23,23);
        newHc.printTable();
        newHc.put(51,51);
        newHc.put(42,42);
        newHc.printTable();
        System.out.println("Delete key 13:");
        newHc.remove(13);
        newHc.printTable();
        System.out.println("Delete key 3:");
        newHc.remove(3);
        newHc.printTable();
        System.out.println("Delete key 12:");
        newHc.remove(12);
        newHc.printTable();
        System.out.println("Delete key 3 again :" + newHc.remove(3));
        System.out.println("Adding some elements for rehash test...");
        newHc.put(12,12);
        newHc.put(21,21);
        newHc.put(12,12);
        newHc.put(123,123);
        newHc.put(143,143);
        newHc.put(2222,2222);
        newHc.put(11112,11112);
        newHc.put(23431,23431);
        newHc.printTable();

        elapsedTime = System.nanoTime() - startTime;
        System.out.println("Total execution time : " + elapsedTime/1000000);
        System.out.println();
        System.out.println("---------  MapIterator  Test  ---------");
        System.out.println("Iterator  Created at key 23 ....");
        HashMapCoalesced<Integer,String>.MapIterator<Integer> newIterator = newHc.iterator(23);
        System.out.println("Iterator Prev:" + newIterator.prev());
        System.out.println("Iterator Prev:" + newIterator.prev());
        System.out.println("Iterator Prev:" + newIterator.prev());
        System.out.println("Iterator has next ? :" + newIterator.hasNext());
        System.out.println("Iterator Prev:" + newIterator.prev());
        System.out.println("Iterator has next ? :" + newIterator.hasNext());
        System.out.println("Iterator Next:" + newIterator.next());
        System.out.println("Iterator  Created without parameter ....");
        newIterator = newHc.iterator();
        System.out.println("Iterator Next:" + newIterator.next());
        System.out.println("Iterator Next:" + newIterator.next());
        System.out.println("Iterator Next:" + newIterator.next());
        System.out.println("Iterator Next:" + newIterator.next());
        System.out.println("Iterator Next:" + newIterator.next());
        System.out.println("Iterator Next:" + newIterator.next());
        System.out.println("Iterator Next:" + newIterator.next());
        System.out.println("Iterator Prev:" + newIterator.prev());

    }
}

