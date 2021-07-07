import java.util.LinkedList;
import java.util.Queue;

/**
 * @author Erdi Bayır
 * @since 26-05-2021
 * Trader Class Implementation.It extends User class and implements Comparable interface.
 */
public class Trader extends User implements Comparable{
    /**
     * Linked list of products of trader
     */
    private LinkedList<Product> products;

    /**
     * Trader 3 parameter constructor to create Trader object
     * @param id id of trader
     * @param name name of trader
     * @param password password of trader
     */
    public Trader(String id, String name, String password) {
        super(id, name, password);
    }

    /**
     * User 2 parameter constructor to create Trader object
     * @param name name of trader
     * @param password password of trader
     */
    public Trader(String name, String password) {
        super(name,password);
        products = new LinkedList<>();
    }

    /**
     * Return Trader Products List
     * @return Return Products
     */
    public LinkedList<Product> getProducts() {
        return products;
    }

    /**
     * Set Trader Products List
     * @param products new products object
     */
    public void setProducts(LinkedList<Product> products) {
        this.products = products;
    }

    /**
     * Add Product to product list of trader
     * @param newProduct new product object
     * @return Return true if add operations done successfully,otherwise false
     */
    public boolean addProduct(Product newProduct){
        return products.add(newProduct);
    }
    /**
     * Remove Product from product list of trader
     * @param newProduct remove product object
     * @return Return true if remove operations done successfully,otherwise false
     */
    public boolean removeProducts(Product newProduct){
        return products.remove(newProduct);
    }
    public boolean editProduct(Product editProduct,String category, String name, String description, String price, String discountPrice){
        if(products.contains(editProduct)){
            products.remove(editProduct);
            Product newProduct = new Product(editProduct.getOwnTrader(),editProduct.getId(),category,name,description,price,discountPrice);
            return true;
        }
        return false;
    }

    /**
     * Show List of Trader's products
     */
    public void listOfProducts(){
        System.out.println("List Of Product");
        for (int i = 0; i < products.size();i++){
            System.out.println(i + 1 + ".Product -> " + products.get(i).toString());
        }
    }

    /**
     * Show List of Customer orders that trader's own
     * @param customers customers list for show orders
     */
    public void list_customerOrders(LinkedList<Customer> customers){
        for (int i = 0 ; i < customers.size(); i++){
            Customer tempCustomer = customers.get(i);
            Queue<Product> customerOrder = tempCustomer.getOrders();
            if(customerOrder != null) {
                for (int j = 0; j < customerOrder.size(); j++){
                    Product tempProduct = customerOrder.poll();
                    if (tempProduct.getOwnTrader().getName().equals(getName())){
                        System.out.println("Customer -> " + tempCustomer.toString() + " Order-> " + tempProduct.toString());
                    }
                    customerOrder.add(tempProduct);
                }
            }
        }
    }

    /**
     * toString override method
     * @return Return Trader information as a string
     */
    @Override
    public String toString() {
        return getId() + ";" + getName() + ";" + getPassword();
    }

    /**
     * compareTo override method
     * @param o Comparable object for compare with Trader
     * @return Return true if compare is successfully otherwise 0
     */
    @Override
    public int compareTo(Object o) {
        if(toString().equals(o.toString()))
            return 1;
        return 0;
    }
}
