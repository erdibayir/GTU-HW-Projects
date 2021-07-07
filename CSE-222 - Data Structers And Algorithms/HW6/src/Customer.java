import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Queue;

/**
 * @author Erdi Bayır
 * @since 26-05-2021
 * Customer Class Implementation.It extends User class.
 */
public class Customer extends User{
    /**
     * Orders object of Customer's own
     */
    private Queue<Product> orders;

    /**
     * User 2 parameter constructor to create Customer object
     * @param name name of customer
     * @param password password of customer
     */
    public Customer(String name,String password) {
        super(name,password);
        orders = new PriorityQueue<>();
    }

    /**
     * Customer 3 parameter constructor to create Customer object
     * @param id id of customer
     * @param name name of customer
     * @param password password of customer
     */
    Customer(String id,String name,String password){
        super(id,name,password);
        orders = new PriorityQueue<>();
    }

    /**
     * Return orders of Customer
     * @return Return orders
     */
    public Queue<Product> getOrders() {
        return orders;
    }

    /**
     * toString override method
     * @return Return Customer information as a string
     */
    @Override
    public String toString() {
        return getId() + ";" + getName() + ";" + getPassword();
    }

    /**
     * Set orders of Customer
     * @param orders new orders object
     */
    public void setOrders(Queue<Product> orders) {
        this.orders = orders;
    }

    /**
     * Customer can search a product with use product file
     * @param filepath file path of products
     * @param searchWord search word of Customer's entered
     * @return Return result of search
     */
    public ArrayList<Product> searchProduct(String filepath,String searchWord){
        ArrayList<Product> products = new ArrayList<>();
        String line = "";
        String splitBy = ";";
        int k = 0;
        try {
            BufferedReader br = new BufferedReader(new FileReader(filepath));
            String[] lines = line.split(splitBy);
            line = br.readLine();
            while ((line = br.readLine()) != null)   //returns a Boolean value
            {
                lines = line.split(splitBy);
                if(lines[2].contains(searchWord) || lines[6].contains(searchWord)){
                    Product newProduct = new Product(new Trader(lines[0],"null"),lines[1],lines[2],lines[3],lines[4],lines[5],lines[6]);
                    products.add(newProduct);
                }
            }
            br.close();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        products = searchProductsTrader(products);
        return products;
    }

    /**
     * Helper function for searchProduct.It determine trader of products
     * @param products Take products to determine their traders
     * @return Return result of search
     */
    private ArrayList<Product> searchProductsTrader(ArrayList<Product> products){
        String line = "";
        String splitBy = ";";
        int k = 0;
        try {
            BufferedReader br = new BufferedReader(new FileReader("src/traders.txt"));
            String[] lines = line.split(splitBy);
            line = br.readLine();
            while ((line = br.readLine()) != null)   //returns a Boolean value
            {
                lines = line.split(splitBy);
                for (int i = 0 ; i < products.size(); i++){
                    if (products.get(i).getOwnTrader().getName().equals(lines[1])){
                        Trader tempTrader = new Trader(lines[0],lines[1],lines[2]);
                        products.get(i).setOwnTrader(tempTrader);
                        break;
                    }
                }
            }
            br.close();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        return products;
    }

    /**
     * Customer can make order with this function
     * @param shop ShoppingStore object for make order
     * @param orderId Id of products which can be ordered
     * @return Return true if order is successfully done otherwise false
     */
    public boolean makeOrder(ShoppingStore shop, String orderId){
        for(int i = 0 ; i < shop.getTraders().size(); i ++){
            Trader tempTrader = shop.getTraders().get(i);
            for (int j = 0; j < tempTrader.getProducts().size();j++){
                if(tempTrader.getProducts().get(j).getId().equals(orderId)){
                    orders.offer(tempTrader.getProducts().get(j));
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * Show customer orders.
     */
    public void showOrders(){
        for (int i = 0 ; i < orders.size();i++){
            Product tempProduct = orders.poll();
            System.out.println(i + ".Order ->" + tempProduct.toString());
            orders.offer(tempProduct);
        }
    }

    /**
     * Bubble sort algorithm for sort products by their names with ascender order
     * @param products products object to be sorted
     */
    public void bubbleSortName(ArrayList<Product> products) {
        boolean sorted = false;
        Product temp;
        while (!sorted) {
            sorted = true;
            for (int i = 0; i < products.size() - 1; i++) {
                if (products.get(i).getName().compareTo(products.get(i+1).getName()) > 0) {
                    temp = products.get(i);
                    products.set(i,products.get(i+1));
                    products.set(i+1,temp);
                    sorted = false;
                }
            }
        }
    }

    /**
     * Selection sort algorithm for sort products by their price with ascender order
     * @param products products object to be sorted
     */
    public void selectionSortPrice(ArrayList<Product> products){
        int n = products.size();
        for (int fill = 0; fill < n-1 ; fill++) {
            int posMin = fill;
            for (int next = fill + 1; next < n; next++) {
                int nextInt = Integer.parseInt(products.get(next).getPrice());
                int nextposMin = Integer.parseInt(products.get(posMin).getPrice());

                if (nextInt < nextposMin) {
                    posMin = next;
                }
            }
            Product temp = products.get(fill);
            products.set(fill,products.get(posMin));
            products.set(posMin,temp);
        }
    }

    /**
     * Shell sort algorithm for sort products by their discount price with ascender order
     * @param products products object to be sorted
     */
    public void shellSortDiscount(ArrayList<Product> products){
        int gap = products.size() / 2;
        while (gap > 0) {
            for (int nextPos = gap; nextPos < products.size(); nextPos++) {
                insert(products, nextPos, gap);
            }
            if (gap == 2) {
                gap = 1;
            } else {
                gap = (int) (gap / 2.2);
            }
        }
    }

    /**
     * Helper function for shell sort
     * @param products products object to be sorted
     * @param nextPos next position of sorting element
     * @param gap gap of shell sort
     */
    private void insert(ArrayList<Product> products,int nextPos,int gap){
        Product nextVal = products.get(nextPos);
        while ((nextPos > gap - 1) && (Integer.parseInt(nextVal.getDiscountPrice()) < Integer.parseInt(products.get(nextPos - gap).getDiscountPrice()))){
            products.set(nextPos,products.get(nextPos - gap));
            nextPos -= gap;
        }
        products.set(nextPos,nextVal);
    }

    /**
     * Filter search result by price upper and lower bound
     * @param products products object to be sorted
     * @param upperBound upper bound value
     * @param lowerBound lower bound value
     * @return return filtered products
     */
    public ArrayList<Product> filterPriceBound(ArrayList<Product> products, int upperBound, int lowerBound){
        ArrayList<Product> filterResuls = new ArrayList<>();
        for (int i = 0 ; i < products.size(); i++){
            int price = Integer.parseInt(products.get(i).getPrice());
            if(price >= lowerBound && price <= upperBound)
                filterResuls.add(products.get(i));
        }
        return filterResuls;
    }

    /**
     * Display all the products of selected trader
     * @param shop Shop object to determine trader
     * @param id Id of selected trader
     */
    public void displayTraderProducts(ShoppingStore shop,String id){
        for (int i = 0; i < shop.getTraders().size();i++){
            if(shop.getTraders().get(i).getId().compareTo(id) == 0){
                shop.getTraders().get(i).listOfProducts();
                break;
            }
        }
    }
}